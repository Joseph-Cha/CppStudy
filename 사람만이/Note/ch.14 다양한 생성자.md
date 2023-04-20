# 14강. 다양한 생성자

## 생성자(Constructor)

- 객체가 생성될 때 단 한 번 자동으로 호출되는 멤버 함수
    - 객체의 멤버 변수를 ‘초기화’
    - 일반적으로 명시적으로 따로 호출하지는 않음
- 생성자 구현 조건
    - 생성자 이름은 클래스 이름과 같아야 함
    - 반드시 return type이 지정되지 않아야 됨

```cpp
<생성자명>([매개변수1], ..., [매개변수n]) {
	수행문 1;
	수행문 2;
	...
}
```

## default 생성자

- 컴파일러에 의해 자동으로 제공
    - 프로그래머가 단 하나도 명시적으로 생성자를 정의하지 않음 경우에만 제공됨
    - 프로그래머가 생성자를 하나라도 정의하면 제공되지 않음
- 인자가 없는 생성자
    - 실제로 아무 일도 하지 않음!
    - 어떠한 초기화 작업을 하지 않는다

```cpp
FruitSeller seller; // ()가 없음
```

- default 생성자가 호출되도록 처리

## 매개변수를 가지는 생성자

- 객체가 가질 멤버 변수의 초기 설정값을 객체 생성시 전달 받음
    - instance 멤버 변수의 초기화
- 객체 생성 후 초기화 작업이 한 번에 수행
    - 초기화 작업에 대해 프로그래머가 신경쓰지 않아도 됨
    - 초기화 작업은 객체 생성시에만 수행됨
- FruitSeller seller(0, 20);

## 생성자 오버로딩

- 생성자의 다중정의
    - 매개변수 리스트가 서로 다른 생성자들
- 객체 생성 후 다양한 방법으로 객체 초기화를 위해 다수의 생성자 제공
    - FruitSeller s1(0, 20);
    - FruitSeller s2(20);

## 멤버 이니셜라이저(Member Initializer)

- 멤버 변수를 초기화하는 간단한 방법
- 생성자 정의시에만 사용 가능
    
    ```cpp
    생성자함수명(매개변수리스트): 멤버필드(값)
    {
    	// 다른 멤버 초기화 구문
    }
    ```
    
- 꼭 사용해야 하는 경우
    - 멤버 상수의 초기화 → 선언과 동시에 초기화가 필요
    - 멤버 레퍼런스의 초기화 → 선언과 동시에 초기화가 필요
    - 멤버 객체의 초기화 → 선언과 동시에 초기화가 필요
        - 이들의 공통점은 멤버 변수가 메모리를 할당 받는 시점에 초기화가 필요하다.
        - 이들의 경우는 멤버 이니셜라이저를 통해서만 객체 생성 시 초기화를 시켜줄 수 있다.
- 멤버 이니셜라이저를 통해 멤버를 초기화한 다음 생성자 함수의 내부 로직을 실행하게 된다.

## 수정된 클래스 선언 4안: 멤버 초기화자

```cpp
#pragma once

class FruitSeller {
private:
    const int APPLE_UNITCOST;

    int numOfApple;
    int money;

    void Init(int money, int numOfApple);
public:
    FruitSeller(int numOfApple, int money);
    ~FruitSeller();

    int GetNumOfApple() const { return numOfApple; }
    int GetMoney() const { return money; }

    void SetNumOfApple(int n) { numOfApple = n; }
    void SetMoney(int m) { money = m; }

    int SaleApple(int money);
    int ShowResult(void) const;
};

inline FruitSeller::FruitSeller(int num, int money)
    : APPLE_UNITCOST(1000)
{
    numOfApple = num;
    money = money;
}

inline void FruitSeller::Init(int m, int n)
{
    money = m;
    numOfApple = n;
}
```

```cpp
#pragma once

class FruitBuyer {
private:
    int totalMoney;
    int numOfApple;

public:
    FruitBuyer(int money, int num)
        : totalMoney(money), numOfApple(num) { };
    ~FruitBuyer();

    void Init(int money, int numOfApple);

    void SetMoney(int m) { totalMoney = m; }
    void NumOfApple(int n) { numOfApple = n; }

    int BuyApple(FruitSeller& seller, int money);
    void ShowResult(void);
};

inline void FruitBuyer::Init(int m, int n)
{
    numOfApple = n;
    totalMoney = m;
}
```

## 위임 생성자(Delegating Constructor)

- 한 클래스 내의 특정 생성자 구현시 오버로딩 되어 있는 다른 생성자를 호출할 때 사용
- 현재 클래스의 인수 리스트가 일치하는 생성자의 호출을 의미
- 생성자가 또 다른 생성자를 호출하는 구조

```cpp
#pragma once

class FruitSeller {
private:
    const int APPLE_UNITCOST;

    int numOfApple;
    int money;

public:
    FruitSeller(int numOfApple, int money);
    FruitSeller(int numOfApple);
    ~FruitSeller();

    int GetNumOfApple() const { return numOfApple; }
    int GetMoney() const { return money; }

    void SetNumOfApple(int n) { numOfApple = n; }
    void SetMoney(int m) { money = m; }

    int SaleApple(int money);
    int ShowResult(void) const;
};

inline FruitSeller::FruitSeller(int num, int money)
    : APPLE_UNITCOST(1000)
{
    numOfApple = num;
    money = money;
}

inline FruitSeller::FruitSeller(int numOfApple)
    : FruitSeller(0, numOfApple)
{
	
}
```