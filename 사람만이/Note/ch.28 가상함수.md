# 28강. 가상 함수

```cpp
#pragma once

#include <cstring>

class Person
{
    int age;
    char name[50];
public:
    Person(const char* name, int age);

    void WhatYourName() const;
    void HowOldAreYou() const;
    void WhoAreYou() const;
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

void Person::WhoAreYou() const
{
    WhatYourName();
    HowOldAreYou();
}
```

```cpp
#pragma once

#include "Person.h"
#include <cstring>

class UnivStudent : public Person
{
    char major[50];

public:
    UnivStudent(const char* name, int age, const char* major);
    void WhoAreYou() const;
};

inline UnivStudent::UnivStudent(
    const char* name, 
    int age, 
    const char* major) : Person(name, age)
{
    strcpy(this->major, major);
}
```

```cpp
#include "UnivStudent.h"
#include <iostream>

void UnivStudent::WhoAreYou() const
{
    Person::WhoAreYou();
    std::cout << "My major is " << major << std::endl;
};
```

```cpp
#include "UnivStudent.h"
#include <iostream>

int main()
{
    UnivStudent s("hong, gil-dong", 20, "computer");
    s.WhoAreYou();

    std::cout << std::endl;
    Person* pPerson = &s;

    pPerson->WhoAreYou();
    return 0;
}

/*
[UnivStudent::WhoAreYou]
My name is hong, gil dong
I'm 20 years old
My major is computer 

[Person::WhoAreYou]
My name is hong, gil dong
I'm 20 years old
*/
```

- `pPerson→WhoAreYou`를 호출하면 `pPerson`의 원본 객체가 `UnivStudent`임에도 불구하고 `Person::WhoAreYou`를 호출하게 된다.
- 만일 UnivStudent::WhoAreYou를 호출하기를 원했다면 pPerson을 아래와 같이 캐스팅을 해줘야 한다.
    
    ```cpp
    ((UnivStudent *)pPerson)->WhoAreYou();
    ```
    

## 바인딩

- 함수 호출을 함수의 정의와 결합해둔 것
    - 정적 바인딩
        - 컴파일 때 호출될 함수를 결정 지음
            - 컴파일 때에는 포인터 타입만 알 수 있기에 오버라이딩 된 함수의 경우 base의 멤버로 접근됨
            - 포인터의 타입 객체 멤버로 접근하게 된다.
        - 일반적인 함수의 바인딩 방법
    - 동적 바인딩
        - 프로그램이 실행되는 중에 호출될 함수를 결정
        - 가상 함수의 바인딩 방법

## 가상 함수(Virtual Function)

- 프로토타입 앞에 virtual 키워드를 붙인 멤버로 함수
- 가상 함수는 동적 바인딩 됨(다형성)
    - virtual 키워드가 붙은 함수는 정적 바인딩이 아니라 동적 바인딩 될 수 있도록 컴파일러에게 지시
    - 객체 포인터 형이 아니라 객체 자신의 형에 따라 실행 중에 바인딩 될 함수가 결정됨
    - 업 캐스팅된 포인터로 오버라이딩 된 가상 함수 접근 시 derived 클래스의 멤버가 호출
- 가상 함수의 특징인 derived 클래스에서 virtual 키워드를 붙이지 않아도 상속됨

```cpp
#pragma once

#include <cstring>

class Person
{
    int age;
    char name[50];
public:
    Person(const char* name, int age);

    void WhatYourName() const;
    void HowOldAreYou() const;
    virtual void WhoAreYou() const; // virtual 키워드 추가
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

void Person::WhoAreYou() const
{
    WhatYourName();
    HowOldAreYou();
}
```

- 함수 선언부에만 virtual 키워드를 붙이고 구현부에는 따로 붙이지 않아도 된다.

```cpp
#pragma once

#include "Person.h"
#include <cstring>

class UnivStudent : public Person
{
    char major[50];

public:
    UnivStudent(const char* name, int age, const char* major);
    void WhoAreYou() const;
};

inline UnivStudent::UnivStudent(
    const char* name, 
    int age, 
    const char* major) : Person(name, age)
{
    strcpy(this->major, major);
}
```

- derived 클래스에서는 virtual 키워드를 붙이지 않아도 괜찮다.
- 왜냐하면 parent 클래스에서 이미 virtual 클래스를 정의했기 때문에 가상함수 특징이 그대로 상속 되었기 때문이다.

