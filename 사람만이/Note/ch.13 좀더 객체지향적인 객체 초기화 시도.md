# 13강. 좀더 객체지향적인 객체 초기화 시도

## 사과장수 시뮬레이션 개선

- 각 객체 생성 후 instance 멤버 변수의 초기값 설정 필요
    - 초기화 위해 멤버 변수에 직접 전근하는 것은 바람직 하지 않음
- 멤버 변수는 private 영역에 두고 객체의 멤버 변수를 초기화하는 멤버 함수 추가
    - 각 멤버 변수마다 setter 추가
    - 초기화를 수행하는 멤버 함수 추가

## 수정된 클래스 선언 1안: setter 추가

```cpp
#pragma once

class FruitSeller {
private:
    int numOfApple;
    int money;
public:
    int GetNumOfApple() { return numOfApple; }
    int GetMoney() { return money; }

    void SetNumOfApple(int n) { numOfApple = n; }
    void SetMoney(int m) { money = m; }

    int SaleApple(int money);
    int ShowResult(void);
};
```

```cpp
#pragma once

class FruitBuyer {
private:
    int totalMoney;
    int numOfApple;

public:
    void SetMoney(int m) { totalMoney = m; }
    void NumOfApple(int n) { numOfApple = n; }

    int BuyApple(FruitSeller& seller, int money);
    void ShowResult(void);
};
```

## 수정된 클래스 선언 2안: Initializer 추가

```cpp
#pragma once

class FruitBuyer {
private:
    int totalMoney;
    int numOfApple;

public:
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

```cpp
#pragma once

class FruitSeller {
private:
    int numOfApple;
    int money;
public:
    void Init(int money, int numOfApple = 0);
    void Init(int numOfApple);

    int GetNumOfApple() { return numOfApple; }
    int GetMoney() { return money; }

    void SetNumOfApple(int n) { numOfApple = n; }
    void SetMoney(int m) { money = m; }

    int SaleApple(int money);
    int ShowResult(void);
};

inline void FruitSeller::Init(int m, int n)
{
    money = m;
    numOfApple = n;
}

inline void FruitSeller::Init(int numOfApple)
{
    Init(0, numOfApple);}
```

- 인라인 함수의 정의부는 header파일에 있어야 정상적으로 동작한다(cpp 소스에 들어가 있으면 안된다).