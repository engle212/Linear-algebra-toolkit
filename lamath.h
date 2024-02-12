#pragma once
#ifndef LAMATH_H
  #define LAMATH_H
#endif
#include <string>
#include <vector>


using namespace std;

class Matrix {
  private:
    std::vector<float> rep;
    int rows;
    int cols;
    void setDim(int m, int n);
    int indexOf(int r, int c);
    int rowOf(int i);
    int columnOf(int i);
    int minRow(int firstRow, int col);
    void sortRows(int firstRow, int col);
    // Adding, subtracting, scaling, and swapping rows
    void add(int r1, int r2, float scalar);
    void scaleRow(int row, float scalar);
    void swap(int r1, int r2);
    bool isZero(int col);

  public:
    // Constructors
    Matrix(int m, int n);
    Matrix(int *arr, int r, int c);
    std::string toString();
    void populateWith1DVector(std::vector<float> vector);
    void Echelon();
    void ReducedEchelon();
    std::vector<float> Vector1D();
};