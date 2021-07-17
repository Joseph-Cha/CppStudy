#include <iostream>
#include "myConstHeader.h"

extern int e;

void doSomething4()
{
    using namespace std;
    cout << "Hello" << endl;
    cout << "In test.cpp " << constants::pi << endl;
    cout << "In test.cpp, address of pi " << &constants::pi << endl;

}