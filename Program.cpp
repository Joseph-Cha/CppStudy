#include <iostream>
#include <cstddef>

using namespace std;

int main()
{
    int y = 5;
    int &ref_y = y;
    const int &const_ref_y = ref_y;

    return 0; 
}