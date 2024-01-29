#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

bool compare(float a, float b, float epsilon = 0.0001f) {
    return (fabs(a - b) < epsilon);
}

class Matrix {
  private:
    std::vector<float> rep;
    int rows;
    int cols;
    // Populate arr by passing in 2D array
    void populate(int *arr, int rows) {

    }

    // r1 = [old]r1 + scalar * r2
    void add(int r1, int r2, float scalar) {
      
    }

    // row = [old]row * scalar
    void scaleRow(int row, float scalar) {

    }

    // r1 = [old]r2
    // r2 = [old]r1
    void swap(int r1, int r2) {

    }

  public:
    // Constructor
    Matrix(int *arr, int rows) {

    }
    std::string toString() {

    }
    void Echelon() {

    }
    void ReducedEchelon() {

    }
}