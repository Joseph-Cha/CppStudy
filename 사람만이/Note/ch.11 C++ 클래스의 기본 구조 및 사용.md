# 11강. C++ 클래스의 기본 구조 및 사용

## 기본 클래스의 구조

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.11/1.png)

- SimpleData::SetData(int n)에서 ::을 붙이는 이유는 SetData라는 함수가 SimpleData 클래스에서 정의된 함수라는 사실을 식별하기 위함이다.
- 다른 클래스에서도 동일하게 SetData가 있을 수도 있기 때문에 이를 식별하기 위한 연산자이다.
- 더불어 SimpleData에서 data라는 변수에 바로 접근을 하고 있는데 이게 가능한 이유가 SetData라는 함수는 SimpleData라는 클래스 안에 존재하는 함수이기 때문에 SimpleData의 멤버 변수의 값을 곧바로 접근할 수 있는 것이다.

## 변수의 유효범위와 접근 지정자

- 변수의 유효범위(Scope Rule)
    - 정의된 변수가 프로그램 내에서 참조 가능한 범위를 가르킴
- 접근 지정자에 의해 기본 유효범위가 바뀜
    - private
        - 전용 영역으로 선언
        - class의 기본영역
    - protected
    - public
        - 공용 영역으로 선언
        - 외부 클래스에서도 자유롭게 접근이 가능

## 멤버 필드

- 객체의 특징과 속성을 저장
    - [static] <자료형> <식별자>;
    - instance 멤버 필드
        - 각 객체 생성 시 별도의 메모리 할당
            - 멤버 변수의 경우 각 객체마다 고유의 속성 값 저장 가능
            - 멤버 상수
                - 기본적으로 클래스 정의 시 멤버 필드 선언부에 초기값 지정 불가
                - 초기화 리스트를 통해 상수값 부여
    - static 멤버 필드
        - 프로그램 시작시 메모리 할당
        - 추후 자세히 다룰 때까지는 사용하지 않음

## 멤버 필드의 선언 예

```cpp
class FruitSeller {
	public:
		int numOfApple;
		int money;
}
```

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.11/2.png)

- FruitSeller라는 객체를 만들게 되면(new 키워드 없이) stack 영역에 FruitSeller가 가지고 있는 멤버 변수에 대한 메모리 영역이 할당된다.

## 멤버 함수

- 객체가 수행할 수 있는 동작을 정의
    - 보통 멤버 필드를 이용하는 연산
    - 객체가 단순/구조체 변수와 다른 대표적 특징
- 멤버 필드를 조작하는 안전한 방법 제공
    - getter / setter
- 보통 클래스 정의 안에는 멤버 함수 선언만 기술(header에 선언하는 형식)
    - 멤버 함수 정의는 클래스 정의 밖에 따로 기술
    - 함수 구현까지 포함하는 경우 inline 함수로 지정됨
        - 단순하게 동작하는 함수의 경우는 메크로를 헤더에 포함해서 구현까지 하는 경우가 종종 있음

```cpp
[static] <반환형> <멤버함수명> ([인수타입1], ... , [인수타입n]);
```

## 멤버 함수의 구현

- 객체의 행위에 대한 함수의 body를 구현함으로써 기술
- 클래스 정의 밖에서 영역지정 연산자(::)를 이용하여 구현
    - 구현할 함수 이름 앞에 클래스 이름과 더불어 사용
    - 어느 클래스에 소속된 멤버 함수인지를 나타냄
    - 구현시 inline 키워드를 사용하면 inline 함수로 지정

```cpp
[static] <반환형> <클래스명>::<멤버함수명>([매개변수1], ... , [매개변수n]) {
	문장1;
	문장2;
	...
}
```

## 클래스 정의 예 - 과일 장수 클래스

- 속성: 보유하고 있는 사과 개수, 판매 수익
- 행위: 판매하기, 판매현황 보여주기

```cpp
// FruitSeller.h
class FruitSeller {
private:
    int numOfApple;
    int money;
public:
    FruitSeller(int numOfApple, int money);
    ~FruitSeller();

    int GetNumOfApple() { return numOfApple; }
    int GetMoney() { return money; }

    int SaleApple(int money);
    int ShowResult(void);
};
```

```cpp
// FruitSeller.cpp
#include "FruitSeller.h"
#include <iostream>

FruitSeller::FruitSeller(int num, int money)
{
    numOfApple = num;
    money = money;
}

int FruitSeller::SaleApple(int money)
{
    const int APPLE_UNITCOST = 1000;
    int num = money / APPLE_UNITCOST;
    
    numOfApple -= num;
    money += money;

    return num;
};

int FruitSeller::ShowResult()
{
    std::cout << "남은 사과: " << GetNumOfApple() << std::endl; 
    std::cout << "남은 돈:" << GetMoney() << std::endl;
};
```

## 객체의 생성과 멤버 접근

- 객체의 선언
    - 일반 변수와 마찬가지로 필요 메모리 할당
        - 메모리 할당 측면에서 C의 구조체 변수와 유사
- 멤버 접근
    - 멤버참조 연산자 . 이용

```cpp
#include <iostream>
#include <string>
#include "FruitSeller.h"

int main()
{
    FruitSeller fruitSeller(10, 1000);

    fruitSeller.SetMoney(2000);
    fruitSeller.SetNumOfApple(10);

    fruitSeller.SaleApple(5000);
    fruitSeller.ShowResult();

    return 0;
}
```

## 멤버 함수의 호출

- 객체에게 지정된 행위의 수행을 요청
    - 멤버 함수에 포함된 문장을 수행시키는 동작
    - 멤버 함수 호출도 하나의 표현식이기에 표현식이 나타날 수 있는 모든 곳에 사용 가능

```cpp
[변수명=] 객체명.멤버함수명(인수1,… 인수2)
```

- 함수 호출 시 함수 호출측은 함수에게 하나 이상의, 지정된 타입의 인수를 넘겨줄 수 있다.
- 함수 호출측은 호출의 결과로 하나의 값을 반환 받을 수 있다.

## 다중 소스 컴파일

- 클래스 헤더 파일: 클래스이름.h
    - 클래스 선언
    - 인라인 멤버 함수의 정의
    - 클래스 밖에 선언된 상수 선언
- 클래스 소스 파일: 클래스 이름.cpp
    - 멤버 함수의 정의
- 메인 소스 파일: 프로그램이름.cpp
    - main 함수의 정의 외

## 나(me) 클래스: FruitBuyer

- 속성
    - 보유 현금: money
    - 구매한 사과 개수: numOfApple
- 행위
    - 사과를 구매한다.
    - 구매현황을 보여준다.

```cpp
#pragma once

class FruitBuyer {
public:
    FruitBuyer(int money, int num);
    ~FruitBuyer();

    int totalMoney;
    int numOfApple;

    int BuyApple(int money);
    void ShowResult(void);
};
```

```cpp
#include <iostream>
#include "FruitBuyer.h"

FruitBuyer::FruitBuyer(int money, int num)
{
    totalMoney = money;
    numOfApple = num;
}

FruitBuyer::~FruitBuyer()
{
}

int FruitBuyer::BuyApple(int money)
{
    if (totalMoney < money) {
        return 0;
    }
    const int APPLE_UNITCOST = 1000;

    int num = money / APPLE_UNITCOST;
    totalMoney -= money;
    numOfApple += num;

    return num;
}

void FruitBuyer::ShowResult()
{
    std::cout << "남은 돈: " << totalMoney << std::endl;
    std::cout << "구매한 사과 갯수: " << numOfApple << std::endl;
}
```