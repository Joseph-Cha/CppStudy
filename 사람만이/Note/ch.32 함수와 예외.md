# 32강. 함수와 예외

## 예외의 전달

- 예외가 발생되었으나 처리되지 않으면, 예외가 발생한 함수를 호출한 영역으로 예외가 전달됨
    - 예외가 발생한 위치와 예외를 처리해야 하는 위치가 달라야 하는 경우에 유용
    
    ![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.32/1.png)

## 예외 처리 매커니즘을 이용(최종)

```cpp
#include <iostream>
using namespace std;

int getExp(int base, int exp);
int main(void)
{
	try {
		int rv = getExp(2, -3); // 2의 -3승은?
		cout << "2의 -3승은 " << rv << "입니다." << endl;
	}
	catch (const char* e) {
		cout << "오류: " << e << endl; 
	}
	return 0;
}

int getExp(int base, int exp)
{
	if (base <= 0 || exp <= 0) throw "음수 사용 불가";
	int value = 1;
	for (int n = 0; n < exp; n++) {
		value = value * base;
	}
	return value
}
```

## 예외를 발생시키는 함수의 선언

- (선택적으로) throw 문을 가진 함수는 함수 선언문에 예외 발생을 명시할 수 있음
    - 가독성 향상
    - 프로그램의 작동을 명확히 함
        - 컴파일러에 따라 기술하지 않은 예외가 발생하면 중지시킴
    
    ```cpp
    반환자료형 함수이름(매개변수) throw(예외 자료형) {
    	...
    }
    ```
    
    - 발생 가능한 예외 자료형이 여럿인 경우 콤마로 구분하여 나열

## 예외를 발생시키는 함수의 선언의 예

```cpp
int max(int x, int y) throw(int)
{
	if (x < 0) throw x;
	else if (y < 0) throw y;
	else if (x > y) return x;
	else return y;
}
```

```cpp
double valueAt(double *p, int index) throw(int, char*)
{
	if (index < 0)
		throw "index out of bounds exception";
	else if (p == NULL)
		throw 0;
	else
		return p[index];
}
```

## 중첩된 예외처리

- try, catch 블럭에서 중첩된 예외처리 가능
    
    ```cpp
    try {
    	// ...
    	throw 3;
    	// ...
    	try {
    		throw "abc";
    		// ...
    		throw 5;
    		// ...
    	}
    	catch (int inner) {
    		cout << inner; // 5출력
    	}
    }
    catch (char* s) {
    	cout << s; // abc 출력
    }
    catch (int outer) {
    	cout << outer; // 3 출력
    }
    ```