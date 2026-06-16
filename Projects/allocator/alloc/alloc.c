/* alloc.c */
#include "alloc.h"

extern heap *memspace;

void *mkalloc(word words, header *hdr) {
    void *ret;

    hdr->w = words;
    hdr->allocated = true;
    ret = ($v hdr) + 4;

    return ret;
}

void *alloc(int32 bytes) {
    word words;

    header *hdr;
    void *mem;
    void *ret;

    words = (!(bytes % 4)) ? bytes/4 : (bytes/4) + 1;

    mem = $v memspace;
    hdr = $h mem;

    //mkalloc(words, hdr);

    if (hdr->w == 0) {
        if (words > Maxwords) {
            reterr(ErrNoMem);
        }

        ret = mkalloc(words, hdr);

        if (ret == NULL) {
            reterr(ErrNoMem);
        }

        return ret;
    }

    printf("bla\n");
    exit(0);
}

int main(int argc, char *argv[]) {

    alloc(7);

    return 0;
}