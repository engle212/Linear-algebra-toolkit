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

// Return rep index given row and column of an element
int Matrix::indexOf(int r, int c) {
  return cols * r + c;
}

// Return row that the index i is located in
int Matrix::rowOf(int i) {
  return i / cols;
}

// Return column that the index i is located in
int Matrix::columnOf(int i) {
  return i % cols;
}

// Return row with minimum value in the given column col
int Matrix::minRow(int firstRow, int col) {
  float min = rep.at(indexOf(firstRow, col));
  int mRow = firstRow;

  if (rows - firstRow > 1) {
    int x = indexOf(minRow(firstRow+1, col), col);
    if (rep.at(x) < min) {
      min = rep.at(x);
      mRow = rowOf(x);
    }
  }
  return mRow;
}

// Sort rows based on given column col
// Selection Sort
void Matrix::sortRows(int firstRow, int col) {
  if (rows - firstRow > 1) {
    // Get minimum of rows in question
    // Swap it with firstRow
    swap(firstRow, minRow(firstRow, col));
    // sortRows excluding firstRow
    sortRows(firstRow+1, col);
  }
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

// Populate Matrix using a 1D vector
void Matrix::populateWith1DVector(std::vector<float> vector) { // Tested and working properly
  rep = vector;
  rep.resize(rows * cols);
}

// m is rows//
// n is columns
void Matrix::Echelon() {
  // Check if matrix is large enough to compute Echelon
  if (rows != 1 && rep.size() > 1) {
    // Determine leftmost non-zero column
    int i = 0;
    bool nonZeroColFound = false;
    while (i < cols && !nonZeroColFound) {
      nonZeroColFound = !isZero(i);
      i++;
    }
    int leftmostNonZeroCol = i - 1;

    // Use row ops to put 1 in the topmost position of the column (called pivot position)
    // Selection sort
    sortRows(0, leftmostNonZeroCol);
    
    // Scale top row to 1
    scaleRow(0, 1.0f / rep.at(indexOf(0, leftmostNonZeroCol)));


    // Use row ops to put zeros below the pivot position
    for (int j = 1; j < rows; j++) {
      add(j, 0, -rep.at(indexOf(j, leftmostNonZeroCol)));
    }

    // Apply steps to submatrix of rows under pivot position
    // Create submatrix excluding first row
    Matrix m = Matrix(rows-1, cols);
    std::vector<float> subVec(rep.begin() + cols, rep.end());
    m.populateWith1DVector(subVec);

    m.Echelon();
    subVec = m.Vector1D();

    // Put submatrix back into matrix
    rep.erase(rep.end() - m.Vector1D().size(), rep.end());
    
    for(int i = 0; i < m.Vector1D().size(); i++) {
      rep.push_back(m.Vector1D().at(i));
    }
  }
}
void Matrix::ReducedEchelon() {
  std::cout << "PLACEHOLDER";
}

std::vector<float> Matrix::Vector1D() {
  return rep;
}