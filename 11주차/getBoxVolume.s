        .global getBoxVolume
        .text

getBoxVolume:
        mov %rdi, %rax
        imul %rsi, %rax
        imul %rdx, %rax
        ret
