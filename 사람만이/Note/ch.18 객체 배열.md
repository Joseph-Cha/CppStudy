# 18강. 객체 배열

## 객체 배열이란?

- 배열의 요소가 객체인 경우
    
    ```cpp
    클래스명 배열이름[요소개수];
    ```
    
- 같은 클래스 타입의 객체들을 연속된 메모리 공간에 할당
    - 연속된 메모리 공간에 객채들을 할당하고 하나의 이름 및 index를 통해 접근
- 생성자가 있는 클래스의 경우 객체 배열 선언함과 동시에 각 객체 초기화 가능
    - 일반 배열의 초기화 형태를 사용하되,
    - 초기값 자리에 인수가 일치하는 생성자 호출

## 객체 배열의 선언과 선택

```cpp
Complex clist[3];
for (int i = 0; i < 3; i++)
	clist[i].ShowComplex();
```

![Untitled](/resources/%EC%82%AC%EB%9E%8C%EB%A7%8C%EC%9D%B4/ch.18/1.png)

- 지역 내에서 배열을 선언만 해도 연속된 스택 메모리에 객체가 할당이 된다.

## 객체 배열과 포인터

```cpp
Complex clist[] = {
	Complex(2,3),
	Complex(4,8),
	Complex(8,16),
	Complex(16,32)
};

Complex* pCom;
pCom = clist; // 배열의 첫 번째 주소값을 저장
pCom->ShowComplex() // pCom이 가리키고 있는 객체(clist[0])의 ShowComplex 호출
(pCom+1)->ShowComplex(); // clist[1]이 가리키고 있는 객체의 ShowComlex 호출
```

- pCom + 1을 해주게 되면 pCom이 가리키고 있는 타입의 크기 만큼의 메모리 주소를 이동시켜서 접근을 하게 된다. 따라서 배열의 다음 주소에 접근이 가능하다.

## 함수의 매개변수로 객체 배열 사용

- 일반 배열의 경우와 동일
- 실인수에는 배열의 이름만 기술
    - 배열의 시작주소를 전달
    - 함수 내에서 접근하고자 하는 배열의 크기
    
    ```cpp
    fn(list, 3);
    ```
    
- 형식 매개변수에는 배열의 시작 주소를 저장할 포인터 변수 필요
    
    ```cpp
    void fn(Complex* array, int n); // 배열의 시작 주소를 저장하기 위해 포인터 변수 필요
    void fn(Complex array[], int n);
    ```