section .data
    msg db "Hello, ALX", 10, 0    ; 10 is the ASCII newline character (\n), 0 is the null terminator

section .text
    global main
    extern printf

main:
    push rbp                ; Align stack frame
    mov rbp, rsp

    mov rdi, msg            ; Pass string address as 1st argument to printf
    xor eax, eax            ; printf is a variadic function; 0 indicates no vector registers used
    call printf             ; Call the standard C library function

    mov rsp, rbp            ; Restore stack pointer
    pop rbp

    mov eax, 0              ; Return 0 from main
    ret
