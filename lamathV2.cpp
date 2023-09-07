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
        std::vector<float> rep;
        int rows;
        int cols;
        void setDim(int m, int n) {
            rows = m;
            cols = n;
            rep.resize(rows*cols, 0);
        }

        // Add r2 to r1
        // r1 = [old]r1 + scalar * r2
        void add(int r1, int r2, float scalar) {
            int dif = r2 - r1;
            for (int i = (r1 * cols); i < (r1 * cols + cols); i++) {
                rep.at(i) = rep.at(i) + scalar * rep.at(i + dif*cols);
            }
        }

        // Multiply row by scalar
        // row = [old]row * scalar
        void scaleRow(int row, float scalar) {
            for (int i = (row * cols); i < (row * cols + cols); i++) {
                rep.at(i) = rep.at(i) * scalar;
            }
        }

        // Swap r1 and r2
        // r1 = [old]r2
        // r2 = [old]r1
        void swap(int r1, int r2) {
            std::vector<float> temp;
            temp.resize(cols, 0);
            // Copy r2 to temp
            // Copy r1 to r2
            for (int i = 0; i < cols; i++) {
                temp.at(i) = rep.at(i + r2 * cols);
                rep.at(i + r2 * cols) = rep.at(i + r1 * cols);
            }
            // Copy temp to r1
            for (int j = 0; j < cols; j++) {
                rep.at(j + r1 * cols) = temp.at(j);
            }
        }

        // Return index of smallest nonzero row in a given column
        int findPivotRow(int column) {
            float min = rep.at(column); // Set min to first row of column
            int minIdx = column;
            for (int i = 0; i < rows; i++) {
                float curr = rep.at(column + cols * i);
                if (!compare(curr, 0) && curr < min) {
                    min = curr;
                    minIdx = column + cols * i;
                }
            }
            return minIdx;
        }

        // Return rep, excluding first row and first column
        Matrix getInnerMatrix() {
            // Copy rep
            std::vector<float> repCopy = rep;

            // Remove first row
            repCopy.erase(repCopy.begin(), repCopy.begin() + cols);

            // Remove first column
            for (int i = 0; i < rows; i = i + cols - 1) {
                repCopy.erase(repCopy.begin()+i);
            }
            
            // Construct new Matrix
            Matrix newMatrix(repCopy, rows - 1, cols - 1);

            return newMatrix;
        }
        
    public:
        // Construct empty matrix
        Matrix(int m, int n) {
            // Set dimensions of rep
            setDim(m, n);
        }

        // Construct matrix from 2D vector
        Matrix(std::vector<std::vector<float>> &vect) {
            // Set dimensions of rep
            setDim(vect.size(), vect.at(0).size());
            // Load vector values into rep
            for (int i = 0; i < rep.size(); i++) {
                int c = i % cols;
                // Set rep at position i to value from 2D vector
                rep[i] = vect.at((i - c) / cols).at(c);
            }
        }

        // Construct matrix from 1D vector
        Matrix(std::vector<float> &vect, int m, int n) {
            setDim(m, n);
            rep = vect;
        }

        // Return string representation of rep
        std::string toString() {
            std::string str = "{";
            // Cycle through rep and display values
            for (int i = 0; i < rep.size(); i++) {
                if (i != 0 && i % cols == 0) {
                    str += "}\n{";
                }
                str += "[" + std::to_string(rep.at(i)) + "]";
            }
            str +="}";
            return str;
        }

        // Return vector containing contents of matrix
        std::vector<float> getVector() {
            return rep;
        }
        
        // Return dimensions of rep
        std::pair<int, int> getDim() {
            return std::make_pair(rows, cols);
        }

        // Convert rep to Echelon form
        void echelon() {
            // Determine pivot row
            int pivRow = findPivotRow(0);

            // Ensure pivot row is first row in matrix
            if (pivRow != 0) {
                swap(pivRow, 0);
            }
            // Scale pivot row so first num is 1
            scaleRow(0, 1.0f / rep.at(0));

            // Subtract pivot row from all other rows
            for (int i = 1; i < rows; i++) {
                float factor = rep.at(0) / rep.at(i * cols);
                add(i, 0, factor);
            }
            
            // Recursively perform echelon function on inner matrix
            Matrix innerMatrix = getInnerMatrix();
            innerMatrix.echelon();
            std::vector<float> innerVect = innerMatrix.getVector();

            // Overwrite overall matrix with inner matrix echelon
            // Start with second row
            for (int j = (cols + 1); j < (rows * cols); j++) {
                // Ensure not in first column
                if (j % cols != 0) {
                    rep.at(j) = innerVect.at(j - cols - 1);
                }
            }
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