# 15. 소멸자

## 소멸자

- 객체가 소멸할 때 단 한번 자동으로 호출되는 멤버 함수
    - 객체 정리(동적 할당된 메모리 해제 등) 작업
    - 명시적으로 따로 호출하지는 않음
- 일반적으로 객체가 생성되어지면서 그 객체 내부에 만들어진 멤버 변수들은 객체가 소멸될 때 자동으로 할당 해제가 되어져서 우리가 추가적으로 소멸시 정리 작업을 해줄 필요는 없다.
- 다만 포인터 멤버 필드를 통해 객체 외부에 동적 할당된 영역을 유지하고자 하는 구조체 변수인 경우 객체가 소멸되어질 때 객체 외부에 유지하고  있는 동적 할당된 메모리(heap memory)를 정리해 주는 작업들이 필요하다.
- 마찬가지로 클래스의 멤버 필드 안에 모든 내용들을 해당하는 객체가 직접 갖고 있다라고 한다면 원칙적으로 소멸자는 추가적으로 해줘야 될 일이 필요 없기 때문에 굳이 만들어 주지 않아도 된다.
- 다만 클래스의 멤버 필드 내에 포인터 변수를 두고 그 포인터 변수를 통해서 객체 외부에 동적 할당된 메모리를 유지하고 있다면, 그저 현재 객체가 소멸되어지면 끝나는 것이 아니라 현재 객체가 소멸되어지기 전에 그 객체 외부에 유지하고 있는 동적할당된  메모리를 먼저 지워주고 나서 자기가 소멸되어 한다. 그렇지 않으면 객체 외부에 동적으로 할당된 메모리가 정리되어지지 않고 남아 있게 되어지는 일이 발생되어지지 않을 수 있다(memory leak).
- 함수 영역에서 생성한 클래스의 경우는 해당 함수 영역이 끝나는 것과 동시에 메모리가 해제되어 소멸자가 호출되게 된다.
- 소멸자 구현 조건
    - 소멸자 이름은 클래스 이름 앞에 틸드(~) 붙임
    - 반드시 return type이 지정되지 않아야 됨
    - 매개변수를 전달 받음 못함
        - 오버로딩 불가

## default 소멸자

- 컴파일러에 의해 자동으로 제공
    - 프로그래머가 명시적으로 소멸자를 정의하지 않은 경우에만 제공됨
    - 프로그래머가 소멸자를 정의하면 제공되지 않음
    - 실제로 아무 일도 하지 않음!
        - 일반적인 경우 객체 소멸 시 아무 일도 할 필요 없음
- 멤버 변수에 포인터를 포함하지 않는 일반적인 경우는 대부분 소멸자 불필요
    - 동적할당된 영역을 가리키는 포인터 멤버

## 예제
```cpp
#pragma once
#include <iostream>

class Point {
private:
    int x, y;

public:
    Point(int xPos = 0, int yPos = 0);
    ~Point();

    int GetX(void) const;
    int GetY(void) const;

    bool SetX(int xPos);
    bool SetY(int yPos);
};

inline Point::Point(int xPos, int yPos)
{
    x = xPos;
    y = yPos;
}

inline Point::~Point()
{
    std::cout << "(" << x << " , " << y << "( 소멸" << std::endl;
}
```

```cpp
#pragma once

#include <iostream>
#include "Point.h"

class Rectangle
{
private:
    Point lt, rb;
public:
    bool Init(Point& leftTop, Point& rightBottom);

    Rectangle(Point& leftTop, Point& rightBottom);
    ~Rectangle();

    int getArea(void) const;
    int getPerimeter(void) const;
};

inline Rectangle::Rectangle(Point& leftTop, Point& rightBottom)
{
    lt.SetX(leftTop.GetX());
    lt.SetY(leftTop.GetY());

    rb.SetX(rightBottom.GetX());
    rb.SetY(rightBottom.GetY());

    // lt = leftTop;     -> 값을 복사(deep copy)
    // rb = rightBottom; -> 값을 복사(deep copy)
}

inline Rectangle::~Rectangle()
{
    std::cout << "객체가 소멸되었다." << std::endl;
}
```