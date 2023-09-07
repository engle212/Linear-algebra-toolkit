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
            rep.resize(rows*cols, '0');
        }


        // Return index of smallest row in a given column
        //int findSmallestRowInColumn(int column) {
            //float min = rep.at(0).at(column);
            //int minIdx = 0;
            //for (int i = 0; i < rows; i++) {
            //    float curr = rep.at(i).at(column);
            //    if (curr < min) {
            //        min = curr;
            //        minIdx = i;
            //    }
            //}
            //return minIdx;
        //}
        
    public:
        Matrix(int m, int n) {
            // Set dimensions of rep
            setDim(m, n);
        }
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
        
        // Return dimensions of rep
        std::pair<int, int> getDim() {
            return std::make_pair(rows, cols);
        }

        // Convert rep to Echelon form
        void echelon() {
            
        }
        // Add r2 to r1
        // r1 = [old]r1 + scalar * r2
        void add(int r1, int r2, float scalar) {
            int dif = r2 - r1;
            for (int i = (r1 * cols); i < (r1 * cols + cols); i++) {
                rep.at(i) = rep.at(i) + scalar * rep.at(i + dif*cols);
            }
        }
};

int main() {
    std::vector<std::vector<float>> v = {{1.0f, 3.0f, 4.0f}, {1.0f, 1.0f, 0.0f}, {2.0f, 2.0f, 2.0f}};
    Matrix m(v);

    m.add(1, 2, -0.5f);
    //m.echelon();

    std::string str = m.toString();
    std::cout << str;
    return 0;
}