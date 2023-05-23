# 24강. 파생 클래스의 생성자와 소멸자

## 생성자와 상속

- Parent 클래스의 생성자는 child 클래스 객체 생성 시 사용할 수 없음
    - child 클래스 객체를 초기화하기에는 부족
- Derived 클래스 객체를 위한 생성자
    - 반드시 derived 클래스에서 새롭게 정의되야 함
    - Derived 클래스의 생성자 구현시
        - 상속 받은 멤버를 초기화하기 위해 base 클래스의 생성자를 이용
        - 즉, derived 클래스의 생성자에선 다음 작업 수행
            - base 클래스의 생성자 호출
            - 자신에게 추가된 멤버에 초기값 설정

## 파생 클래스 객체의 생성 과정

- Derived 클래스 객체가 생성되면
    - 객체 생성시 지정된 인수 값이 derived 클래스의 생성자의 매개변수를 전달되고,
    - 우선, base 클래스의 인자 없는 생성자가 자동으로 호출되며,
        - 첫 문장에 base 클래스의 생성자 호출 구문이 있으면 이 과정은 생략됨
    - 이후, derived 클래스의 생성자 구현부의 문장들이 처리됨

## 인자있는 생성자만 갖는 클래스 상속

- Parent 클래스에 인자 없는 생성자 부재로 derived 클래스의 생성자에서 오류 발생
    - base 클래스에 인자없는 생성자를 제공하거나
    - derived 클래스 객체 생성 시 호출될 base 클래스의 생성자를 명시적으로 지정
        - derived 클래스에 생성자에서 콜론(:) 초기화를 통한 base 클래스 생성자 호출로 base 클래스 멤버 초기화

```cpp
derived_constructor(매개변수_list) : base_constructor(인수_list)
{
		// ..
}
```

## 상속과 생성자 예

```cpp
class Person
{
		int age;
		char name[50];
public:
		Person(const char* name, int age);
		void WhatYourName() const;
		void HowOldAreYou() const;
};

inline Person::Person(const char* name, int age) : age(age)
{
		strcpy(this->name, name);
}
```

```cpp
class UnivStudent : public Person
{
		char major[50];
public:
		UnivStudent(const char* name, int age, int char* major);
		void WhoAreYou() const;
};

inline UnivStudent::UnivStudent(const char* name, int age, const char* major)
		: Person(name, age)
{
		strcpy(this->major, major)
}
```

```cpp
#include "UnivStudent.h"

int main(void)
{
		UnivStudent s("hong, gil-dong", 20, "computer");
		s.WhoAreYou();

		return 0;
}
```

## 상속과 소멸자

- Base 클래스와 derived 클래스는 각각 자신의 소멸자를 가질 수 있음
    - base 클래스의 멤버는 base 클래스의 소멸자로
    - derived 클래스의 멤버는 derived 클래스의 소멸자 이용
- Derived 클래스 객체 소멸 시 파생역순으로 소멸자가 호출됨
    - derived 클래스의 소멸자 호출 후
    - base 클래스의 소멸자 호출

## 상속과 소멸자 예
```cpp
class Person
{
		int age;
		char* name;
public:
		Person(const char* name, int age);
		~Person();

		void WhatYourName() const;
		void HowOldAreYou() const;
};

inline Person::Person(const char* name, int age) : age(age)
{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
}

inline Person::~Person()
{
		delete [] name;
}
```

```cpp
class UnivStudent : public Person
{
		char major[50];
public:
		UnivStudent(const char* name, int age, int char* major);
		~UnivStudent()

		void WhoAreYou() const;
};

inline UnivStudent::UnivStudent(const char* name, int age, const char* major)
		: Person(name, age)
{
		this->major = new char[strlen(major) + 1];
		strcpy(this->major, major)
}

inline UnivStudent::~UnivStudent()
{
		delete [] major;
}
```