#include "lib.h"

#include <iostream>

using namespace std;

int main (int, char **)
{
    cout << "build " << $TRAVIS_BUILD_NUMBER<< endl;
    cout << "Hello, World!"
    return 0;
}
