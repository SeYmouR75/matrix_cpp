#include "s21_matrix_oop.h"

void S21Matrix::AllocateMatrix(){
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++){
        matrix_[i] = new double[cols_];
    }
}

void S21Matrix::FreeMatrix(){
    for (int i = 0; i < rows_; i++){
        delete[] matrix_[i];
    }
    delete[] matrix_;
}