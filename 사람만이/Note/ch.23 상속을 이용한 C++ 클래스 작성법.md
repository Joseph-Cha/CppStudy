# 23강. 상속을 이용한 C++ 클래스 작성법

## C++에서 상속의 특징

- C++에서는 다중 상속이 제공
    - 여러 parent로부터 동시에 상속을 받아 새 클래스 작성이 가능
- 상속 관계는 클래스 정의시 명시적으로 지정한 경우에만 제공됨
    - java의 경우 기본 class는 object를 상속받는 구조로 구현이 됨
- 상속의 방법이 3가지로 나뉨
    - parent 클래스의 멤버를 기본적으로 어느 영역으로 가져갈 것인가에 따라 다름

## Derived 클래스 만들기

```cpp
class derivedClassName:access baseClassName {
		// derived 클래스 객체가 가질 멤버 추가 선언
};
```

- access 지장자: 상속 방법을 지정
    - public으로 상속
        - 멤버들의 접근 지정자가 그대로  유지
        - Base 클래스에서 위치하고 있는 접근 지정자가 파생 클래스에서도 그대로 유지
    - protected로 상속
        - 더 넓은 범위의 멤버들의 접근 지정자를 protected로 변경
        - 베이스 클래스에 존재하는 멤버들의 접근 지정자가 protected 보다 더 허용적인 경우 즉 public인 경우에 protected로 제한하고 나머지 경우는 모두 그대로 유지하게 된다.
    - private으로 상속
        - 멤버들의 접근 지정자를 private으로 변경
        - Base 클래스의 접근 지정자가 private보다 더 허용적인 즉 protected, public 멤버인 경우 private로 변경해서 가져 온다.
- Base 클래스의 private 멤버를 derived 클래스에서 직접 접근하는 것은 모든 경우에서 불가
    - Base 클래스의 private 멤버는 파생 클래스의 private 멤버로 전달되는 것이 아니다.
    - Base 클래스의 private 멤버가 파생 클래스에 전달은 되어지지만 Base의 private인채로 전달되어 진다.