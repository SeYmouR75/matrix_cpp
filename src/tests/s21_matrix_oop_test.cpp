#include "s21_matrix_oop_test.h"

#include <time.h>

void FillMatrixRandom(S21Matrix& Matrix) {
  for (int i = 0; i < Matrix.GetRows(); ++i) {
    for (int j = 0; j < Matrix.GetCols(); ++j) {
      Matrix(i, j) = rand();
    }
  }
}

int main(int argc, char** argv) {
  srand((long int)&argc + (long int)&argv);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}