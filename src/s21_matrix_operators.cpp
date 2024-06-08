#include "s21_matrix_oop.h"

double& S21Matrix::operator()(int rows, int cols){
    if (rows >= rows_ || rows < 0 || cols >= cols_|| cols < 0) throw std::invalid_argument("Index outside the matrix");

    double& reference = matrix_[rows][cols];
    return reference;
}

