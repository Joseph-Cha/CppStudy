# 11강. C++ 클래스의 기본 구조 및 사용

## 기본 클래스의 구조

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.11/1.png)

- SimpleData::SetData(int n)에서 ::을 붙이는 이유는 SetData라는 함수가 SimpleData 클래스에서 정의된 함수라는 사실을 식별하기 위함이다.
- 다른 클래스에서도 동일하게 SetData가 있을 수도 있기 때문에 이를 식별하기 위한 연산자이다.
- 더불어 SimpleData에서 data라는 변수에 바로 접근을 하고 있는데 이게 가능한 이유가 SetData라는 함수는 SimpleData라는 클래스 안에 존재하는 함수이기 때문에 SimpleData의 멤버 변수의 값을 곧바로 접근할 수 있는 것이다.

## 변수의 유효범위와 접근 지정자

- 변수의 유효범위(Scope Rule)
    - 정의된 변수가 프로그램 내에서 참조 가능한 범위를 가르킴
- 접근 지정자에 의해 기본 유효범위가 바뀜
    - private
        - 전용 영역으로 선언
        - class의 기본영역
    - protected
    - public
        - 공용 영역으로 선언
        - 외부 클래스에서도 자유롭게 접근이 가능