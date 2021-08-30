### 1.13 네임스페이스

``` C++
#include <iostream>

// namespace를 사용함으로써 함수 이름이 중복되는 경우를 방지해준다.
namespace Myspace1
{
    namespace InnerSpace
    {
        int my_function()
        {
            return 0;
        }
    }
    int doSomething(int a, int b)
    {
        return a + b;
    }

} 

namespace Myspace2
{
    int doSomething(int a, int b)
    {
        return a * b;
    }
}

// iostream 안에 namespace std가 정의 되어 있기 때문에 
// 아래와 같이 using namespace를 사용할 수 있다.
using namespace std;

int main()
{
    using namespace Myspace1;
    using namespace Myspace1::InnerSpace;

    my_function();
    
    cout << Myspace2::doSomething(3, 4) << endl; // 12
    cout << doSomething(3, 4) << endl; // 7
    return 0;
}
```