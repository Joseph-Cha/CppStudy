### 1.5 함수와의 첫 만남

``` C++
#include <iostream>

using namespace std;

int addNumbers(int a, int b)
{
	int sum = a + b;
	return sum;
}
void print(int a, int b)
{
	cout << addNumbers(a, b) << endl;
	return;
}


int main()
{
	cout << addNumbers(1, 2) << endl;
	cout << addNumbers(3, 4) << endl;
	cout << addNumbers(8, 13) << endl;
	print(1, 2);
	print(2, 3);
	print(8, 13);
	
	return 0;
}
```