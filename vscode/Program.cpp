#include <iostream>

int main()
{
    4 + 2 * 3; // 10
    (4 + 2) * 3; // 18
    
    // 결합 법칙을 통해 우선순위를 정함
    3 * 4 / 2; // 6 왼쪽부터 계산

    // 우선순위가 애매하면 ( )괄호를 통해 우선순위를 명확하게 남기는 게 좋음
    std::cout << "Hello World!";

    return 0;
}
