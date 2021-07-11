#include <iostream>
#include <bitset>

int main()
{
    using namespace std;
    /* 
    bool item1_flag = false;
    bool item2_flag = false;
    bool item3_flag = false;
    bool item4_flag = false;
    */
    // 1byte 변수 하나만 사용해서 8가지 경우의 On & Off를 표현할 수 있다.
    // 아이템 8개 소유 여부를 표현할 수 있지 않을까??
    // 아이템 1을 가졌을 때 0000 0001
    // 아이템 2를 가졌을 때 0000 0010
    // 아이템 3를 가졌을 때 0000 0100
    // 아이템 4를 가졌을 때 0000 1000
    // ...

    // 이렇게 위와 같이 1byte 타입으로 8가지 아이템의 소유 여부를 확인할 수 있다.

    const unsigned char opt0 = 1 << 0;
    const unsigned char opt1 = 1 << 1;
    const unsigned char opt2 = 1 << 2;
    const unsigned char opt3 = 1 << 3;
    // ...

    cout << bitset<8>(opt0) << endl; // 0000 0001
    cout << bitset<8>(opt1) << endl; // 0000 0010
    cout << bitset<8>(opt2) << endl; // 0000 0100
    cout << bitset<8>(opt3) << endl; // 0000 1000
    // ...


    unsigned char items_flag = 0;

    cout << "No item " << bitset<8>(items_flag) << endl; // 0000 0000

    // item_0을 얻었을 때
    // 각 자리수를 비교해서 둘 중 하나라도 1이면 1로 바꿈
    // 0000 0000
    // 0000 0001
    items_flag |= opt0;
    cout << "item0 obtained" << " " << bitset<8>(items_flag) << endl; // 0000 0001

    // item_3을 얻었을 때
    // 0000 0001
    // 0000 1001
    items_flag |= opt3;
    cout << "item3 obtained" << " " << bitset<8>(items_flag) << endl; // 0000 1001
    
    // item_3을 잃었을 때
    // 아이템을 잃었기 때문에 일단 보수로 바꿔주고
    // 보수로 바꾼 결과와 flag의 값을 비교해서 둘다 true일 때 1로 바꿔줌
    // 0000 1001
    // 1111 0111
    items_flag &= ~opt3;
    cout << "item3 lost" << " " << bitset<8>(items_flag) << endl; // 0000 0001

    // has item 1?
    // opt1의 자리수의 값과 flag릐 값이 같으면 true
    if (items_flag & opt1) { cout << "Has item1 " << items_flag << endl; }
    else { cout << "Not have items1" << endl; }
    
    // has item 0?
    if (items_flag & opt0) { cout << "Has item0" << items_flag << endl; }

    // obtain item 2, 3
    items_flag |= (opt2 | opt3);

    cout << bitset<8>(opt2 | opt3) << endl; // 0000 1100
    cout << "item2, 3 obtained " << bitset<8>(items_flag) << endl; // 0000 1101

    return 0;
}