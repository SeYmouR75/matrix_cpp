#include "s21_matrix_oop.h"

void S21Matrix::AllocateMatrix() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

void S21Matrix::FreeMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

bool S21Matrix::IsEqualSize(const S21Matrix& other) {
  return (rows_ == other.rows_ && cols_ == other.cols_);
}

S21Matrix S21Matrix::SplitToSub(int row_to_skip, int col_to_skip) {
  int row = 0, col = 0;

  S21Matrix Sub(rows_ - 1, cols_ - 1);

  for (int i = 0; i < rows_; i++) {
    if (i != row_to_skip) {
      for (int j = 0; j < cols_; j++) {
        if (j != col_to_skip) {
          Sub.matrix_[row][col] = matrix_[i][j];
          col++;
        }
      }
      row++;
      col = 0;
    }
  }

  return Sub;
}