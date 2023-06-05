# 30강. 예외 상황과 예외 처리의 개념

## 실행 시 오류의 종류

- 컴파일 시간 오류
    - 컴파일 오류
        - 문법에 맞지 않은 구문으로 인함
    - 링크 오류
        - 호출문과 함수의 정의를 연결하지 못함
        - 함수의 호출문과 그에 따른 함수의 선언 부분은 존재하나 함수의 정의가 제공되지 않아서 링킹 시 즉 호출문과 그 호출에 따른 함수의 정의 부분을 정적 바인딩 하는 과정에서 연결할 수 없다라는 오류가 발생되어지는 경우가 되어질 것
        - 일반적으로 링크 오류는 함수의 정의를 누락한 경우나 혹은 함수 호출문과 선언과 달리 함수의 정의에서 함수의 이름에 오타 등으로 잘못 작성되어지는 경우들이 대표적인 경우이다.
- 실행 시간 오류
    - 논리 오류: 잘못된 결과값을 냄
        - 프로그래머가 잘못 구현하거나 잘못 설계한 경우에 주로 발생
    - 예외 상황에 따른 오류
        - 잘못된 입력이나 예외적인 데이터 발생 시
            - 정수를 0으로 나누기, 잘못된 입력 파일명 등

## 예외 상황에 대한 대처가 없는 예

- 지수승을 계산하는 함수의 이용
    
    ```cpp
    #include <iostream>
    
    int getExp(int base, int exp);
    
    int main()
    {
        int rv = getExp(2, -3);
        std::cout << "2의 -3승은 " << rv << "입니다." << std::endl; // 2의 -3승은 1입니다.
    
        return 0;
    }
    
    // base의 exp 지수승을 계산하여 리턴
    int getExp(int base, int exp)
    {
        int value = 1;
        for (int n = 0; n < exp; n++) {
            value = value * value; // base를 exp번 곱하여 지수 값 계산
        }
        return value;
    }
    ```
    
    - 오답: 2^3은 1이 아니라 1/8
    - getExp를 구현한 의도와 달리 의도하지 않은 방법으로 사용을 한 상황이다.

## 조건문을 이용한 예외 상황 처리

- 예외 상황 발생 여부를 검사 후 처리
    
    ```cpp
    #include <iostream>
    
    int getExp(int base, int exp);
    
    int main()
    {
        int rv = getExp(2, -3);
    
        if (rv != -1) {
            std::cout << "2의 -3승은 " << rv << "입니다." << std::endl; // 2의 -3승은 1입니다.
        } else {
            std::cout << "오류: 계산할 수 없습니다!" << std::endl;
        }
        
        return 0;
    }
    
    // base의 exp 지수승을 계산하여 리턴
    int getExp(int base, int exp)
    {
        if (base <= 0 || exp <= 0) {
            return -1; 
        }
        int value = 1;
        for (int n = 0; n < exp; n++) {
            value = value * value; // base를 exp번 곱하여 지수 값 계산
        }
        return value;
    }
    ```
    
    ## 예외 상황 발생 여부의 확인
    
    - 예외 상황 발생 여부를 검사 후 처리
        
        ```cpp
        #include <iostream>
        
        int getExp(int base, int exp);
        
        int main()
        {
            int rv = 0;
            bool isNoErr = getExp(2, -3, rv);
        
            if (isNoErr) {
                std::cout << "2의 -3승은 " << rv << "입니다." << std::endl; // 2의 -3승은 1입니다.
            } else {
                std::cout << "오류: 계산할 수 없습니다!" << std::endl;
            }
            
            return 0;
        }
        
        // base의 exp 지수승을 계산하여 리턴
        bool getExp(int base, int exp, int& retVal)
        {
            if (base <= 0 || exp <= 0) {
                return false;
            }
            int value = 1;
            for (int n = 0; n < exp; n++) {
                value = value * value; // base를 exp번 곱하여 지수 값 계산
            }
        
            retVal = value;
            return true;
        }
        ```
        
    
    ## 예외(Exception)
    
    - 프로그램 실행 중에 예기치 못한 상황에서 발생하는 비정상적인 상황을 가리킴
        - 문법적 오류가 아닌 논리적 오류
        - 연산지에 의해 발생할 수 있음
            - 정수 0으로 나누는 경우
        - 예외적으로 발생하는 상황이나 입력에 따른 오류
        - 인위적으로 발생시킬 수도 있음
            - 문법적으로 문제가 없으나 논리적으로 맞지 않은 상황을 예외로 규정 가능
    
    ## 예외 처리(Exception Handling)
    
    - 예외발생 시 프로그램의 비정상적인 종료대신 계속해서 정상적인 수행을 할 수 있도록 처리
        - 기본적으로 예외가 발생하면 프로그램의 비정상적인 종료 발생
        - 개발자가 예외 탐지의 처리 코드를 직접 작성해 적절히 처리해야 함
    - 기존의 예외상황 처리 방법
        - if 조건문으로 예외 상황을 처리하는 코드의 구분이 어려움
        - 예외상항이 발생한 이후의 처리가 복잡해짐