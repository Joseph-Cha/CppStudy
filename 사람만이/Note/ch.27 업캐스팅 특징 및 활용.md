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