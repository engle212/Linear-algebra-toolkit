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
  int i1 = r1*cols;
  // Get first index of r2
  int i2 = r2*cols;

  for (int j = 0; j < cols; j++) {
    rep.at(j+i1) = rep.at(j+i1) + scalar * rep.at(j+i2);
  }
}

// row = [old]row * scalar
void Matrix::scaleRow(int row, float scalar) {

  // Get first index of row
  int i1 = row*cols;

  for (int j = 0; j < cols; j++) {
    rep.at(j+i1) = scalar * rep.at(j+i1);
  }
}

// r1 = [old]r2
// r2 = [old]r1
void Matrix::swap(int r1, int r2) {
  // Get first index of r1
  int i1 = r1*cols;
  // Get first index of r2
  int i2 = r2*cols;

  for (int j = 0; j < cols; j++) {
    float temp = rep.at(j+i1);
    rep.at(j+i1) = rep.at(j+i2);
    rep.at(j+i2) = temp;
  }
}
// Return true if column at col is all zeros
bool Matrix::isZero(int col) {
  int i = 0;
  bool isZero = true;
  while (isZero && i < rows) {
    isZero = compare(rep.at(col + i * cols), 0.0f);
    i++;
  }

  return isZero;
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
// m is rows//
// n is columns
void Matrix::Echelon() {
  // Check if matrix is large enough to compute Echelon
  if (rows != 1 && rep.size() > 1) {
    // Determine leftmost non-zero column
    // Maybe an isZero(col) function?
    // Use row ops to put 1 in the topmost position of the column (called pivot position)
    // Use row ops to put zeros below the pivot position
    // If no more zeros below the pivot position, done
    // Apply steps to submatrix of rows under pivot position
  }
}
void Matrix::ReducedEchelon() {
  std::cout << "PLACEHOLDER";
}