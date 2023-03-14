### 1.6 키워드와 식별자, 이름 짓기

``` C++

#include <iostream>

using namespace std;

// main도 예약어 같은 느낌
// void main()
// {

// }
void MyFuction()
{

}

// 함수명 : 동사 + 명사
// 함수명 시작이 소문자 또는 대문자로 사용
// 함수명이 너무 길어질 것 같으면 함수명을 짧게 짓고 주석을 다는게 좋음


void getNumber()
{

}

void addNumber()
{

}

class MyClass
{
    public :
        int m_variable; // 클래스의 멤버 변수일 때 m_도 사용함
};


int main()
{
    // int 3 : 변수명 함수명 모두 숫자로 시작 x
    // int ->  : 이런 함수 포인팅도 안됨
    int num_apples; // _를 통해 단어를 구분
    int nApples; // 이런 경우도 있음
    int VALUE; // 대문자는 잘 안씀 -> 대문자는 메크로에 많이 사용
    int _apples; // low level 개발자 분들이 종종 사용함

}
```