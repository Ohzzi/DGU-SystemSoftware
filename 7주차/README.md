# 7주차 과제

SIC/XE Assembly code를 assemble 할 때 출력되는 OBJFILE 을 읽어서 각 줄에서 CODES에 해당하는 instructions을 분리한다.
CODES 에 해당하는 내용에서 16진수를 10진수로 변환하고,
문자코드로 표현된 CODES 와 코드 변환된 InCODES (각 문자가 변환된 10진법 표기 값)을 출력하는 C 프로그램을 작성하시오.
단, 입력파일을 command line argument로 입력 받고 argument가 주어지지 않았을 때는 예외 처리를 하도록 한다.

---
#### 예시  
```
CODES = ’0010030C1006’  -> 0, 0, 1, 0, 0, 3, 0, 12, 1, 0, 0, 6
CODES = ’000005ABCDF’  -> 0, 0, 0, 0, 0, 5, 10, 11, 12, 13, 15
```
---
#### OPCODE  
TAG, PROGNAME, ADDR, SIZE  
( Col.1:  H, Col.2-7: program name, Col.8-13 : ADDR, Col.14-19: SIZE) 

TAG, ADDR, LENGTH, CODES
( Col.1:  T, Col.2-7: ADDR, Col.8-9 : LENGTH, Col.10-60: CODES) 

TAG, ADDR, OTHERS
( Col.1:  M 혹은 E, Col.2-7: ADDR, Col.8-9 : LENGTH, Col.10-60: OTHERS) 
