# 12. C++에서의 캡슐화와 정보은닉 개념

## 실습: Rectangle 클래스

- 화면 상에 존재하는 하나의 직사각형을 나타내고 넓이와 둘레를 구해보자
    - 사각형의 좌측 상단 꼭짓점과 우측하단 꼭짓점 유지
        - int lt_x, lt_y; → 좌칙 상단 꼭짓점
        - int rb_x, rb_y; → 우측 상단 꼭짓점
    - 넓이/둘레 산출
        - int getArea(void);
        - int getPerimeter(void);

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.12/1.png)

## 캡슐화(Encapsulation)

- 데이터와 그와 관련된 연산(함수)들을 하나의 객체로 묶음
    - 보다 쉽고 안전한 사용 가능
    - 정보 은닉이 포하된 개념
- 반드시 하나의 클래스로 만들어야 하는 건 아님

## 정보은닉의 필요성

```cpp
#pragma once

class Point
{
public:
    Point();
    ~Point();

    int x, y;
};
```

```cpp
#pragma once

#include "Point.h"

class Rectangle
{
public:
    Point lt, rb;

    int getArea(void);
    int getPerimeter(void);
};
```

- Point형 객체의 멤버 변수가 0~100 사이의 값만 가질 수 있게 보장하지 못함
- Rectangle형 객체의 멤버 변수가 좌우 정보가 뒤바뀌게 저장되는 것을 막을 수 없음

## 정보은닉(Information Hiding)

- 객체 외부에 인터페이스만 드러내고 객체의 내부 구현은 숨김
    - 멤버 변수의 조작은 가능한 한 공개된 멤버 함수를 통해서만 접근
        - 멤버 변수의 접근을 제한: private / protected
            - 부적절한 값이 저장되는 것을 방지
            - 실수가 쉽게 발견될 수 있도록
        - 멤버 함수를 통한 안전한 접근만 허용
    - 프로그램의 다른 부분에 영향을 미치지 않고 쉽게 변경 가능

## 변수의 유효범위와 접근지정자

- 변수의 유효범위(Scope Rule)
    - 정의된 변수가 프로그램 내에서 참조 가능한 범위를 가르킴
- 접근 지정자에 의해 기본 유효범위가 바뀔 수 있다.
    - private
    - protected
    - public
- 특정 객체의 상태 정보를 갖고 있는 멤버변수를 생각해 보면 그 객체가 생성되었을 때부터 소멸될 때까지 메모리에 들고 있을 것이다.

## 클래스 멤버의 접근 지정자

### private:

- 전용영역을 선언
    - 현재 클래스 객체 외부에서 접근 불가
- 일반적으로 멤버 변수에 사용 / class의 기본값

### public:

- 공용영역을 선언
    - 클래스 객체 외부에서 접근을 허용(인터페이스 역할)
- 일반적으로 멤버 함수에 사용 / struct의 기본값

### protected:

- 보호영역을 선언
    - 기본적으로 private처럼 외부에서 접근 불가
    - 상속한 클래스 객체에서는 접근 가능
    - 외부에서는 자식 클래스에서만 접근 가능

## 접근 지정자의 특징

- 접근 지정자 A가 선언 시 그 이후에 등장하는 멤버는 A 범위 내에서 접근 가능
- 새 접근 지정자 B 선언 시, 그 이후에 등장하는 멤버는 B 범위 내에서 접근 가능
- 클래스 밖의 멤버 함수 정의에서도 자신의 private 멤버에 접근 가능
- 기본 접근 지정자
    - 구조체: public
    - 클래스: private

## Access 함수

- (필요에 따라)특정 멤버 변수의 값을 얻어오거나 설정하는 멤버 함수
    - 멤버 변수를 객체 외부에서 직접 조작하는 대신 Getter나 Setter를 통한 안전한 접근 제공
        - Getter
            - 지정된 멤버 변수의 값을 반환
        - Setter
            - 지정된 멤버 변수를 실인수의 값으로 설정
            - 실인수에 할당되는 값이 유효한지 체크 후 할당하는 형식
    - 당장 필요하지 않더라도 필요할 것으로 예상되면 멤버에 포함 시킴

## 예: Point 클래스의 정보은닉

```cpp
#pragma once

class Point {
private:
    int x, y;

public:
    int GetX(void);
    int GetY(void);

    bool SetX(int xPos);
    bool SetY(int yPos);
};
```

```cpp
#include <iostream>
#include "Point.h"

int Point::GetX(void) {
	return x;
}

int Point::GetY(void) {
	return y;
}

bool Point::SetX(int xPos) {
	if (xPos < 0 || xPos > 100) {
        std::cout << "오류: 범위가 벗어난 값 > " << xPos << std::endl;
        return false;
    }
    x = xPos;
    return true;
}

bool Point::SetY(int yPos) {
    if (yPos < 0 || yPos > 100) {
        std::cout << "오류: 범위가 벗어난 값 > " << yPos << std::endl;
        return false;
    }
    y = yPos;
    return true;
}
```

```cpp
#pragma once

#include "Point.h"

class Rectangle
{
private:
    Point lt, rb;
public:
    bool Init(Point& leftTop, Point& rightBottom);

    int getArea(void);
    int getPerimeter(void);
};
```

```cpp
#include <iostream>
#include "Point.h"
#include "Rectangle.h"

bool Rectangle::Init(Point& leftTop, Point& rightBottom) {
    if (leftTop.GetX() > rightBottom.GetX() || leftTop.GetY() > rightBottom.GetY()) {
        std::cout << "오류: 잘못된 설정 값!" << std::endl;
        return false;
    }

    lt = leftTop;
    rb = rightBottom;

    return true;
}

int Rectangle::getArea(void) {
	return (rb.GetX() - lt.GetX()) * (lt.GetY() - rb.GetY());
}

int Rectangle::getPerimeter(void) {
	return (rb.GetX() - lt.GetX() + lt.GetY() - rb.GetY()) * 2;
}
```

## const 멤버 함수

- 멤버 함수 헤더 마지막에 const 키워드 사용
- 멤버 함수 내에서 어떠한 멤버 변수의 값도 변경되지 못하도록 함
    - 멤버 변수를 변경하는 문장은 컴파일 시 에러
    - 보통 getter에서 사용
    - const가 아닌 멤버 함수 호출 불가
        - 간접적인 변경 가능성 차단
    - const 레퍼런스 매개변수를 이용해선 const 멤버 함수만 호출 가능
- 컴파일 타임 때 에러 발생

## 예: const 멤버함수로 수정

```cpp
#pragma once

#include "Point.h"

class Rectangle
{
private:
    Point lt, rb;
public:
    bool Init(Point& leftTop, Point& rightBottom);

    int getArea(void) const;
    int getPerimeter(void) const;
};
```

```cpp
int Rectangle::getArea(void) const {
	return (rb.GetX() - lt.GetX()) * (lt.GetY() - rb.GetY());
}

int Rectangle::getPerimeter(void) const {
	return (rb.GetX() - lt.GetX() + lt.GetY() - rb.GetY()) * 2;
}
```

- `getArea`와 `getPerimeter`는 const 멤버 함수로 이 함수 내부에서는 어떠한 멤버 변수의 값도 변경 시키지 않는다라는 것을 의미한다.