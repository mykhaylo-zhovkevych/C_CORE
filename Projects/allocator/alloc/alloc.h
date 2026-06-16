/* alloc.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;
typedef void heap;
typedef int32 word;

#define packed __attribute__((__packed__))
#define unused __attribute__((__unused__))

#define $1 (int8 *)
#define $2 (line16)
#define $4 (int32)
#define $8 (int64)
#define $16 (int128)
#define $c (char *)
#define $i (int)
#define $v (void *)
#define $h (header *)

struct packed s_header {
    word w:30;
    bool alloced:1;
    bool unused reserved:1;
};
typedef struct packed s_header header;

int main(int,char**);