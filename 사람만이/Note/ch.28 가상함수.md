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