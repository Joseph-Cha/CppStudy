# 19강. 동적할당된 다양한 객체 배열

## 동적 할당된 배열

- 동적 할당된 (1차원) 배열의 선언
    
    ```cpp
    object_type* p-var = new object_type[size];
    ```
    
    - 동적 할당배열의 요소 초기화는 불가능
    - size 갯수 만큼의 객체를 가리키는 주소를 전달 받게 된다.
- 동적 할당된 배열의 해제
    
    ```cpp
    delete [] p-var;
    ```
    
    - 배열의 각 요소에 대해 소멸자를 호출

## 예제

```cpp
#include <iostream>
#include <string>
#include "Point.h"

const int NLIST = 5;
Point* CreateList(int n);

int main()
{
    Point* pList = CreateList(NLIST);

    int i;
    
    for (i = 0; i < NLIST; i++) {
        (pList + i)->GetX();
        (pList + i)->GetY();
    }

    delete [] pList;

    return 0;
}

Point* CreateList(int n)
{
    Point* p = new Point[n];

    for (int i = 0; i < n; i++) {
        (p + i)->SetX(i);
        (p + i)->SetY(i);

    }

    return p; // 동적할당된 메모리는 delete하기 전까지는 사라지지 않는다.
}
```

## C++에서 객체 배열 생성 방법들

- 지역적으로 선언
    
    ```cpp
    Point clist1[2];
    Point clist2[] = {
        Point(10, 20),
        Point(20, 30)
    };
    clist2[0].GetX();
    ```
    
- 동적 생성
    
    ```cpp
    Point* plist = new Point[n];
    (plist + 1)->GetX();
    delete [] plist;
    ```