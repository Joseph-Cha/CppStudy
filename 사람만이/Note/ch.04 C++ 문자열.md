# 4강. C++의 문자열

## C++에서의 문자열 표현

### 방법1: C-String 방식

- 널문자(\0)으로 끝나는 char 배열
    
    ```cpp
    char str1[3] = { 'h', 'i', '\0' }; // str1은 문자열 "hi"
    char str2[2] = { 'h', 'i' };       // str2는 문자열이 아니라 단순 문자 배열
    ```
    
    ![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.04/1.png)
    
    - str3[10]으로 메모리 공간을 확보했기 때문에 추후 9개 문자를 넣을 수 있는 문자열 배열이 된다(마지막은 널문자를 넣아야 하므로 9개까지만 사용이 가능하다).
    - 다만 이렇게 C 스타일로 문자열을 표현하면 배열을 만들 때 사전에 필요한 크기만큼을 미리 확보를 해야한다.
    - 이를 해소하기 위해 물론 동적 할당된 배열을 사용할 수 있다.

### 방법2: string 클래스 이용

- <string> 헤더 포함 필요

## 예제

### C-String 방식

```cpp
#include <iostream>

int main()
{
    std::cout << "당신의 이름을 입력하세요:";

    char name[11]; // 한글은 5개 글자(2byte * 2 -> 1byte(char) * 10), 영문은 10개까지
    char first_name[11];
    
		std::cin >> name >> first_name;

    std::cout << "당신의 이름은 " << name << "입니다." << std::endl;
    std::cout << "당신의 성은 " << first_name << "입니다." << std::endl;

    return 0;
}
```

- 입력을 동훈 차라고 했을 때 입력 버퍼에는 “동훈 차”까지 들어가 있지만 실제로 출력을 할 때는 스페이스를 기준으로 값을 읽어 출력을 해준다.

### string 클래스 이용

```cpp
#include <iostream>
#include <string>

int main()
{
    std::cout << "당신의 이름을 입력하세요:";

    std::string name; // 한글은 5개 글자(2byte * 2 -> 1byte(char) * 10), 영문은 10개까지
    std::cin >> name;

    std::cout << "당신의 이름은 " << name << "입니다." << std::endl;

    return 0;
}
```

## 참고: 공백을 포함하는 문자열의 입력

- cin 객체에서 지원하는 getline() 이용
    - cin.getline(char buf[], int size, char delimitChar)
        - buf에 최대 size-1개의 문자를 입력 받음 → 함수를 호출할 때는 size만큼 입력 필요
        - size-1개의 문자가 입력되지 않았더라도 delimitChar를 만나면 입력 중단
        - 입력된 문자열 끝에 널문자가 자동으로 붙음
        
        ![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.04/2.png)
        

## C-String 방식으로 문자열 다루기

- C 언어에서 사용한 문자열 라이브러리 사용 가능
    - strlen(), strcmp(), strcpy() 등
        - 각 함수에서 처리할 문자열의 시작 주소를 넘겨줌
    - <cstring> 헤더 포함 필요
        - C 스타일의 헤더인 string.h도 가능하나 표준 방법 사용 권장

### C-String 방식

```cpp
#include <iostream>
#include <cstring>

int main()
{
    char password[11];
    std::cout << "프로그램을 종료하려면 암호를 입력하세요." << std::endl;
    while (true) {
        std::cout << "암호: ";
        std::cin >> password;
        if (strcmp(password, "C++") == 0) {
            std::cout << "암호가 일치합니다!" << std::endl;
            break;
        }
        else {
            std::cout << "암호가 틀렸습니다!";
        } 
    }
    
    return 0;
}
```

### string 클래스
```cpp
#include <iostream>
#include <string>

int main()
{
    std::string password;
    std::cout << "프로그램을 종료하려면 암호를 입력하세요." << std::endl;
    while (true) {
        std::cout << "암호: ";
        std::cin >> password;
        if (password == "C++") {
            std::cout << "암호가 일치합니다!" << std::endl;
            break;
        }
        else {
            std::cout << "암호가 틀렸습니다!" << std::endl;
        } 
    }

    return 0;
}
```