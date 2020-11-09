# 9주차 과제
  
  아래 Fig. 1과 같이 주어진 코드에서 RSUB이 실행된 이후 다음 작업을 수행하도록 다음 코드를 완성하시오.
  단 각 step에 해당하는 작업은 하나의 instruction으로 수행한다.
  제출 항목: SIC / XE Assembly code (.asm 파일).  
  
#### ①	A register에 저장된 값을 S register로 이동.  
#### ②	S register에 저장된 값을 4 bit left shift  
#### ③	S register의 값과 A register 값의 합을 A register에 저장.  

```
  
TEST5    START   0
FIRST    J       BEGIN
FIVE     WORD    5
XXX      RESW    1
BEGIN    LDA     ZERO
         LDX     ZERO
LOOP     JSUB    GETC
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
```
