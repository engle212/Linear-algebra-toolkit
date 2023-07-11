#pragma once

template <class T> class Matrix {
    private:
        // Populate arr by passing in 2D array
        void populate(T arr[][]);
        // Adding, scaling, and swapping rows
        void addTo(int r1, int r2);
        void scaleRow(int row, int scalar);
        void swap(int r1, int r2);

    public:
        // Constructor
        Matrix(T arr[][]);
        Echelon();
        ReducedEchelon();

};