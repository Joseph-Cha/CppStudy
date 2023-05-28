# 27강. 업캐스팅 특징 및 활용

## 업 캐스팅 된 포인터의 활용

- 객체 포인터 배열에서
    - Base 클래스형의 객체 포인터 배열은 다양한 종류의 derived 클래스의 객체를 가리킬 수 있음
        
        ```cpp
        Person* pList[10];
        pList[0] = new Person;
        pList[1] = new UnivStudent;
        ```
        
- 포인터 매개 변수에서
    - Base 클래스형의 포인터 매개변수는 다양한 종류의 derived 클래스 객체를 넘겨 받을 수 있음
        
        ```cpp
        void Fn(Person* p);
        ```

## 업 캐스팅된 포인터의 성질(1)

- Derived 클래스의 멤버 중 base 클래스로부터 상속 받은 멤버만 직접 접근이 가능
    - derived 클래스에서 추가된 멤버에는 접근 불가
        
        ```cpp
        pPerson->WhatYourName(); // 정상
        pPerson->WhoAreYou();    // 컴파일 오류
        ```
        
- 상속 받지 않은 멤버에 접근하기 위해선 다운 캐스팅 후 조작
    
    ```cpp
    UnivStudent pStud;
    pStud = (UnivStudent *) pPerson;
    ((UnivStudent *) pPerson)->WhoAreYou(); // pPerson에서 바로 접근하는 것이 아니라 다운 캐스팅 후 접근
    ```
    

## 업 캐스팅된 포인터의 성질(2)

- 오버라이딩 된 멤버에 접근 시 base class에서 정의한 멤버로 접근
    
    ```cpp
    pPerson->WhoAreYou(); // base의 멤버 호출
    ```
    
    - 업 캐스팅된 포인터가 가리키는 대상이 자식 클래스임에도 불구하고 부모 클래스 멤버가 호출된다.
- 따라서 오버라이딩 된 멤버에 접근하기 위해선 다운 캐스팅 후 조장
    
    ```cpp
    ((UnivStudent *) pPerson)->WhoAreYou();
    ```
    
    - 즉, 오버라이딩된 WhoAreYou() 멤버 함수를 호출하기 위해서는 다운 캐스팅 후 호출을 해줘야 한다.
- 오버라이딩 된 멤버는 base class형 포인터로 접근할 가능성이 많음
    - 좀더 쉬운 방법 제공 필요 → 가상함수 제공

## dynamic_cast<type-id *>(exp)

- exp를 type-id형의 객체로 캐스팅
    - type-id는 포인터(혹은 레퍼런스)여야 함
    - 주어진 표현식은 exp는
        - type-id가 포인터인 경우, 객체에 대한 주소 값
        - type-id가 레퍼런스인 경우, l-value여야 함
    - 캐스팅 불가 시 NULL을 결과값으로 가짐
- base 클래스에 가상함수가 포함되어 있어야 사용 가능
- 상속과 관련된 다형성 특징을 통해서 다수의 데이터들을 업캐스팅 되어진 포인터(부모 클래스 포인터)를 통해서 특정 객체를 가리키고자 한다면 실제 그 업캐스팅 되어진 포인터가 가리키는 객체의 타입을 식별해 보고 싶을 때가 있을 것이다.
- 이를 위해 dynamic_cast라는 연산자를 제공해 준다.
- 업캐스팅 되어진 포인터에 대해서 다운 캐스팅하고 하는 클래스 타입을 기술해 주게 되어지면 dynamic_cast의 결과로 exp 포인터가 가리키는 객체를 type-id 타입으로 캐스팅 할 수 있으면 그렇게 다운 캐스팅한 결과 주소값을 반환해 주고 그렇지 않으면 NULL을 반환해 준다.