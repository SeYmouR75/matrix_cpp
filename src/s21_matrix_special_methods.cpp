#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 0 || cols < 0) throw std::out_of_range("Incorrect matrix size");

  AllocateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  AllocateMatrix();

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  FreeMatrix();
  rows_ = 0;
  cols_ = 0;
}

int S21Matrix::GetRows() { return rows_; }
int S21Matrix::GetCols() { return cols_; }
void S21Matrix::SetRows(int new_rows) {
  if (new_rows < 0) throw std::logic_error("Incorrect number");

  S21Matrix New(new_rows, cols_);

  int min = rows_ > new_rows ? new_rows : rows_;

  for (int i = 0; i < min; i++) {
    for (int j = 0; j < cols_; j++) {
      New.matrix_[i][j] = matrix_[i][j];
    }
  }

  *this = std::move(New);
}
void S21Matrix::SetCols(int new_cols) {
  if (new_cols < 0) throw std::logic_error("Incorrect number");

  S21Matrix New(rows_, new_cols);

  int min = cols_ > cols_ ? cols_ : cols_;

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < min; j++) {
      New.matrix_[i][j] = matrix_[i][j];
    }
  }

  *this = std::move(New);
}