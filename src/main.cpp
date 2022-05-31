#include <iostream>
#include "test.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    char * name;

    cin >> name;

    your_name(name);
    return 0;
}