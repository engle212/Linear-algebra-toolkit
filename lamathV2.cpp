#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

//using namespace std;

bool compare(float a, float b, float epsilon = 0.0001f) {
    return (fabs(a - b) < epsilon);
}

class Matrix {
    private:
        std::vector<float> matrix;
        int rows;
        int columns;
        void setDim(int m, int n) {
            rows = m;
            columns = n;
            matrix.resize(rows*columns, '0');
        }
        
    public:
        Matrix(int m, int n) {
            // Set dimensions of matrix
            setDim(m, n);
        }
        Matrix(std::vector<std::vector<float>> &vect) {
            // Set dimensions of matrix
            setDim(vect.size(), vect.at(0).size());
            // Load vector values into matrix
            for (int i = 0; i < matrix.size(); i++) {
                int c = i % columns;
                // Set matrix at position i to value from 2D vector
                matrix[i] = vect.at((i - c) / columns).at(c);
            }
        }
        std::string toString() {
            std::string str = "{";
            // Cycle through matrix and display values
            for (int i = 0; i < matrix.size(); i++) {
                if (i != 0 && i % columns == 0) {
                    str += "}\n{";
                }
                str += "[" + std::to_string(matrix.at(i)) + "]";
            }
            str +="}";
            return str;
        }
        std::pair<int, int> getDim() {
            return std::make_pair(rows, columns);
        }
};

int main() {
    std::vector<std::vector<float>> v = {{1.0f, 3.0f, 4.0f}, {1.0f, 1.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Matrix m(v);

    //m.echelon();

    std::string str = m.toString();
    std::cout << str;
    return 0;
}