TEST5    START   0
FIRST    J       BEGIN
FIVE     WORD    5
XXX      RESW    1
BEGIN    LDA     ZERO
         LDX     ZERO
LOOP     JSUB    GETC
         RMO     A,S
         SHIFTL  S,4
         ADDR    S,A
         J       FINISH
GETC     STX     TEMP
         LDX     INCNT
         LDA     INCNT
         ADD     #1
         STA     INCNT
         LDCH    INDEV,X
         COMP    EOF
         JEQ     RETURN
         COMP    48
         JLT     GETC
         SUB     48
         COMP    #10
         JLT     RETURN
         SUB     #7
RETURN   LDX     TEMP
         RSUB
ZERO     WORD    0
EOF      WORD    63
TEMP     RESW    1
INCNT    WORD    0
EXADDR   RESB    12
INDEV    BYTE    C'0010030C1006'
         BYTE    C'000005FFFFFF?'
FINISH   END     FIRST
