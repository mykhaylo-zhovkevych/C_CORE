;;;
;;; Space Invaders-ish game in 510 bytes of qemu bootable real mode x86 asm
;;;

;; NOTE: Assuming direction flag is clear, SP initialized to 6EF0h, BP = 0

use16           
bits 16
org 07C00h		; Set bootsector to be at memory location hex 7C00h (UNCOMMENT IF USING AS BOOTSECTOR)
;org 8000h		; Set memory offsets to start here


;; DEFINED VARIABLES AFTER SCREEN MEMORY - 320*200 = 64000 = FA00h
sprites: equ 0FA00h
alien1 equ 0FA00h
alien2 equ 0FA00h
ship equ 0FA08h
barrierArr equ 0F20h
alienArr equ 0FA20h ; 2 words (1dblword) -bites/aliens
playerX equ 0FA24h
shotsArr equ 0FA25h ; 4 X/Y shot values 8 bytes
alienY equ 0FA2Ch
alienX equ 0FA2Eh
num_aliens equ 0FA2Fh ; # of aliens still alive
direction equ 0FA30h ; # pixels that aliens move in X direction 
move_timer equ 0FA31h ; 2 bytes (use BP) - number of game loops (or timer ticks) to wait before moving aliens again 
change_alien equ 0FA33h; ; Use alternate sprite yes/no


;; CONSTANTS ================
SCREEN_WIDTH equ 320
SCREEN_HEIGHT equ 200
VIDEO_MEMORY equ 0A000h
TIMER equ 046Ch ; # of timer ticks since midnight
BARRIERX equ 22  
BARRIERY equ 85
PLAYERY equ 93
SPRITEH equ 4
SPRITEW equ 8 ; WIDTH in bits/data pixels
SPRITEWP equ 16 ; Width in screen pixels


;Colors
ALIEN_COLOR equ 02h
PLAYER_COLOR equ 07h
BARRIER_COLOR equ 27h
PLAYER_SHOT_COLOR equ 0Bh;
ALIEN_SHOT_COLOR equ 0Eh;

mov ax, 0013h	; Set video mode 13h (320x200 256 color)
int 10h

push VIDEO_MEMORY
pop es
;; GAME LOOP ==============
game_loop:
    xor ax, ax ; Clear screen to black first
    xor di, di
    mov cx, SCREEN_WIDTH * SCREEN_HEIGHT
    rep stosb ;  mov[ES:DI], al cx # of times

;; Draw aliens
;; Draw barrirers
;; Draw player ship
;; Draw if shot hit anything
    ;; Hit player
    ;; Hit barrier
    ;; Hit alien
;; Draw shots
;; Create aliens shots
;; Move aliens
;; Get player input 

    delay_timer:
        mov ax, [TIMER]
        int ax
        .wait:
            cmp [TIMER], ax
            je .wait
jmp game_loop
;; End GAME LOOP ==============

cli
hlt

;; Draw sprite to the screen
draw_sprite:
    ret

;; Get x/y screen posituion in DI
get_screen_position:
    ret

;; CODE SEGMENT DATA ================
sprite_bitmaps:
    db 10011001b; Alien 1 bitmap
    db 01011010b
    db 00111100b
    db 01000010b

    db 00011000b; Alien 2 bitmap
    db 01011010b
    db 10111101b
    db 00100100b

    db 00011000b; Player ship bitmap
    db 00111100b
    db 10111101b
    db 01100110b

    db 00111100b; ; Barrier bitmap
    db 01111110b
    db 11100111b
    db 11100111b

;; Boot signature
times 510-($-$$) db 0
dw 0AA55h




