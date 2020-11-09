# 10주차 과제

아래 doubleWeight에 해당하는 X86-64 Assembly code를 작성하고 main함수에서 호출하시오.  
doubleWeight에 해당하는 parameter는 자신의 몸무게를 argument로 제공한다.  
단, 모든 X86-64 assembly code에 해당하는 함수의 원형은 주어진 형식을 지킨다.  

#### doubleWeight(int weight): 자신의 몸무게를 입력 받고 몸무게의 두배를 반환.

```
#include <stdio.h>

int doubleWeight(int weight);

int main() {
    printf(“double weight: %d\n",  doubleWeight(69));
    return 0;
}
```
