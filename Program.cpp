#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x;
    tryAgain : // label
    cout << "Enter a non-negative number" << endl;
    cin >> x;

    if (x < 0.0)
    {
        // 해당 label로 이동
        // 어셈블리에서는 반복문도 goto로 돌아감
        // goto문이 while을 대체함
        // 계획적으로 반복문을 짜는 방법을 사용함
        goto tryAgain;
    }
    cout << sqrt(x) << endl;

    return 0;
}