---
name: watch
description: Fetches a YouTube video's caption transcript and produces a summary at one of three depth levels (1video/2video/3video) — each level trades more time/tokens for deeper, better-reasoned coverage. Use when the user gives a YouTube URL and wants it summarized, reviewed, or "watched" without actually watching it, or invokes /watch.
---

# Watch

Summarizes a YouTube video from its caption track, at a depth the caller picks.

## Usage

```
/watch <youtube-url> [1video|2video|3video]
```

If the depth argument is omitted, default to `1video`.

## Step 1 — Fetch transcript + metadata

Run the bundled script, which uses `yt-dlp` to pull caption tracks (manual
captions preferred, falls back to auto-generated) and video metadata,
without downloading the video/audio itself:

```bash
python3 .claude/skills/watch/scripts/fetch_transcript.py "<youtube-url>"
```

The script installs `yt-dlp` on first use if it isn't already present. It
prints one JSON object to stdout with `title`, `channel`, `duration`,
`chapters` (if the uploader defined any), `transcript` (deduped,
timestamped caption segments), and `transcript_text` (the full transcript
as one string).

Redirect the output to a temp file (e.g. `mktemp`, or your scratchpad
directory if you have one) rather than reading it inline if the transcript
is long, then read/chunk it from there.

**Failure modes to handle explicitly, don't retry blindly:**
- `EGRESS_BLOCKED` / proxy / connection errors → this environment's network
  policy blocks YouTube. Tell the user plainly that this environment can't
  reach YouTube and stop; this is not fixable by retrying or by trying
  alternate domains/mirrors.
- `"no captions found"` → the video has no manual or auto-generated
  captions in the requested language. Tell the user; don't attempt
  audio-based transcription (out of scope for this skill).

## Step 2 — Summarize at the requested depth

### `1video` — Quick pass (fastest, shallowest)

Read `transcript_text` once, straight through. Produce:

- **TL;DR** — 2-3 sentences
- **Key points** — 5-8 bullets
- **Topic tags**

One reasoning pass. No chunking, no subagents. Optimize for speed.

### `2video` — Structured pass (moderate)

1. Segment the transcript using `chapters` if the video has them;
   otherwise split `transcript` into ~6-8 roughly equal time-based
   segments.
2. For each segment, write a short paragraph summary with its timestamp
   range and 1-2 notable direct quotes.
3. Do a second pass: re-read your own draft summary against the
   transcript once more, and tighten/correct anything you got wrong or
   missed before presenting it.

Output: executive summary, a chapter-by-chapter table (timestamp →
summary), key quotes, and actionable takeaways.

### `3video` — Deep pass (slowest, most thorough)

1. Chunk `transcript` into segments of roughly 1500-2500 words each,
   respecting chapter boundaries where they exist.
2. Produce a detailed sub-summary per chunk: main claims, evidence or
   examples given, notable quotes with exact timestamps, and any open
   questions or gaps.
   - If there are more than ~4 chunks, consider dispatching one
     background `Agent` (general-purpose) per chunk to analyze it in
     parallel and report back a structured summary, then synthesize the
     results yourself — this buys deeper coverage on long videos at the
     cost of more time/tokens. For shorter videos, just work through the
     chunks yourself sequentially; spinning up agents for a 10-minute
     video is overkill.
3. Synthesize all chunk summaries into one report:
   - **TL;DR**
   - Full segment-by-segment breakdown with timestamps and quotes
   - Core arguments and the evidence given for them
   - Critical evaluation — assumptions, unsupported claims, possible
     bias, counterpoints worth raising
   - Actionable takeaways / next steps
   - Glossary of any jargon or niche terms used

Explicitly reason across the whole transcript before finalizing (e.g.
check whether something claimed early is contradicted or reinforced
later) rather than just concatenating chunk summaries.

## Notes

- This skill only reads publicly available caption/subtitle tracks and
  metadata — it never downloads video or audio.
- Auto-generated captions can contain transcription errors; flag
  uncertain wording when it materially affects the summary (e.g. a
  number, name, or claim that seems off).
- Requires outbound network access to `youtube.com`. Some sandboxed or
  remote Claude Code environments block this by network policy — if so,
  report that plainly rather than trying to route around it.
