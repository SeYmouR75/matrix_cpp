#include "s21_matrix_oop.h"

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