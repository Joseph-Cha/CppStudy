# 21강. C++의 static 멤버

## instance 멤버 vs static 멤버

- instance 멤버
    - 각 객체 생성 시 별도의 메모리 할당
    - 객체 이름과 멤버 참조 연산자로 접근 가능
- static 멤버(class 단위 멤버)
    - 프로그램 시작시 메모리 할당, 프로그램 종료 시 소멸
    - 클래스 이름과 영역 지정 연산자로 객체를 생성하지 않고서도 접근 가능

## static 멤버 변수

- 어떤 클래스 클래스 내에 멤버 변수를 선언을 하되 그 멤버 변수를 static 변수로 선언을 하면 그 static 멤버변수는 해당 클래스의 객체가 하나도 생성되어지지 않았다 하더라도 정적 메모리 영역에 할당되어 지고 그 클래스 타입의 인스턴스가 여러개 생성되었다 할지라도 모든 객체 간의 공유되어 지는 특징을 가지고 있다.
- 조건
    - 클래스 내부에 static 키워드를 이용하여 선언
    - 클래스 이름과 영역지정 연산자로 클래스 바깥에서 초기화
        - 클래스 선언부나 생성자에서 초기화하지 않음!
- 접근 방법
    - 객체 생성 없이 클래스명과 영역지정 연산자로 접근
    - 객체 존재시 객체 이름으로도 접근 가능
        - 즉 인스턴스 변수에서도 영역지정 연산자로 static 멤버에 접근 가능
        - 하지만 인스턴스 변수로 접근 시 혼돈의 여지가 있기 때문에 보통 클래스명과 영역지정 연산자로 접근을 한다.

## static 멤버 변수의 예

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.21/1.png)

- c1과 c2가 모두 같은 count 멤버 변수를 바라보고 있다.

## static 멤버 상수

- 보통 멤버 상수는 static 멤버로 정의
    - 한 클래스의 instance들 간에 같은 값을 가지므로 각 객체가 별도의 메모리를 할당 받지 않아도 됨
    - 클래스 선언 안에 초기값 부여 허용

```cpp
class StaticConstant {
	static const int MAX_VALUE;

public:
	static int getMax() { return MAX_VALUE; }
};
const int StaticConstant::MAX_VALUE = 100; // 멤버 상수의 경우 이렇게 초기화할 필요가 없다.
```

```cpp
class StaticConstant {
	static const int MAX_VALUE = 100; // 멤버 상수의 경우 클래스 선언에서 초기화 가능

public:
	static int getMax() { return MAX_VALUE; } // static 멤버 함수
};
```

- 특정 클래스가 가지고 있는 상수 값은 각각의 객체가 똑같은 상수 값들을 서로 다른 메모리 공간에 할당 받아서 공유할 필요가 없다.
- 어차피 상수는 한 번 정의되면 그 값이 변경되어 질 수 없기 때문에 그 클래스 타입의 모든 객체가 공유 되어지는 영역의 상수를 만들어 놓고 하나의 상수 값을 다수의 객체가 공유해서 사용하는 것이 메모리 활용에 좋다.
- 특정 클래스에서 멤버 상수를 정의하면 그 상수들은 인스턴스 멤버로 정의하기 보다 static 멤버로 정의하는 것이 좀더 일반적이다.
- 멤버 상수에 접근을 할 때 객체를 생성하지 않고서도 접근할 수 있는 함수 구현을 위해 사용하는 것이 static 멤버 함수이다.

## static 멤버 함수

- static 멤버 함수 내에서는
    - this 사용 불가 → 객체 생성 없이 호출하기 때문
    - instance 멤버는 직접 접근 불가
        - 객체를 생성 후 객체 이름을 통한 접근은 가능
    - static 멤버는 직접 접근 가능
- 객체 생성 없이 호출 가능
    - static 멤버 필드의 안전한 접근 제공
    - 간편한 사용을 위해 객체 생성과 관련 없는 일반적인 기능 제공

## static 멤버 함수의 예

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.21/2.png)

## instance 멤버 vs static 멤버

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.21/3.png)