```cpp
#include "UnivStudent.h"
#include <iostream>

int main()
{
    UnivStudent s("hong, gil-dong", 20, "computer");
    s.WhoAreYou();

    std::cout << std::endl;
    Person* pPerson = &s;

    pPerson->WhoAreYou();
    return 0;
}

/*
[UnivStudent::WhoAreYou]
My name is hong, gil dong
I'm 20 years old
My major is computer 

[UnivStudent::WhoAreYou]
My name is hong, gil dong
I'm 20 years old
My major is computer 
*/
```

- `pPerson→WhoAreYou()`를 호출해도 원본인 `UnivStudent::WhoAreYou()`를 호출하게 된다.

## 가상함수 vs 오버로딩 함수

| 가상 함수 | 오버로딩 함수 |
| --- | --- |
| 재정의의 한 예
 - 매개 변수의 타입과 수, 반환형이 정확하게 일치 해야 함 | 다중정의
  - 매개변수의 타입이나 개수가 달라야 한다 |
| 멤버 함수만 가능 | 멤버 함수 or 일반 함수 모두 가능 |
| 생성자는 가상함수 불가 | 생성자는 오버로딩 가능
  - 일반적 선택 |
| 소멸자는 가상 함수 가능
  - 일반적 선택 | 소멸자는 오버로딩 불가 |

## virtual 소멸자

- 업 캐스팅 된 포인터로 delete 하는 경우 base 클래스의 소멸자만 호출됨
- 따라서 포인터 Base 타입과 상관 없이 항상 해당 객체의 모든 소멸자를 호출하기 위해서는
    - Base 클래스의 소멸자를 virtual 함수로 지정 필요

```cpp
#pragma once

#include <cstring>
#include <iostream>

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
		std::cout << "~Person()" << std::endl;
		delete[] name;
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
		~UnivStudent();
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

inline UnivStudent::~UnivStudent()
{
		std::cout << "~UnivStudent" << std::endl;
		delete[] major;		
}
```

```cpp
#include "UnivStudent.h"
#include <iostream>

int main()
{
    Person* pPerson;
		pPerson = new UnivStudent("hong, gil dong", 20, "computer");

		pPerson->WhatYourName();
		delete pPerson;

    return 0;
}

/*
[UnivStudent::~Person()]
My name is hong, gil dong
~Person() 
*/
```

- ~Person() 소멸자만 호출되는 것을 확인 할 수 있다.
- ~Person에서 virtual 키워드를 사용하지 않았기 때문!
- 따라서 아래와 같이 수정을 해야 한다.

```cpp
#pragma once

#include <cstring>
#include <iostream>

class Person
{
    int age;
    char* name;
public:
    Person(const char* name, int age);
    virtual ~Person(); // virtual 키워드 추가

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
		std::cout << "~Person()" << std::endl;
		delete[] name;
}
```

```cpp
#include "UnivStudent.h"
#include <iostream>

int main()
{
    Person* pPerson;
		pPerson = new UnivStudent("hong, gil dong", 20, "computer");

		pPerson->WhatYourName();
		delete pPerson;

    return 0;
}

/*
[UnivStudent::~UnivStudent()]
My name is hong, gil dong
~UnivStudent()
~Person() 
*/
```

- 자식의 소멸자와 부모의 소멸자가 같이 호출되는 것을 확인할 수 있다.

## dynamic_cast<type-id*>(exp) 사용 방법

```cpp
#pragma once

#include <cstring>
#include <iostream>

class Person
{
    int age;
    char* name;

public:
    Person(const char* name, int age);

    void WhatYourName() const;
    void HowOldAreYou() const;
		virtual void WhoAreYou() const;
};

inline Person::Person(const char* name, int age) : age(age)
{
		this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
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

    const char* GetMajor() const { return major; }
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

int main()
{
    Person* list[2];

    list[0] = new Person("Il, Ji mae", 21);
    list[1] = new UnivStudent("Hong, gil dong", 20, "computer");

    UnivStudent* us;
    for (int i = 0; i < 2; i++) {
        list[i]->WhoAreYou();
        std::cout << std:: endl;

        us = dynamic_cast<UnivStudent*>(list[i]);
        if (us != NULL)
        {
            std::cout << us->GetMajor() << std::endl;
        }
    }

    return 0;
}

/*
[Person::WhoAreYou()]
My name is Il, Ji mae
I'm 21 years old

[UnivStudent::WhoAreYou()]
My name is Hong, gil dong
I'm 20 years old
My major is computer

[UnivStudent::GetMajor()]
computer
*/
```

- 캐스팅 불가 시 NULL을 반환하기 때문에 list[0] 요소는 NULL을 반환하게 된다.
- dynamic_cast를 사용하기 위해서는 부모 클래스에서 virtual 함수가 있어야 한다.