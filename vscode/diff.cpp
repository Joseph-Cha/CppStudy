#include <iostream>
#include <algorithm>

using namespace std;

void doSomething()
{
    // LIKE_APPLE이 define이면
    #ifdef LIKE_APPLE
        cout << "APPLE" << endl;
    #endif

    // LIKE_APPLE이 not define이면
    #ifndef LIKE_APPLE
        cout << "Orange" << endl;
    #endif
}