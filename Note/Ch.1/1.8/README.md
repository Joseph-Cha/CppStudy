### 1.8 연산자와 첫 만남

``` C++
#include <iostream>
using namespace std;

int main()
{
    int x = 2; // x is a variable, 2 is a literal.
    // = : Assignment

    cout << 1 + 2 << endl;
    // 1, 2 : 리터럴, 피연산자(Operand)
    // 1 + 2 : 표현식
    // + : 연산자

    cout << "My Home" << endl;
    // My Home : 리터럴

    // 연산자 종류
    // +, -, *, /

    // 단항 연산자 
    cout << -x << endl; // -가 단항 연산자

    // 이항 연산자
    cout << 1 + 2 << endl; // 피연산자가 2개

    // 삼항 연산자
    int y = ( x > 0) ? 1 : 2;
    // 조건 ? 참일 때 실행 : 거짓일 때 실행
}
```