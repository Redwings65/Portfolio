    .file "divd.S"
value:
    .long 2
    .text
.global divd
divd:
    mov     r15, r15    ;this was here and i hate life
    mov     r15, r10
    mov     r14, r11
    inv     r15
    inc     r15
    inv     r14
    inc     r14
Loop:
    inc     r13         ;increment register 13 by 1
    sub     r14, r15    ;i added this for testing subtract 5 from 25
    jn      Loop        ;jump back to mainloop while negative
    add     r14, r15    ;this gives me -2 when i do 27 in 5
    sub     r14, r15
    dec     r15
    jn      Off         ;sees if the number i am calculating is going to go in evenly or odd

    mov     r10, r15
    mov     r11, r14    ; basically just started over
    inv     r15
    inc     r15
    inv     r14
    inc     r14

Again:
    inc     r12         ;increment register 12 by 1
    sub     r14, r15    ;i added this for testing subtract 5 from 25
    jn      Again       ;jump back to mainloop while negative
    add     r14, r15
    clr     r11
Zero:
    inc     r11         ;keeps track of remainder
    inc     r15
    jnz     Zero

    dec     r12
    mov     r11, r14
    mov     r12, r15    ;12 holds the answer


    ret


Off:                    ;goes here when it is suppose to go in evenly
    clr     r13
    mov     r10, r15
    mov     r11, r14
opps:
    inc     r13         ;increment register 13 by 1
    sub     r14, r15    ;i added this for testing subtract 5 from 25
    jnz     opps        ;jump back to mainloop while negative

    mov     r13, r15
    clr     r14

ret
