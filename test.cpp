#include <iostream>
#include "lamath.h"

using namespace std;

int main() {
    int array[3][3] = {{1, 3, 4}, {1, 1, 0}, {2, 2, 2}};
    Matrix m(array, 3);

    string str = m.toString();
    cout << str;
    return 0;
}