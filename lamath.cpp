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
        void add(int r1, int r2) {
            for (int i = 0; i < n; ++i) {
                rep[r1][i] = rep[r1][i] + rep[r2][i];
            }
        }

        // Subtract r2 from r1
        // r1 = [old]r1 + r2
        void subtract(int r1, int r2) {
            for (int i = 0; i < n; ++i) {
                rep[r1][i] = rep[r1][i] - rep[r2][i];
            }
        }

        // Multiply row by scalar
        // row = [old]row * scalar
        void scaleRow(int row, int scalar) {

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

        int countLeadingZeros(int row) {
            // First value of row
            float num = rep[row][0];
            int count = 0;
            while (!compare(num, 0.0f)) { // While num is not equal to 0
                count++;
                num = rep[row][count];
            }
            return count;
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
        void a(int r1, int r2) {
            swap(r1, r2);
        }
        // Convert matrix to Echelon form
        void echelon() {

        }
        // Convert matrix to Reduced Echelon Form
        void reducedEchelon() {

        }
};

int main() {
    float array[3][3] = {{1.0f, 3.0f, 4.0f}, {1.0f, 1.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Matrix m(array, 3);

    m.a(0, 1);

    string str = m.toString();

    cout << str;
    return 0;
}