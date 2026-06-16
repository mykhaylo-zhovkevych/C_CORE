;64-bit machine code
bits 64
global memspace
%define Heapsize (1024*1024*1024/4)

Section .data alloc noexec write progbits
    memspace:
        dq _memspace

;custom section called ".heap"
Section .heap alloc noexec write nobits
    _memspace:
        heapsize equ Heapsize
        ;reserve by 4 which is 1gb
        resd heapsize

Section .note.GNU-stack noalloc
