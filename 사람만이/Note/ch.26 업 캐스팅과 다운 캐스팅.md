# 26강. 업 캐스팅과 다운 캐스팅

## 다형성(Polymorphism)

- 다양한 형태가 존재한다는 의미
    - 프로그래밍을 유연하게 만들어주는 메커니즘
- 실행 때 객체 종류에 따라 달라지는 코드 사용을 프로그래밍 때 구분하지 않고 사용하게 해줌
    - 프로그래밍을 단순하게 만들어주는 효과

## 포인터 객체를 간접 참조하는 방법

- 기본적으로 포인터의 base type과 저장할 객체의 자료형이 일치해야 함
    
    ```cpp
    Person person("hong", 20);
    Pserson* pPerson = &person;
    ```
    
    ```cpp
    Person* pPerson = new Person("hong", 20); 
    ```
    
    - C++에서 상속과 관련되어지는 다형성의 특징은 오로지 포인터로 객체를 참조하거나 혹인 레퍼런스로 객체를 참조할 때에만 그 특징이 나타난다.
    - 위와 같이 Person 타입 포인터를 사용하기 위해서는 Person 객체를 동적 할당하거나 Person 타입의 레퍼런스를 할당해야 가능하다.
    - 하지만 다형성을 이용하면 생성되는 객체의 타입과 포인터의 타입이 서로 달라질 수 있다

## 업 캐스팅

- Base 클래스형 포인터/레퍼런스는 derived 클래스 객체를 가리키는데 사용 가능
    - 자동 형 변환이 일어남
        
        ```cpp
        Person* pPerson;
        pPerson = new UnivStudent;
        ```
        
        ```cpp
        pPerson = (Person *) (new UnivStudent);
        ```
        
    - Derived 클래스 객체의 성질은 그대로 유지됨
- 자식 타입의 클래스가 부모 타입의 클래스로 형 변환이 되는 것을 업 캐스팅이라고 한다.

## 업 캐스팅의 예

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.26/1.png)

## 다운 캐스팅

- Derived 클래스형 포인터/레퍼런스는 base 클래스 객체를 가리킬 수 없음!
    
    ```cpp
    UnivStudent* pStud = new Person; // 오류
    ```
    
    - 명시적 형변환으로 컴파일 오류는 피할 수 있더라도 런타임 에러 발생
- 업 캐스팅 된 포인터는 명시적 형변환을 통해 다운 캐스팅 하는 것은 가능
    
    ```cpp
    Person* pPerson = new UnivStudent;
    UnivStudent* pStud = (UnivStudent*)pPerson; // 실제로 UnivStudent 주소 값(원래 나의 타입)으로 접근 하기 때문에 가능
    ```
    
- 포인터 자체가 다운 캐스팅이 가능함

## 잘못된 다운 캐스팅의 예

```cpp
UnivStudent* pStud = new Person; // 오류
UnivStudent* s = (UnivStudent*)new Person(); // 명시적 형변환을 하지만 런타임 오류 발생
```

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.26/2.png)

- pStud가 가리키는 위치에 UnivStudent 객체가 있을 것으로 예상하고 접근을 해보지만 실제로는 Person 객체가 있기 때문에 에러 발생
- Person 객체라고 할지라도 온전히 UnivStudent가 아니기 때문에 다운 캐스팅은 실패함

## 유효한 다운 캐스팅의 예
```cpp
Person* pPerson = new UnivStudent;
UnivStudent* pStud = (UnivStudent*)pPerson; // 명시적으로 업캐스트 되기 전 타입을 선언해 줘야 한다.
```

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.26/3.png)