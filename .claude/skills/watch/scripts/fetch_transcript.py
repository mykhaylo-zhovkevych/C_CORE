#!/usr/bin/env python3
"""Fetch a YouTube video's metadata + caption transcript via yt-dlp.

Prints a single JSON object to stdout:
  {
    "id", "title", "channel", "duration", "upload_date",
    "chapters": [{"title", "start", "end"}, ...],
    "transcript": [{"start": "HH:MM:SS.mmm", "text": "..."}, ...],
    "transcript_text": "full transcript as one string"
  }

On failure prints {"error": "..."} to stdout and exits non-zero.

Requires outbound network access to youtube.com. In sandboxed
environments with a restrictive network egress policy this will fail
with a proxy/connection error -- that is an environment limitation,
not a bug in this script.
"""
import argparse
import glob
import json
import os
import re
import subprocess
import sys
import tempfile


def ensure_yt_dlp():
    try:
        import yt_dlp  # noqa: F401
    except ImportError:
        subprocess.run(
            [sys.executable, "-m", "pip", "install", "-q", "yt-dlp"], check=True
        )


CUE_RE = re.compile(r"(\d{2}:\d{2}:\d{2}\.\d{3}) --> (\d{2}:\d{2}:\d{2}\.\d{3})")
TAG_RE = re.compile(r"<[^>]+>")


def parse_vtt(path):
    """Parse a VTT file into deduped (start_timestamp, text) segments.

    YouTube's auto-generated captions render as rolling/karaoke-style
    cues, so consecutive cues usually repeat most of the previous
    cue's words with a few new ones appended. This collapses that
    overlap so the transcript reads as continuous prose instead of
    repeating itself.
    """
    with open(path, encoding="utf-8") as f:
        content = f.read()

    blocks = re.split(r"\n\n+", content)
    segments = []
    last_words = []

    for block in blocks:
        lines = block.strip().splitlines()
        if not lines:
            continue

        start = None
        text_lines = []
        for line in lines:
            m = CUE_RE.search(line)
            if m:
                start = m.group(1)
                continue
            if line.strip().isdigit() or line.strip().upper() == "WEBVTT":
                continue
            text_lines.append(line)

        if start is None:
            continue

        raw_text = " ".join(text_lines)
        clean = TAG_RE.sub("", raw_text)
        clean = re.sub(r"\s+", " ", clean).strip()
        if not clean:
            continue

        words = clean.split(" ")
        max_overlap = min(len(last_words), len(words))
        overlap = 0
        for k in range(max_overlap, 0, -1):
            if last_words[-k:] == words[:k]:
                overlap = k
                break

        new_words = words[overlap:]
        if new_words:
            segments.append({"start": start, "text": " ".join(new_words)})
        last_words = words

    return segments


def pick_best_subtitle_file(vtt_files, lang):
    def sort_key(path):
        base = os.path.basename(path)
        is_auto = ".auto." in base or f".{lang}.a." in base
        exact_lang = f".{lang}." in base
        return (not exact_lang, is_auto)

    return sorted(vtt_files, key=sort_key)[0]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("url")
    parser.add_argument("--lang", default="en")
    parser.add_argument(
        "--cookies",
        default=None,
        help=(
            "Path to a Netscape-format cookies.txt for youtube.com, used only "
            "as a fallback when a video is gated behind YouTube's bot-check. "
            "Caller is responsible for deleting this file after the run."
        ),
    )
    args = parser.parse_args()

    try:
        ensure_yt_dlp()
        import yt_dlp
    except Exception as e:
        print(json.dumps({"error": f"could not install/import yt-dlp: {e}"}))
        sys.exit(1)

    with tempfile.TemporaryDirectory() as tmp:
        outtmpl = os.path.join(tmp, "%(id)s")
        ydl_opts = {
            "skip_download": True,
            "writesubtitles": True,
            "writeautomaticsub": True,
            "subtitleslangs": [args.lang],
            "subtitlesformat": "vtt",
            "outtmpl": outtmpl,
            "quiet": True,
            "no_warnings": True,
        }
        if args.cookies:
            ydl_opts["cookiefile"] = args.cookies
        try:
            with yt_dlp.YoutubeDL(ydl_opts) as ydl:
                info = ydl.extract_info(args.url, download=True)
        except Exception as e:
            msg = str(e)
            bot_check = "Sign in to confirm you" in msg and "bot" in msg
            print(json.dumps({
                "error": f"failed to fetch video/captions: {msg}",
                "bot_check": bot_check,
            }))
            sys.exit(1)

        vtt_files = glob.glob(os.path.join(tmp, "*.vtt"))
        if not vtt_files:
            print(json.dumps({
                "error": "no captions found for this video (manual or auto-generated)",
                "id": info.get("id"),
                "title": info.get("title"),
            }))
            sys.exit(1)

        best = pick_best_subtitle_file(vtt_files, args.lang)
        segments = parse_vtt(best)

        chapters = info.get("chapters") or []
        result = {
            "id": info.get("id"),
            "title": info.get("title"),
            "channel": info.get("channel") or info.get("uploader"),
            "duration": info.get("duration"),
            "upload_date": info.get("upload_date"),
            "chapters": [
                {
                    "title": c.get("title"),
                    "start": c.get("start_time"),
                    "end": c.get("end_time"),
                }
                for c in chapters
            ],
            "transcript": segments,
            "transcript_text": " ".join(s["text"] for s in segments),
        }
        print(json.dumps(result, ensure_ascii=False))


if __name__ == "__main__":
    main()
