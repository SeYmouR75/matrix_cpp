#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other){
    S21Matrix Copy(*this);
    Copy.SumMatrix(other);
    return Copy;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other){
    S21Matrix Copy(*this);
    Copy.SubMatrix(other);
    return Copy;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other){
    S21Matrix Copy(*this);
    Copy.MulMatrix(other);
    return Copy;
}

S21Matrix S21Matrix::operator*(const double num){
    S21Matrix Copy(*this);
    Copy.MulNumber(num);
    return Copy;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other){
    SumMatrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other){
    SubMatrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const double num){
    MulNumber(num);
    return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other){
    MulMatrix(other);
    return *this;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other){
    if (this != &other) {
        FreeMatrix();
        rows_ = other.rows_;
        cols_ = other.cols_;
        AllocateMatrix();
    
        for (int i = 0; i < rows_; i++){
            for (int j = 0; j < cols_; j++){
                matrix_[i][j] = other.matrix_[i][j];
            }
        }
    }

    return *this;
} 

bool S21Matrix::operator==(S21Matrix& other){
    return EqMatrix(other);
}

double& S21Matrix::operator()(int rows, int cols){
    if (rows >= rows_ || rows < 0 || cols >= cols_|| cols < 0) throw std::out_of_range("Index outside the matrix");

    double& reference = matrix_[rows][cols];
    return reference;
}

const double& S21Matrix::operator()(int row, int col) const {
    if (row >= rows_ || row < 0 || col >= cols_ || col < 0) throw std::out_of_range("Index outside the matrix");
    
    return matrix_[row][col];
}