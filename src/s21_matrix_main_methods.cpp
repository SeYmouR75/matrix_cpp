#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other){
    if (!IsEqualSize(other)) return false;

    for (int i = 0; i < rows_; i++){
        for (int j = 0; j < cols_; j++){
            if(fabs(matrix_[i][j] - other.matrix_[i][j]) < EPS) return false;
        }
    }

    return true;
}

// void S21Matrix::SumMatrix(const S21Matrix& other){

// }
// void S21Matrix::SubMatrix(const S21Matrix& other){

// }
// void S21Matrix::MulNumber(const double num){

// }
// void S21Matrix::MulMatrix(const S21Matrix& other){

// }

// S21Matrix S21Matrix::Transpose(){
//     return 0;
// }

// S21Matrix S21Matrix::CalcComplements(){
//     return 0;
// }

// double S21Matrix::Determinant(){
//     return 0;
// }

// S21Matrix S21Matrix::InverseMatrix(){
//     return ;
// }
