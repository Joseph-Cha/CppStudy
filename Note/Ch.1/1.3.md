### 1.3 변수와의 첫 만남

``` C++
#include <iostream>

int main()
{
	//int x = 12; // initialization
	//int x(12); // initialization
	//x = 123; // assignment
	//// L value 
	//// R value 

	//std::cout << x << std::endl;
	//std::cout << &x << std::endl;
	int x = 1;
	x = x + 2;
	std::cout << x << std::endl; // 3
	int y = x;
	std::cout << x + y << std::endl; // 6
	std::cout << x << std::endl; // 3

	int z;
	std::cout << &z << std::endl;

	return 0;
}
```