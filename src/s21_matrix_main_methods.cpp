#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (!IsEqualSize(other)) return false;
  bool result = true;

  if (matrix_ != nullptr && other.matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS) {
          result = false;
          break;
        }
      }
    }
  } else
    result = false;

  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (!IsEqualSize(other))
    throw std::invalid_argument("Different matrix dimensionality");
  if (matrix_ == nullptr || other.matrix_ == nullptr)
    throw std::invalid_argument("Empty matrix");

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!IsEqualSize(other))
    throw std::invalid_argument("Different matrix dimensionality");
  if (matrix_ == nullptr || other.matrix_ == nullptr)
    throw std::invalid_argument("Empty matrix");

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (matrix_ == nullptr) throw std::invalid_argument("Empty matrix");

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (matrix_ == nullptr || other.matrix_ == nullptr)
    throw std::invalid_argument("Empty matrix");
  if (cols_ != other.rows_)
    throw std::invalid_argument(
        "The number of columns of the first matrix is not equal to the number "
        "of rows of the second matrix");

  S21Matrix Result(rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        Result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  *this = std::move(Result);
}

S21Matrix S21Matrix::Transpose() {
  if (matrix_ == nullptr) throw std::invalid_argument("Empty matrix");

  S21Matrix Result(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      Result.matrix_[j][i] = matrix_[i][j];
    }
  }

  return Result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (matrix_ == nullptr) throw std::invalid_argument("Empty matrix");
  if (rows_ != cols_) throw std::invalid_argument("The matrix is not square.");

  S21Matrix Result(rows_, cols_);

  if (rows_ == 1) {
    Result.matrix_[0][0] = matrix_[0][0];
  } else {
    int sign = 0;

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix Sub = SplitToSub(i, j);
        sign = ((i + j) % 2 == 0) ? 1 : -1;
        Result.matrix_[i][j] = Sub.Determinant() * sign;
      }
    }
  }

  return Result;
}

double S21Matrix::Determinant() {
  if (matrix_ == nullptr) throw std::invalid_argument("Empty matrix");
  if (rows_ != cols_) throw std::invalid_argument("The matrix is not square.");

  double result = 0;

  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    int sign = 1;

    for (int i = 0; i < rows_; i++) {
      S21Matrix Sub = SplitToSub(0, i);
      double rec_det = Sub.Determinant();
      result += sign * matrix_[0][i] * rec_det;
      sign *= -1;
    }
  }

  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (matrix_ == nullptr) throw std::invalid_argument("Empty matrix");
  if (rows_ != cols_) throw std::invalid_argument("The matrix is not square.");

  double det = Determinant();

  if (det == 0) throw std::invalid_argument("Determinant is equal zero");

  S21Matrix Minor = CalcComplements();
  S21Matrix Result = Minor.Transpose();

  for (int i = 0; i < Result.rows_; i++) {
    for (int j = 0; j < Result.cols_; j++) {
      Result.matrix_[i][j] = 1 / det * Result.matrix_[i][j];
    }
  }

  return Result;
}
