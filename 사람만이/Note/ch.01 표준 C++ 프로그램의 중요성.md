# C++ 프로그래밍 과정

## C++ 프로그래밍 단계

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.01/1.png)

## 각 프로그래밍 단계 별 오류의 종류

- 컴파일 시간 오류
    - 컴파일 과정에서 생긴 문법적인 오류
- 링크 시간 오류
    - 링크 과정에서 생긴 함수 호출-정의 간 연결 오류
- 논리 오류
    - 프로그램을 실행하면서 잘못된 결과를 내는 경우
    - 대부분의 경우 프로그래머가 직접 어떻게 해당 오류가 발생했는지 찾아야 한다.
    - 이때 사용하는 것인 디버깅이다.
    - 소스코드가 한 라인씩 실행되면서 변수, 메모리 값을 확인하여 어느 지점이 문제가 되는지 확인해 주는 도구
- 실행시간 오류(Run-time error)
    - 실행 중에 예상치 못한 이유로 비상정적으로 종료
    - 포인터나 배열을 잘못 사용했을 경우 발생할 수 있다.

## 표준 C++ 프로그램의 중요성

- 표준의 중요성
    - 표준에 의해 작성된 C++ 프로그램
        - 모든 플랫폼. 모든 표준 C++ 컴파일러에 의해 컴파일
        - 동일한 실행 결과 보장
        - 운영체제와 컴파일러의 종류에 관계 없는 높은 호환성
        - 다양한 환경에서 컴파일 될 수 있도록 표준의 필요성이 대두되었다.

## 표준/비표준 C++ 프로그램의 비교

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.01/2.png)

- 컴파일러의 종류와 상관 없이 동작하도록 해준다.