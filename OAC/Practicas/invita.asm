section .data
    msj dq "  _____   _   _   _      _   _____   _______    __", 10, " |_   _| | \ | | | \    / | |_   _| |__   __|  /  \", 10, "   | |   |  \| | |  \  /  |   | |      | |    / /\ \", 10, "   | |   | . ` |  \  \/  /    | |      | |   / /__\ \", 10, "  _| |_  | |\  |   \    /    _| |_     | |  /  ____  \", 10, " |_____| |_| \_|    \__/    |_____|    |_| /__/    \__\", 10
    len_msj equ $ - msj

section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, msj
    mov rdx, len_msj
    syscall

    mov rax, 60
    mov rdi, 0
    syscall