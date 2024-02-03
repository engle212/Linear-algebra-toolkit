#include <iostream>
#include "lamath.h"

using namespace std;

int main() {
  const int r = 3;
  const int c = 4;
  int array[r][c] = {{1, 3, 4, 5}, {1, 1, 0, 2}, {2, 2, 2, 0}};
  Matrix m = Matrix((int*)array, r, c);

  string str = m.toString();
  cout << str;
  return 0;
}