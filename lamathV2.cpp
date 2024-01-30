#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

//using namespace std;

bool compare(float a, float b, float epsilon = 0.0001f) {
    return (fabs(a - b) < epsilon);
}

//class Matrix {
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

        // Find leftmost non-zero column
        int findPivotColumn() {
            //float min = rep.at(row*cols);
            //int minIdx = row*cols;
            
            // Iterate through columns until column is non-zero
            int i = 0;
            int colIdx = -1; // Negative only when non-zero column has not been found
            
            while (colIdx < 0 && i < cols) {
                // Check each value in column
                for (int j = 0; j < rows; j++) {
                    // Get value in the column
                    float currVal = rep.at(j*cols);
                    // Check if non-zero
                    if (!compare(currVal, 0)) {
                        colIdx = i;
                    }
                }
                i++;
            }
            return colIdx;
        }

        // Return index of row where num is in the given column col. If none, return negative
        int findNumInColumn(int col, int num) {
            // Iterate through columns until column is non-zero
            int i = 0;
            int rowIdx = -1; // Negative only when non-zero column has not been found

            // Iterate through col until one found or out of rows
            /*
            while (rowIdx < 0 && i < rows) {
                // Check each value in column
                for (int j = 0; j < rows; j++) {
                    // Get value in the column
                    float currVal = rep.at(j*cols);
                    // Check if non-zero
                    if (!compare(currVal, 0)) {
                        rowIdx = i;
                    }
                }
                i++;
            }
            */
            return rowIdx;
        }
        
        // Return rep, excluding first row and first column
        Matrix getInnerMatrix() {
            // Copy rep
            std::vector<float> repCopy = rep;

            // Remove first row
            repCopy.erase(repCopy.begin(), repCopy.begin() + cols);

            // Construct new Matrix
            Matrix newMatrix(repCopy, rows - 1, cols);

            return newMatrix;
        }

        // Return sum of absolute values in matrix
        float getAbsoluteValueSum() {
            float sum = 0.0f;
            for (int i = 0; i < rows*cols; i++) {
                sum += fabs(rep.at(i));
            }
            return sum;
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
            for (unsigned int i = 0; i < rep.size(); i++) {
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
            for (unsigned int i = 0; i < rep.size(); i++) {
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

        // Convert rep to Reduced Row Echelon form
        void echelon() {
            // Check if matrix is empty, or 1 row
            if (compare(getAbsoluteValueSum(), 0.0f, 0.000001)) {
                // Do nothing
            } else if (rows == 1) {
                // Scale values in row
                scaleRow(0, 1.0f / rep.at(0));
            } else {
                // Determine left-most non-zero column
                int pivCol = findPivotColumn();
                // Move a 1 to topmost row (if no 1, make a 1)


                // Put 0s below topmost row

                // If no more non-zero rows, skip recursion

                // Done!

                // Determine pivot row
                int pivRow = findPivotRow();

                // Ensure pivot row is first row in matrix
                if (pivRow != 0) {
                    swap(pivRow, 0);
                }

                float pivCol = findPivotColumn();

                // Scale pivot row so first num is 1
                scaleRow(0, 1.0f / pivNum);

                // Subtract pivot row from all other rows
                for (int i = 1; i < rows; i++) {
                    float factor = rep.at(0) / rep.at(i * cols);
                    add(i, 0, factor);
                }

                // Ensure recursion is possible
                if (cols > 1) {
                    // Recursively perform echelon function on inner matrix
                    Matrix innerMatrix = getInnerMatrix();
                    innerMatrix.reducedEchelon();

                    std::vector<float> innerVect = innerMatrix.getVector();
                    
                    std::cout << getDim().first << "__" << getDim().second << ": dim\n";

                    // Overwrite overall matrix with reduced inner matrix
                    // Start with second row
                    for (int j = cols; j < (rows * cols); ++j) {
                        rep.at(j) = innerVect.at(j - cols);
                        std::cout << j << ">>" << j - cols << "\n";
                    }
                }
            }
        }
};

int main() {
    std::vector<std::vector<float>> v = {{1, 2, 3, -1}, {4, 5, 6, 3}, {7, 8, 9, 5}};
    Matrix m(v);

    m.echelon();

    std::string str = m.toString();
    std::cout << str;
    return 0;
}