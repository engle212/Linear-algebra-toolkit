#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(float a, float b, float epsilon = 0.0001f) {
    return (fabs(a - b) < epsilon);
}

class Matrix {
    private:
        string matrix;
        int rows;
        int columns;
        void setDim(int m, int n) {
            rows = m;
            columns = n;
            matrix.resize(rows*columns, '0');
        }
        pair<int, int> getDim() {
            return make_pair(rows, columns);
        }
    public:
        Matrix(int m, int n) {
            // Set dimensions of matrix
            setDim(m, n);
        }
        Matrix(int m, int n, vector< vector<int> > &vect) {
            // Set dimensions of matrix
            setDim(m, n);
            // Load vector values into matrix string
            for (int i = 0; i < matrix.length(); i++) {
                
            }
        }
}