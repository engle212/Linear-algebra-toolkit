#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(float a, float b, float epsilon = 0.001f)
{
    return (fabs(a - b) < epsilon);
}

class Matrix {
    private:
        // Number of rows
        int m = 3;
        // Number of columns
        int n = 3;
        float rep[3][3];

        // Populate arr by passing in 2D array
        void populate(float arr[][3], int rows) {
            for (int i = 0; i < rows; ++i) {
                copy(arr[i], arr[i] + rows, rep[i]);
            }
        }

        // Add r2 to r1
        // r1 = [old]r1 + r2
        void add(int r1, int r2, float scalar) {
            for (int i = 0; i < n; ++i) {
                rep[r1][i] = rep[r1][i] + rep[r2][i] * scalar;
            }
        }

        // Multiply row by scalar
        // row = [old]row * scalar
        void scaleRow(int row, int scalar) {
            for (int i = 0; i < n; ++i) {
                rep[row][i] = rep[row][i] * scalar;
            }
        }

        // Swap r1 and r2
        // r1 = [old]r2
        // r2 = [old]r1
        void swap(int r1, int r2) {
            float temp[n];
            // Copy r2 to temp
            // Copy r1 to r2
            for (int i = 0; i < n; i++) {
                temp[i] = rep[r2][i];
                rep[r2][i] = rep[r1][i];
            }
            // Copy temp to r1
            for (int j = 0; j < n; j++) {
                rep[r1][j] = temp[j];
            }
        }
        
        int findSmallestRowInColumn(int column) {
            int min = 0;
            for (int i = 0; i < m; ++i) {
                if (rep[i][column] < rep[min][column]) {
                    min = i;
                }
            }
            return min;
        }
        
        float[m][n] getArray() {
            return rep;
        }

        // Get matrix excluding first row and first column
        Matrix getSubMatrix() {
            Matrix m(n-1);
        }

    public:
        // Constructor
        Matrix(float arr[][3], int rows) {
            populate(arr, rows);
        }
        string toString() {
            string str = "";
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    str += to_string(rep[i][j]);
                    if (j + 1 < m) {
                        str += ", ";
                    } else {
                        str += "\n";
                    }
                }
            }
            return str;
        }
        // Convert matrix to Echelon form
        void echelon() {
            for (int i = 0; i < n; ++i) {
                int pivotRow = findSmallestRowInColumn(i);

                // Scale smallest row to 1
                float scaleFactor = 1.0f / rep[pivotRow][i];
                scaleRow(pivotRow, scaleFactor);

                // Add to get other elements in column to be zero
                
            }
        }
        // Convert matrix to Reduced Echelon Form
        void reducedEchelon() {

        }
};

int main() {
    float array[3][3] = {{1.0f, 3.0f, 4.0f}, {1.0f, 1.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Matrix m(array, 3);

    m.echelon();

    string str = m.toString();

    cout << str;
    return 0;
}