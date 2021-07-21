#include <iostream>
#include <typeinfo>
#include <string>

 // 열거형의 단점을 보안하기 위해서 
 // 영역 제한 열거형(열거형 클래스)를 제공함
// 열거형의 값이 같은 경우를 방지하기 위해 class 키워드를 사용
// 일종의 namespace와 비슷
 enum class Color
 {
    RED,
    BLUE,
 };

 enum class Fruit
 {
    BANANA,
    APPLE,
 };
int main()
{
    using namespace std;

    Color color1 = Color::RED;  
    Color color2 = Color::BLUE;
    
    Fruit fruit = Fruit::APPLE;
    if (color1 == color2)
    {
        cout << "Same Color" << endl;
    }
    
    return 0;
}