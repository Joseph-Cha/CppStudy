# 29강. 순수 가상 함수와 추상 클래스

## 가상 함수(Virtual Funtion)

- 프로토 타입 앞에 virtual 키워드를 붙인 멤버 함수
- 가상 함수는 동적 바인딩 됨(다형성)
    - 객체 포인터 형이 아니라 객체 자신의 형에 따라 실행 중에 바인딩 될 함수가 결정됨
    - 업 캐스팅된 포인터로 오버라이딩 된 가상 함수 접근 시 derived 클래스의 멤버가 호출
- 가상 함수의 특징인 derived 클래스에서 virtual 키워드를 붙이지 않아도 상속됨
- 가상 함수라 함은 부모 클래스에서 정의 되어지는 내용을 상속관계에서 자식 클래스에서 재정의 해주게 되어진다라고 한다면 업캐스팅 되어진 포인터를 통해서 접근 하였을 때도 자식 클래스의 멤버가 호출되어질 수 있도록 처리하는 기능이다.
- 때에 따라 부모 클래스에서 정의되어진 어떤 멤버들을 상속 받은 모든 자식 클래스에서 항상 다 재정의 해 버린다라고 한다면 부모 클래스에서 제공되어지는 멤버 함수를 어떠한 자식 클래스에서도 사용하지 않는다면 사실상 부모 클래스에서는 재정의 되어질 멤버 함수의 구현을 제공해 줄 필요가 없을 수 있다.
- 따라서 부모 클래스에서 그 멤버함수를 제공하지 않게 되면 자식 클래스에서 필요한 멤버 함수들을 각각 정의해서 사용하면 되는데, 문제는 그 자식 클래스들 사이에서 공통의 멤버 함수를 제공할 수 있도록 그 구현을 강제화 해보고자 한다면 어떻게 할 수 있을까?

## 순수 가상 함수(Puru Virtual Funtion)

- 함수의 정의 없이 함수의 프로토 타입만 base 클래스에 제시해 놓은 함수
    
    ```cpp
    virtual 반환형 함수 이름(매개 변수_목록) = 0; // = 0을 명시함으로써 함수의 선언은 정의를 동반하지 않는다는 의미
    ```
    
- Base 클래스에서 가상 함수가 수행하는 연산이 의미 없을 때, 그 구현을 derived 클래스에게 넘기기 위한 명시적인 방법
- 반드시 derived 클래스에서 순수 가상 함수를 오버라이딩 해야 함
- 자식 클래스에서 멤버 함수를 “강제로” 재정의 해야 함
- 함수의 선언만 가지고 있는 형태이기 때문에 구현은 자식에서 해야함.
- 순수 가상 함수는 가상 함수의 부분 집합이다.
- 순수 가상 함수를 가지고 있는 클래스는 독립적으로 객체를 생성할 수가 없다.
- 반드시 파생 클래스에서 순수 가상함수를 재정의 하는 과정을 통해 몸체를 부여해 줘야 하고 그렇게 몸체를 부여 받은 경우에만 객체를 생성할 수 있게 된다.

## 추상 클래스(Abstract Class)

- 하나 이상의 순수 가상 함수를 포함한 클래스
- 불완전한 형태이므로 이 클래스 타입의 객체 생성은 불가
    - 단지 상속을 위해서만 존재
    - 추상 클래스형 포인터나 참조는 허용
- 여러 클래스들에 대한 동일 인터페이스를 강제 하기 위해 사용
    - 순수 가상 함수를 반드시 오버라이딩해야 하기에

## 예제

```cpp
#pragma once

#include <cstring>

class Person // 추상 클래스
{
    int age;
    char name[50];
public:
    Person(const char* name, int age);

    void WhatYourName() const;
    void HowOldAreYou() const;
    virtual void WhoAreYou() const = 0; // 순수 가상 함수
};

inline Person::Person(const char* name, int age) : age(age)
{
    strcpy(this->name, name);
}
```

```cpp
#include "Person.h"
#include <iostream>

void Person::WhatYourName() const
{
    std::cout << "My name is " << name << std::endl;
}

void Person::HowOldAreYou() const
{
    std::cout << "I'm " << age << " years old" << std::endl;
}
```

```cpp
#pragma once

#include "Person.h"
#include <cstring>

class UnivStudent : public Person
{
    char* major;

public:
    UnivStudent(const char* name, int age, const char* major);
    void WhoAreYou() const;
};

inline UnivStudent::UnivStudent(
    const char* name, 
    int age, 
    const char* major) : Person(name, age)
{
    this->major = new char[strlen(major) + 1];
    strcpy(this->major, major);
}
```

```cpp
#include "UnivStudent.h"
#include <iostream>

void UnivStudent::WhoAreYou() const
{
    WhatYourName();
    HowOldAreYou();
    
    std::cout << "My major is " << major << std::endl;
};
```

```cpp
#include "UnivStudent.h"
#include <iostream>

int main()
{
    UnivStudent s("hong, gil dong", 20, "computer");
    s.WhoAreYou();

    std::cout << std::endl;

    Person* pPerson = &s;
    pPerson->WhoAreYou();

    return 0;
}

/*
[UnivStudent::WhoAreYou()]
My name is Hong, gil dong
I'm 20 years old
My major is computer

[UnivStudent::WhoAreYou()]
My name is Hong, gil dong
I'm 20 years old
My major is computer
*/
```

## 추상 클래스의 사용

- 기반 클래스
    - 파생 클래스들 사이에 공통으로 필요한 메서드는 추상 클래스에 추가
        - 같은 이름, 같은 동작이 필요 → 일반 멤버 함수로
        - 같은 이름, 다른 동작이 필요 → 순수 가상 함수로
- 파생 클래스
    - 개별적 작성이 필요한 멤버 함수 작성
    - 기반 클래스의 순수 가상 함수를 오버라이딩