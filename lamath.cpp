#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "lamath.h"

bool compare(float a, float b, float epsilon = 0.0001f) {
    return (fabs(a - b) < epsilon);
}

void Matrix::setDim(int m, int n) {
  rows = m;
  cols = n;
  rep.resize(rows*cols, 0);
}

// r1 = [old]r1 + scalar * r2
void Matrix::add(int r1, int r2, float scalar) {
  // Get first index of r1
  // Get first index of r2
  std::cout << "PLACEHOLDER";
}

// row = [old]row * scalar
void Matrix::scaleRow(int row, float scalar) {
  std::cout << "PLACEHOLDER";
}

// r1 = [old]r2
// r2 = [old]r1
void Matrix::swap(int r1, int r2) {
  std::cout << "PLACEHOLDER";
}

// Construct empty Matrix
Matrix::Matrix(int m, int n) {
  setDim(m, n);
}

// Construct Matrix from array
Matrix::Matrix(int *arr, int r, int c) {
  // Set to dimensions of arr
  setDim(r, c);
  // Load array values into rep
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      rep[cols*i+j] = arr[cols*i+j];
    }
  }
}
std::string Matrix::toString() {
  std::string str = "{";
  // Cycle through rep and display values
  for (size_t i = 0; i < rows*cols; i++) {
    if (i != 0 && i % cols == 0) {
      str += "}\n{";
    }
    str += "[" + std::to_string(rep.at(i)) + "]";
  }
  str +="}";
  return str;
}
void Matrix::Echelon() {
  std::cout << "PLACEHOLDER";
}
void Matrix::ReducedEchelon() {
  std::cout << "PLACEHOLDER";
}