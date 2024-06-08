#include "s21_matrix_oop.h"

void S21Matrix::AllocateMatrix(){
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++){
        matrix_[i] = new double[cols_];
        for (int j = 0; j < cols_; j++){
            matrix_[i][j] = 0;
        }
    }
}

void S21Matrix::FreeMatrix(){
    if (matrix_ != nullptr){
        for (int i = 0; i < rows_; i++){
            delete[] matrix_[i];
        }
        delete[] matrix_;
    }
    
}

bool S21Matrix::IsEqualSize(const S21Matrix& other){
    return (rows_ == other.rows_ && cols_ == other.cols_);
}