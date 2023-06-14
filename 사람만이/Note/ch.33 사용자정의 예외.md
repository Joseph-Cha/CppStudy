# 33강. 사용자정의 예외

## 사용자 정의 예외 클래스

- 사용자가 정의한 예외 정보를 포함하는 클래스
    - 예외 값으로 예외 클래스로 만들어진 객체를 던질 수 있음
        - throw 이용
    - 던져진 객체는 예외 파라미터에 전달됨
        - 보통 catch 절에서 예외 클래스 형의 레퍼런스로 받음
        - 객체 복사가 되는 것이 아님!
    - 기본 자료형을 던질 때보다 좀더 다양한 정보 전달 가능

## 사용자 예외 예제
```cpp
#include <iostream>
#include <string>

class MyException {
    int lineNo;
    std::string func, msg;

public:
    MyException(int n, std::string f, std::string m)
        : lineNo(n), func(f), msg(m) {}
    void Print();
};

void MyException::Print()
{
    std::cout << func << ":" << lineNo << ", " << msg << std::endl;
}

// 0으로 나누는 예외 클래스 선언
class DivideByZeroException : public MyException {
    public:
        DivideByZeroException(int lineNo, std::string func, std::string msg)
            : MyException(lineNo, func, msg) {}
};

// 잘못된 입력 예외 클래스 선언
class InvalidInputException : public MyException {
public:
    InvalidInputException(int lineNo, std::string func, std::string msg)
        : MyException(lineNo, func, msg) {}
};

int main(void)
{
    int x, y;
    try {
        std::cout << "나눗셈을 합니다. 두개의 양의 정수를 입력하세요 >> ";
        std::cin >> x >> y;

        if (x < 0 || y < 0) {
            throw InvalidInputException(41, "main()", "음수 입력 예외 발생");
        }

        if (y == 0) {
            throw DivideByZeroException(49, "main()", "0으로 나누는 예외 발생");
        }
        std::cout << (double)x / (double)y;
    }
    catch (DivideByZeroException& e) {
        e.Print();
    }
    catch (InvalidInputException& e) {
        e.Print();
    }
}
```