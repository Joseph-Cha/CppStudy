# 25강. Overriding(재정의)

- Derived 클래스에서 base 클래스에서와 같은 이름의 멤버를 다시 정의
    - 기존의 멤버를 요구 사항에 맞게 수정하는 효과
    - base 클래스에서와 동일한 형태로 정의
- Base 클래스에서 상송된 멤버는 은폐됨
    - sub 클래스 객체의 멤버 함수에서 은폐된 멤버에 접근하기 위해 `base_클래스명::멤버명` 을 이용
- ≠ Overloading

## Overriding 예

```cpp
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
void Person::WhatYourName() const
{
		cout << "My name is " << name << endl;
}

void Person::HowOldAreYou() const
{
		cout << "I'm " << age << " years old" << endl;
}

void Person::WhoAreYou() const
{
		WhatYourName();
		HowOldAreYou();
}
```

```cpp
class UnivStudent : public Person
{
		char major[50];
public:
		UnivStudent(const char* name, int age, int char* major);
		void WhoAreYou() const; // 재정의;
};

inline UnivStudent::UnivStudent(const char* name, int age, const char* major)
		: Person(name, age)
{
		strcpy(this->major, major)
}
```

```cpp
void UnivStudent::WhoAreYou() const
{
		Person::WhoAreYou(); // this 포인터가 아니라 Parent의 클래스를 지정
		cout << "My major is " << major << endl;
	}
```

## 오버라이딩 vs 오버로딩
![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.25/1.png)