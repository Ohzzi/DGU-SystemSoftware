        .global doubleWeight
        .text

doubleWeight:
        mov  %rdi, %rax
        imul $2, %rax
        ret
