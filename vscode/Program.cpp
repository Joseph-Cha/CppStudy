#include <iostream>
#include <limits>

using namespace std;

int main()
{
    float f;
    double d;
    long double ld;

    cout << 1.0 / 3.0 << endl;
    
    cout << numeric_limits<float>::max() << endl;
    cout << numeric_limits<double>::max() << endl;
    cout << numeric_limits<long double>::max() << endl;

    cout << numeric_limits<float>::min() << endl; // 표현하는 숫자의 가장 작은 수
    cout << numeric_limits<double>::min() << endl;
    cout << numeric_limits<long double>::min() << endl;
    
    cout << numeric_limits<float>::lowest() << endl; // 비교할 때 사용
    cout << numeric_limits<double>::lowest() << endl;
    cout << numeric_limits<long double>::lowest() << endl;

    // float f(3.141592f); // 3.14 = 31.4 * 0.1
    // double f(3.141592);
    // long double ld(3.141592);

    cout << 3.14 << endl;
    cout << 31.4e-1 << endl; // 3.14 (3.14 -10의 1제곱)
    cout << 31.4e-2 << endl; // 0.314
    cout << 31.4e1 << endl; // 314
    cout << 31.4e2 << endl; // 3140
    
    return 0;
}