#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    int x, y;

    cin >> x >> y ;
    cout << x << " " << y << endl;

    if (x == y)
        cout << "equal" << endl;
    if (x != y)
        cout << "not equal" << endl;
    if (x > y)
        cout << "x is greater than y" << endl;
    if (x < y)
        cout << "x is less than y" << endl;
    if (x >= y)
        cout << "x is greater than y or equal to y" << endl;
    if (x <= y)
        cout << "x is less than or equal to y" << endl;
    
    // 부동소수점끼리 비교할 때 주의 사항
    // 같아야 할 값이 같지 않을 경우
    double d1(100 - 99.99); // 0.001
    double d2(10 - 9.99);   // 0.001

    if (d1 == d2)
        cout << "equal" << endl;
    else
    {
        cout << "not equal" << endl; // 이게 출력
        if (d1 > d2)
            cout << "d1 > d2" << endl;
        else
            cout << "d1 < d2" << endl;
    }

    cout << d1 << endl; // 0.01
    cout << d2 << endl; // 0.01

    // 얼마나 다른지 알려면
    cout << abs(d1 - d2) << endl; // 5.32907e - 15


    // 두 값의 절대값이 일정 크기(epsilon)보다 작을 경우는 거의 같다고 해주기
    const double epsilon = 1e-10;
    if (abs(d1 - d2) < epsilon)
        cout << "Approximately equal" << endl;
    else
        cout << "Not equal" << endl;


    // epsilon의 크기에 따라 같을 수도 작을 수도 있을 수 있다
    // 그래서 그때 그때 다르다.
    // 결국 부동소수점에서 같은 경우를 따질 때는 위와 같이 epsilon을 통해 
    // 오차의 한계를 정해서 대강 같다고 판단하는 방법이 있다.

    return 0;
}
