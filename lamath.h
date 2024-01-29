#pragma once
#ifndef LAMATH_H
  #define LAMATH_H
#endif
#include <string>

using namespace std;

class Matrix {
  private:
    // Populate arr by passing in 2D array
    void populate(int *arr, int rows);
    // Adding, subtracting, scaling, and swapping rows
    void add(int r1, int r2, float scalar);
    void scaleRow(int row, float scalar);
    void swap(int r1, int r2);

  public:
    // Constructor
    Matrix(int *arr, int rows);
    std::string toString();
    void Echelon();
    void ReducedEchelon();
};