#include <iostream>
#include <cmath>
#include <stdexcept>

class S21Matrix {
    public:
        S21Matrix();                         // Default constructor
        S21Matrix(int rows, int cols);       // Parameterized constructor with number of rows and columns.
        S21Matrix(const S21Matrix& other);   // Copy constructor
        S21Matrix(S21Matrix&& other);        // Move constructor
        ~S21Matrix();                        // Destructor

        bool operator==(S21Matrix& other);
        double& operator()(int rows, int cols);
        const double& operator()(int rows, int cols) const;

        bool EqMatrix(const S21Matrix& other);      // Comparision of two matrix
        void SumMatrix(const S21Matrix& other);     // Sum of two matrix
        void SubMatrix(const S21Matrix& other);     // Subtraction of two matrix
        void MulNumber(const double num);           // Multiply the matrix by a number
        void MulMatrix(const S21Matrix& other);     // Multiplication of two matrix
        S21Matrix Transpose();                      // Matrix transpose
        S21Matrix CalcComplements();                // Matrix complements
        double Determinant();                       // Matrix determinant
        S21Matrix InverseMatrix();                  // Inverse matrix

        int GetRows(); //accessor
        int GetCols(); //accessor
        void SetRows(int new_rows); //mutator
        void SetCols(int new_cols); //mutator

    private:
        void AllocateMatrix();
        void FreeMatrix();
        bool IsEqualSize(const S21Matrix& other);

        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to the memory where the matrix is allocated
        const double EPS = 1e-6;
};