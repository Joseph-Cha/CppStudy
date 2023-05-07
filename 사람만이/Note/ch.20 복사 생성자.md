# 20강. 복사 생성자

## C++ 스타일의 초기화

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.20/1.png)

## 복사 생성자(Copy Constructor)

- 객체의 복사본이 만들어질 때 호출
    
    ```cpp
    Complex c2 = c1;
    Complex c3(c1);
    ```
    
    - 위와 같이 새로운 객체를 초기화할 때 기존에 있던 객체를 복사할 때 호출되는 생성자이다.
    - 기존에 Complex에서 정의한 생성자가 호출되지 않는다는 것도 중요 포인트
- Complex의 복사 생성자 프로토 타입
    
    ```cpp
    Complex(const Complex& obj); // 객체의 메모리 크기가 크기 때문에 call by reference로 전달
    ```
    
    - 자신의 클래스형과 같은 자료형의 const 레퍼런스를 매개변수로 갖는 생성자
        - 오직 하나만 선언
- 객체의 복사본이 만들어질 때 필요한 일을 정확하게 지정하기 위해 구현 필요

## default 복사 생성자

- 프로그래머가 별도로 복사 생성자를 정의하지 않으면 자동으로 제공됨(컴파일러에 의해 제공됨)
    - 멤버 대 멤버의 복사를 진행
        - shallow copy 수행
    - 일반적인 경우 default 복사 생성자로 충분
- 포인터 멤버 변수를 갖는 클래스의 경우 복사 생성자의 추가 정의가 필요할 수 있음
    - deep copy 수행
    - 포인터 멤버 변수를 갖게 되면 복사로 객체를 생성할 때 의존성이 걸리기 때문에 deep copy가 필요하다.
        
        ![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.20/2.png)
        
        - c2 객체의 list가 c1에서 가리키고 있는 Complex 배열을 가리키고 있어 의존성이 걸리게 된다.
        - 따라서 아래와 같이 deep copy가 될 수 있도록 해야 한다.
        
        ![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.20/3.png)
        

## 객체 복사시 문제점

- 멤버 변수에 포인터를 포함하는 경우 복사본과 원본이 같은 곳을 가리키게 됨
    - → 복사본 내용 수정 시 원본에도 영향
    - → 소멸자 호출 시 문제
        - 포인터 변수가 가리키고 있는 메모리를 해제 했을 경우 복사 본에서 들고 있는 포인터 변수에도 영향
- 위의 문제가 발생하는 경우(객체 복사가 발생하는 경우)
    - 객체 생성과 동시에 기존 객체로 초기화
    - 값의 복사에 의해 매개 변수로 객체 전달 시
    - 함수로부터 값의 복사에 의해 객체 반환시
- 해결책
    - deep copy를 수행하는 복사 생성자 제공

## 복사 생성자가 호출되는 경우는..

- 객체 생성과 동시에 같은 클래스형의 객체로 초기화 되는 경우
    - 초기화(initialization) → 복사 생성자 호출 O
        - 객체 선언문에서 초기값 할당시
            
            ```cpp
            Complex c2 = c1;
            ```
            
        - 함수의 매개변수로 call by value로 객체를 전달 시
            
            ```cpp
            fn1(c1); // void f1(Compex);
            ```
            
        - 함수의 반환값으로 return by value로 객체 반환 시
            
            ```cpp
            c3 = fn2(); // Complex fn2(void);
            ```
            
    - 대입(assignment) → 복사 생성자 호출 X
        - x = y;
            - 이미 x라는 객체가 생성되이 있는 상태에서 복사가 일어나는 경우이다.
            - 생성자가 호출되는 시점이 아니기 때문에 복사 생성자가 호출되지 않는다.
            - 이런 경우 포인터 멤버를 갖는 경우 얕은 복사가 일어날 수 있기 때문에 문제가 발생할 수 있다.
            - 이럴 땐 대입 연산자 오버로딩이 필요하다.

## 예제

```cpp
#pragma once

class Complex {
public:
    Complex(double real = 0, double image = 0);
    Complex(const Complex& c);
    ~Complex();

    void SetComlpex(double real, double image);
    void ShowComplex(void) const;

    double GetReal(void) const { return real; }
    double GetImage(void) const {return image; }

private:
    double real;
    double image;
};
```

```cpp
#include "Complex.h"
#include <iostream>

Complex::Complex(double r, double i) : real(r), image(i)
{
    std::cout << "Complex 객체 생성" << std::endl;
}

Complex::Complex(const Complex& c)
{
    std::cout << "Complex 객체 복사 생성" << std::endl;
}

Complex::~Complex()
{
    std::cout << "Complex 객체 소멸: ";
    ShowComplex();
    std::cout << "\n";
}

void Complex::SetComlpex(double real, double image)
{
    this->real = real;
    this->image = image; 
}
```

## 적용 예제 1)

```cpp
#include <iostream>
#include "Complex.h"

int main()
{
    Complex c1(1, 2);
    std::cout << "[Step1: 생성과 동시에 초기화]\n" << std::endl;

    Complex c2 = c1;
    Complex c3 =(c1);

    c2.ShowComplex();
    std::cout << std::endl;

    c3.ShowComplex();
    std::cout << std:: endl;

    std::cout << "\nEnd" << std::endl;

    return 0;
}

/*
Complex 객체 생성 -> c1 객체 생성
[Step1: 생성과 동시에 초기화]

Complex 객체 복사 생성 -> c2 복사 생성
Complex 객체 복사 생성 -> c3 복사 생성
1+2i
1+2i

End

Complex 객체 소멸: 1+2i -> c1 소멸
Complex 객체 소멸: 1+2i -> c2 소멸
Complex 객체 소멸: 1+2i -> c3 소멸
*/ 
```

## 적용 예제 2)

```cpp
#include <iostream>
#include "Complex.h"

int main()
{
    Complex c1(1, 2);
    std::cout << "[Step2: 함수 호출]\n" << std::endl;

    Fn1(c1);
    std::cout << std::endl;

    std::cout << "\nEnd" << std::endl;

    return 0;
}

void Fn1(Complex c)
{
    c.ShowComplex();
    std::cout << std::endl;
}

/*
Complex 객체 생성 -> c1 객체 생성
[Step2: 함수 호출]

Complex 객체 복사 생성 -> 함수 호출 시 c 객체 생성
1+2i
Complex 객체 소멸: 1+2i -> c 객체 소멸

End

Complex 객체 소멸: 1+2i -> c1 객체 소멸
*/
```

## 적용 예제 3)

```cpp
#include <iostream>
#include "Complex.h"

int main()
{
    Complex c1(1, 2);
    std::cout << "[Step3: 함수 반환]\n" << std::endl;
    
    Complex res;
    res = Fn2(c1);

    std::cout << "\nEnd" << std::endl;

    return 0;
}

Complex Fn2(Complex& c)
{
    std::cout << ">> 함수에서 return 전" << std::endl;
    return c;
}

/*
Complex 객체 생성
[Step3: 함수 반환]

Complex 객체 생성
>> 함수에서 return 전
Complex 객체 복사 생성
Complex 객체 소멸: 1+2i

End
Complex 객체 소멸: 1+2i
Complex 객체 소멸: 1+2i
*/
```