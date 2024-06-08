#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other){
    if (!IsEqualSize(other)) return false;
    bool result = true;

    if (matrix_ != nullptr && other.matrix_ != nullptr){
        for (int i = 0; i < rows_; i++){
            for (int j = 0; j < cols_; j++){
                if (fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS){
                    result = false;
                    break;
                }
            }
        }
    } else result = false;

    return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other){
    if (!IsEqualSize(other)) throw std::invalid_argument("different matrix dimensionality");
    if (matrix_ == nullptr || other.matrix_ == nullptr) throw std::invalid_argument("empty pointer");


    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] += other.matrix_[i][j];
        }
    }
}

void S21Matrix::SubMatrix(const S21Matrix& other){
    if (!IsEqualSize(other)) throw std::invalid_argument("different matrix dimensionality");
    if (matrix_ == nullptr || other.matrix_ == nullptr) throw std::invalid_argument("empty pointer");

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] -= other.matrix_[i][j];
        }
    }

}
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
