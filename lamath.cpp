#include "lamath.h"

template <class T> class Matrix {
    private:
        int m;
        int n;
        T rep[m][n];
        // Populate arr by passing in 2D array
        void populate(T arr[][]) {
            rep = arr;
        }

        // Add r2 to r1
        // r1 = [old]r1 + r2
        void addTo(int r1, int r2) {
            
        }

        // Multiply row by scalar
        // row = [old]row * scalar
        void scaleRow(int row, int scalar) {

        }

        // Swap r1 and r2
        // r1 = [old]r2
        // r2 = [old]r1
        void swap(int r1, int r2) {

        }

    public:
        // Constructor
        Matrix(T arr[][]) {

        }
        // Convert matrix to Echelon form
        Echelon() {

        }
        // Convert matrix to Reduced Echelon Form
        ReducedEchelon() {

        }

};