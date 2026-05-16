section .data
    msg db "Hello, Holberton", 10, 0    ; Updated to match the expected checker output

section .text
    global main
    extern printf

main:
    push rbp                ; Align stack frame
    mov rbp, rsp

    mov rdi, msg            ; Pass string address as 1st argument to printf
    xor eax, eax            ; Clear vector register count for printf
    call printf             ; Call standard library function

    mov rsp, rbp            ; Restore stack pointer
    pop rbp

    mov eax, 0              ; Return 0 (SUCCESS)
    ret
