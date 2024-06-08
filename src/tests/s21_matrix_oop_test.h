#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

void FillMatrixRandom(S21Matrix& Matrix);

TEST(ConstructorTest, DefaultConstructor) {
  S21Matrix Matrix;
  EXPECT_EQ(Matrix.GetRows(), 0);
  EXPECT_EQ(Matrix.GetCols(), 0);
}

TEST(ConstructorTest, ParameterizedConstructor_1) {
  S21Matrix Matrix{1, 10};
  EXPECT_EQ(Matrix.GetRows(), 1);
  EXPECT_EQ(Matrix.GetCols(), 10);
  for (int i = 0; i < Matrix.GetRows(); ++i) {
    for (int j = 0; j < Matrix.GetCols(); ++j) {
      EXPECT_EQ(Matrix(i, j), 0);
    }
  }
}

TEST(ConstructorTest, ParameterizedConstructor_2) {
  S21Matrix Matrix{0, 0};
  EXPECT_EQ(Matrix.GetRows(), 0);
  EXPECT_EQ(Matrix.GetCols(), 0);
}

TEST(ConstructorTest, ParameterizedConstructor_3) {
  EXPECT_THROW(S21Matrix Matrix(-4, 2), std::out_of_range);
}

TEST(ConstructorTest, CopyConstructor_1) {
  S21Matrix reference{5, 5};
  FillMatrixRandom(reference);
  S21Matrix Copy(reference);
  EXPECT_TRUE(reference.EqMatrix(Copy));
}

TEST(ConstructorTest, CopyConstructor_2) {
  S21Matrix reference{0, 0};
  S21Matrix Copy(reference);
  EXPECT_TRUE(reference.EqMatrix(Copy));
}

TEST(ConstructorTest, MoveConstructor_1) {
  S21Matrix reference{3, 5};
  FillMatrixRandom(reference);
  S21Matrix Copy{std::move(reference)};
  EXPECT_FALSE(Copy.EqMatrix(reference));
}

TEST(ConstructorTest, MoveConstructor_2) {
  S21Matrix reference{};
  S21Matrix Copy{std::move(reference)};
  EXPECT_FALSE(Copy.EqMatrix(reference));
}

// TEST(ArithmeticsTest, SumMatrix_1) {
//   S21Matrix summand_1(3, 3);
//   S21Matrix summand_2(3, 3);
//   S21Matrix result(3, 3);

//   summand_1(0, 0) = 6;
//   summand_1(0, 1) = 45.1;
//   summand_1(0, 2) = -3.321;
//   summand_1(1, 0) = 0;
//   summand_1(1, 1) = 0;
//   summand_1(1, 2) = 4;
//   summand_1(2, 0) = -0.0005;
//   summand_1(2, 1) = 321.43;
//   summand_1(2, 2) = -898;

//   summand_2(0, 0) = 2;
//   summand_2(0, 1) = -43.2;
//   summand_2(0, 2) = 32.2;
//   summand_2(1, 0) = 12;
//   summand_2(1, 1) = 21.3;
//   summand_2(1, 2) = 2;
//   summand_2(2, 0) = 0;
//   summand_2(2, 1) = 0.0007;
//   summand_2(2, 2) = 45.04;

//   result(0, 0) = 8;
//   result(0, 1) = 1.9;
//   result(0, 2) = 28.879;
//   result(1, 0) = 12;
//   result(1, 1) = 21.3;
//   result(1, 2) = 6;
//   result(2, 0) = -0.0005;
//   result(2, 1) = 321.4307;
//   result(2, 2) = -852.96;

//   summand_1.SumMatrix(summand_2);
//   EXPECT_TRUE(summand_1 == result);
// }

// TEST(ArithmeticsTest, SumMatrix_2) {
//   S21Matrix summand_1(2, 2);
//   S21Matrix summand_2(2, 2);
//   S21Matrix result(2, 2);

//   summand_1(0, 0) = 1;
//   summand_1(0, 1) = 2;
//   summand_1(1, 0) = 3;
//   summand_1(1, 1) = 4;

//   summand_2(0, 0) = 5;
//   summand_2(0, 1) = 6;
//   summand_2(1, 0) = 7;
//   summand_2(1, 1) = 8;

//   result(0, 0) = 6;
//   result(0, 1) = 8;
//   result(1, 0) = 10;
//   result(1, 1) = 12;

//   summand_1.SumMatrix(summand_2);
//   EXPECT_TRUE(summand_1 == result);
// }

// TEST(ArithmeticsTest, SumMatrix_3) {
//   S21Matrix summand_1(5, 5);
//   S21Matrix summand_2(5, 5);
//   S21Matrix result(5, 5);

//   summand_1(0, 0) = 1.5;
//   summand_1(0, 1) = -2.7;
//   summand_1(0, 2) = 3.9;
//   summand_1(0, 3) = 4.2;
//   summand_1(0, 4) = -5.1;

//   summand_2(0, 0) = 2.3;
//   summand_2(0, 1) = 1.8;
//   summand_2(0, 2) = -3.2;
//   summand_2(0, 3) = -4.5;
//   summand_2(0, 4) = 6.7;

//   result(0, 0) = 3.8;
//   result(0, 1) = -0.9;
//   result(0, 2) = 0.7;
//   result(0, 3) = -0.3;
//   result(0, 4) = 1.6;

//   summand_1.SumMatrix(summand_2);
//   EXPECT_TRUE(summand_1 == result);
// }

// TEST(ArithmeticsTest, SumMatrix_4) {
//   S21Matrix summand_1(3, 3);
//   S21Matrix summand_2(3, 3);
//   S21Matrix result(3, 3);

//   summand_1(0, 0) = 1.0;
//   summand_1(0, 1) = 2.0;
//   summand_1(0, 2) = 3.0;
//   summand_1(1, 0) = -4.0;
//   summand_1(1, 1) = -5.0;
//   summand_1(1, 2) = -6.0;
//   summand_1(2, 0) = 7.0;
//   summand_1(2, 1) = 8.0;
//   summand_1(2, 2) = 9.0;

//   summand_2(0, 0) = -1.0;
//   summand_2(0, 1) = -2.0;
//   summand_2(0, 2) = -3.0;
//   summand_2(1, 0) = 4.0;
//   summand_2(1, 1) = 5.0;
//   summand_2(1, 2) = 6.0;
//   summand_2(2, 0) = -7.0;
//   summand_2(2, 1) = -8.0;
//   summand_2(2, 2) = -9.0;

//   result(0, 0) = 0.0;
//   result(0, 1) = 0.0;
//   result(0, 2) = 0.0;
//   result(1, 0) = 0.0;
//   result(1, 1) = 0.0;
//   result(1, 2) = 0.0;
//   result(2, 0) = 0.0;
//   result(2, 1) = 0.0;
//   result(2, 2) = 0.0;

//   summand_1.SumMatrix(summand_2);
//   EXPECT_TRUE(summand_1 == result);
// }

// TEST(ArithmeticsTest, SumMatrix_5) {
//   S21Matrix summand_1(9, 9);
//   S21Matrix summand_2(9, 9);
//   S21Matrix result(9, 9);

//   for (int i = 0; i < 9; ++i) {
//     for (int j = 0; j < 9; ++j) {
//       summand_1(i, j) = i + j;
//       summand_2(i, j) = i - j;
//       result(i, j) = summand_1(i, j) + summand_2(i, j);
//     }
//   }

//   summand_1.SumMatrix(summand_2);
//   EXPECT_TRUE(summand_1 == result);
// }

// TEST(ArithmeticsTest, SumMatrix_6) {
//   S21Matrix summand_1(2, 9);
//   S21Matrix summand_2(9, 9);

//   EXPECT_THROW(summand_1.SumMatrix(summand_2), std::invalid_argument);
// }

// TEST(ArithmeticsTest, SubMatrix_1) {
//   S21Matrix minuend(3, 3);
//   S21Matrix subtrahend(3, 3);
//   S21Matrix result(3, 3);

//   minuend(0, 0) = 6;
//   minuend(0, 1) = 45.1;
//   minuend(0, 2) = -3.321;
//   minuend(1, 0) = 0;
//   minuend(1, 1) = 0;
//   minuend(1, 2) = 4;
//   minuend(2, 0) = -0.0005;
//   minuend(2, 1) = 321.43;
//   minuend(2, 2) = -898;

//   subtrahend(0, 0) = 2;
//   subtrahend(0, 1) = -43.2;
//   subtrahend(0, 2) = 32.2;
//   subtrahend(1, 0) = 12;
//   subtrahend(1, 1) = 21.3;
//   subtrahend(1, 2) = 2;
//   subtrahend(2, 0) = 0;
//   subtrahend(2, 1) = 0.0007;
//   subtrahend(2, 2) = 45.04;

//   result(0, 0) = 4;
//   result(0, 1) = 88.3;
//   result(0, 2) = -35.521;
//   result(1, 0) = -12;
//   result(1, 1) = -21.3;
//   result(1, 2) = 2;
//   result(2, 0) = -0.0005;
//   result(2, 1) = 321.4293;
//   result(2, 2) = -943.04;

//   minuend.SubMatrix(subtrahend);
//   EXPECT_TRUE(minuend == result);
// }

// TEST(ArithmeticsTest, SubMatrix_2) {
//   S21Matrix minuend(2, 2);
//   S21Matrix subtrahend(2, 2);
//   S21Matrix result(2, 2);

//   minuend(0, 0) = 10;
//   minuend(0, 1) = 20;
//   minuend(1, 0) = 30;
//   minuend(1, 1) = 40;

//   subtrahend(0, 0) = 1;
//   subtrahend(0, 1) = 2;
//   subtrahend(1, 0) = 3;
//   subtrahend(1, 1) = 4;

//   result(0, 0) = 9;
//   result(0, 1) = 18;
//   result(1, 0) = 27;
//   result(1, 1) = 36;

//   minuend.SubMatrix(subtrahend);
//   EXPECT_TRUE(minuend == result);
// }

// TEST(ArithmeticsTest, SubMatrix_3) {
//   S21Matrix minuend(4, 4);
//   S21Matrix subtrahend(4, 4);
//   S21Matrix result(4, 4);

//   minuend(0, 0) = 10;
//   minuend(0, 1) = 20;
//   minuend(0, 2) = 30;
//   minuend(0, 3) = 40;
//   minuend(1, 0) = 50;
//   minuend(1, 1) = 60;
//   minuend(1, 2) = 70;
//   minuend(1, 3) = 80;
//   minuend(2, 0) = 90;
//   minuend(2, 1) = 100;
//   minuend(2, 2) = 110;
//   minuend(2, 3) = 120;
//   minuend(3, 0) = 130;
//   minuend(3, 1) = 140;
//   minuend(3, 2) = 150;
//   minuend(3, 3) = 160;

//   subtrahend(0, 0) = 1;
//   subtrahend(0, 1) = 2;
//   subtrahend(0, 2) = 3;
//   subtrahend(0, 3) = 4;
//   subtrahend(1, 0) = 5;
//   subtrahend(1, 1) = 6;
//   subtrahend(1, 2) = 7;
//   subtrahend(1, 3) = 8;
//   subtrahend(2, 0) = 9;
//   subtrahend(2, 1) = 10;
//   subtrahend(2, 2) = 11;
//   subtrahend(2, 3) = 12;
//   subtrahend(3, 0) = 13;
//   subtrahend(3, 1) = 14;
//   subtrahend(3, 2) = 15;
//   subtrahend(3, 3) = 16;

//   result(0, 0) = 9;
//   result(0, 1) = 18;
//   result(0, 2) = 27;
//   result(0, 3) = 36;
//   result(1, 0) = 45;
//   result(1, 1) = 54;
//   result(1, 2) = 63;
//   result(1, 3) = 72;
//   result(2, 0) = 81;
//   result(2, 1) = 90;
//   result(2, 2) = 99;
//   result(2, 3) = 108;
//   result(3, 0) = 117;
//   result(3, 1) = 126;
//   result(3, 2) = 135;
//   result(3, 3) = 144;

//   minuend.SubMatrix(subtrahend);
//   EXPECT_TRUE(minuend == result);
// }

// TEST(ArithmeticsTest, SubMatrix_4) {
//   S21Matrix minuend(2, 2);
//   S21Matrix subtrahend(2, 2);
//   S21Matrix result(2, 2);

//   minuend(0, 0) = 1.5;
//   minuend(0, 1) = -2.0;
//   minuend(1, 0) = 3.25;
//   minuend(1, 1) = 4.75;

//   subtrahend(0, 0) = 1.0;
//   subtrahend(0, 1) = 2.5;
//   subtrahend(1, 0) = -3.0;
//   subtrahend(1, 1) = 1.25;

//   result(0, 0) = 0.5;
//   result(0, 1) = -4.5;
//   result(1, 0) = 6.25;
//   result(1, 1) = 3.5;

//   minuend.SubMatrix(subtrahend);
//   EXPECT_TRUE(minuend == result);
// }

// TEST(ArithmeticsTest, SubMatrix_5) {
//   S21Matrix minuend(4, 4);
//   S21Matrix subtrahend(4, 4);
//   S21Matrix result(4, 4);

//   minuend(0, 0) = 1.5;
//   minuend(0, 1) = -2.0;
//   minuend(0, 2) = 3.25;
//   minuend(0, 3) = 4.75;
//   minuend(1, 0) = -1.0;
//   minuend(1, 1) = 2.5;
//   minuend(1, 2) = -3.0;
//   minuend(1, 3) = 1.25;
//   minuend(2, 0) = 2.0;
//   minuend(2, 1) = -3.5;
//   minuend(2, 2) = 4.0;
//   minuend(2, 3) = -5.25;
//   minuend(3, 0) = -2.5;
//   minuend(3, 1) = 3.0;
//   minuend(3, 2) = -4.5;
//   minuend(3, 3) = 5.75;

//   subtrahend(0, 0) = -1.5;
//   subtrahend(0, 1) = -2.5;
//   subtrahend(0, 2) = -3.25;
//   subtrahend(0, 3) = -4.75;
//   subtrahend(1, 0) = -1.0;
//   subtrahend(1, 1) = -2.5;
//   subtrahend(1, 2) = -3.0;
//   subtrahend(1, 3) = -1.25;
//   subtrahend(2, 0) = -2.0;
//   subtrahend(2, 1) = 3.5;
//   subtrahend(2, 2) = -4.0;
//   subtrahend(2, 3) = -5.25;
//   subtrahend(3, 0) = -2.5;
//   subtrahend(3, 1) = -3.0;
//   subtrahend(3, 2) = -4.5;
//   subtrahend(3, 3) = -5.75;

//   result(0, 0) = 3.0;
//   result(0, 1) = 0.5;
//   result(0, 2) = 6.5;
//   result(0, 3) = 9.5;
//   result(1, 0) = 0.0;
//   result(1, 1) = 5.0;
//   result(1, 2) = 0.0;
//   result(1, 3) = 2.5;
//   result(2, 0) = 4.0;
//   result(2, 1) = -7.0;
//   result(2, 2) = 8.0;
//   result(2, 3) = 0.0;
//   result(3, 0) = 0.0;
//   result(3, 1) = 6.0;
//   result(3, 2) = 0.0;
//   result(3, 3) = 11.5;

//   minuend.SubMatrix(subtrahend);
//   EXPECT_TRUE(minuend == result);
// }

// TEST(ArithmeticsTest, SubMatrix_6) {
//   S21Matrix summand_1(2, 9);
//   S21Matrix summand_2(9, 9);

//   EXPECT_THROW(summand_1.SubMatrix(summand_2), std::invalid_argument);
// }

// TEST(ArithmeticsTest, MulNumber_1) {
//   S21Matrix multiplier_1(2, 2);
//   S21Matrix result(2, 2);
//   multiplier_1(0, 0) = 1.5;
//   multiplier_1(0, 1) = -2.0;
//   multiplier_1(1, 0) = 3.25;
//   multiplier_1(1, 1) = 4.75;

//   result(0, 0) = 9.0;
//   result(0, 1) = -12.0;
//   result(1, 0) = 19.5;
//   result(1, 1) = 28.5;

//   double multiplier_2 = 6;

//   multiplier_1.MulNumber(multiplier_2);
//   EXPECT_TRUE(multiplier_1 == result);
// }

// TEST(ArithmeticsTest, MulNumber_2) {
//   S21Matrix multiplier_1(4, 4);
//   S21Matrix result(4, 4);

//   multiplier_1(0, 0) = 10;
//   multiplier_1(0, 1) = 20;
//   multiplier_1(0, 2) = 30;
//   multiplier_1(0, 3) = 40;
//   multiplier_1(1, 0) = 50;
//   multiplier_1(1, 1) = 60;
//   multiplier_1(1, 2) = 70;
//   multiplier_1(1, 3) = 80;
//   multiplier_1(2, 0) = 90;
//   multiplier_1(2, 1) = 100;
//   multiplier_1(2, 2) = 110;
//   multiplier_1(2, 3) = 120;
//   multiplier_1(3, 0) = 130;
//   multiplier_1(3, 1) = 140;
//   multiplier_1(3, 2) = 150;
//   multiplier_1(3, 3) = 160;

//   result(0, 0) = 1;
//   result(0, 1) = 2;
//   result(0, 2) = 3;
//   result(0, 3) = 4;
//   result(1, 0) = 5;
//   result(1, 1) = 6;
//   result(1, 2) = 7;
//   result(1, 3) = 8;
//   result(2, 0) = 9;
//   result(2, 1) = 10;
//   result(2, 2) = 11;
//   result(2, 3) = 12;
//   result(3, 0) = 13;
//   result(3, 1) = 14;
//   result(3, 2) = 15;
//   result(3, 3) = 16;

//   double multiplier_2 = 0.1;

//   multiplier_1.MulNumber(multiplier_2);
//   EXPECT_TRUE(multiplier_1 == result);
// }

// TEST(ArithmeticsTest, MulMatrix_1) {
//   S21Matrix multiplier_1(2, 2);
//   S21Matrix multiplier_2(2, 2);
//   S21Matrix result(2, 2);

//   multiplier_1(0, 0) = 10;
//   multiplier_1(0, 1) = -12.568;
//   multiplier_1(1, 0) = 78;
//   multiplier_1(1, 1) = 0.58;

//   multiplier_2(0, 0) = 35;
//   multiplier_2(0, 1) = 145;
//   multiplier_2(1, 0) = 0.22225;
//   multiplier_2(1, 1) = -89;

//   result(0, 0) = 347.206762;
//   result(0, 1) = 2568.552;
//   result(1, 0) = 2730.128905;
//   result(1, 1) = 11258.38;

//   multiplier_1.MulMatrix(multiplier_2);
//   EXPECT_TRUE(multiplier_1 == result);
// }

// TEST(ArithmeticsTest, MulMatrix_2) {
//   S21Matrix multiplier_1(2, 3);
//   S21Matrix multiplier_2(3, 2);
//   S21Matrix result(2, 2);

//   multiplier_1(0, 0) = 10;
//   multiplier_1(0, 1) = -12.568;
//   multiplier_1(0, 2) = 15;
//   multiplier_1(1, 0) = 78;
//   multiplier_1(1, 1) = 0.58;
//   multiplier_1(1, 2) = 6;

//   multiplier_2(0, 0) = 35;
//   multiplier_2(0, 1) = 145;
//   multiplier_2(1, 0) = 0.22225;
//   multiplier_2(1, 1) = -89;
//   multiplier_2(2, 0) = 9;
//   multiplier_2(2, 1) = 10;

//   result(0, 0) = 482.206762;
//   result(0, 1) = 2718.552;
//   result(1, 0) = 2784.128905;
//   result(1, 1) = 11318.38;

//   multiplier_1.MulMatrix(multiplier_2);
//   EXPECT_TRUE(multiplier_1 == result);
// }

// TEST(ArithmeticsTest, MulMatrix_3) {
//   S21Matrix multiplier_1(22, 33);
//   S21Matrix multiplier_2(3, 2);

//   EXPECT_THROW(multiplier_1.MulMatrix(multiplier_2), std::invalid_argument);
// }

// TEST(OtherTest, Transpose_1) {
//   S21Matrix Matrix(2, 2);
//   S21Matrix TransposedMatrix(2, 2);

//   Matrix(0, 0) = 10;
//   Matrix(0, 1) = -12.568;
//   Matrix(1, 0) = 78;
//   Matrix(1, 1) = 0.58;

//   TransposedMatrix(0, 0) = 10;
//   TransposedMatrix(0, 1) = 78;
//   TransposedMatrix(1, 0) = -12.568;
//   TransposedMatrix(1, 1) = 0.58;

//   EXPECT_TRUE((Matrix.Transpose()) == TransposedMatrix);
// }

// TEST(OtherTest, Transpose_2) {
//   S21Matrix Matrix(3, 3);
//   S21Matrix TransposedMatrix(3, 3);

//   Matrix(0, 0) = 7;
//   Matrix(0, 1) = -0.2;
//   Matrix(0, 2) = 25;
//   Matrix(1, 0) = -1.4;
//   Matrix(1, 1) = 50;
//   Matrix(1, 2) = -2;
//   Matrix(2, 0) = -0.234;
//   Matrix(2, 1) = -54;
//   Matrix(2, 2) = 798;

//   TransposedMatrix(0, 0) = 7;
//   TransposedMatrix(0, 1) = -1.4;
//   TransposedMatrix(0, 2) = -0.234;
//   TransposedMatrix(1, 0) = -0.2;
//   TransposedMatrix(1, 1) = 50;
//   TransposedMatrix(1, 2) = -54;
//   TransposedMatrix(2, 0) = 25;
//   TransposedMatrix(2, 1) = -2;
//   TransposedMatrix(2, 2) = 798;

//   EXPECT_TRUE((Matrix.Transpose()) == TransposedMatrix);
// }

// TEST(OtherTest, DeterminantTest_1) {
//   S21Matrix Matrix(2, 2);

//   Matrix(0, 0) = 10;
//   Matrix(0, 1) = -12.568;
//   Matrix(1, 0) = 78;
//   Matrix(1, 1) = 0.58;

//   double check = 986.104;
//   EXPECT_DOUBLE_EQ(Matrix.Determinant(), check);
// }

// TEST(OtherTest, DeterminantTest_2) {
//   S21Matrix Matrix(1, 1);

//   Matrix(0, 0) = 1337.1337;
//   double check = 1337.1337;
//   EXPECT_DOUBLE_EQ(Matrix.Determinant(), check);
// }

// TEST(OtherTest, DeterminantTest_3) {
//   S21Matrix Matrix(123, 1);

//   EXPECT_THROW(Matrix.Determinant(), std::invalid_argument);
// }

// TEST(OtherTest, DeterminantTest_4) {
//   S21Matrix Matrix(3, 3);

//   Matrix(0, 0) = -23;
//   Matrix(0, 1) = -0.5;
//   Matrix(0, 2) = 23;
//   Matrix(1, 0) = 0;
//   Matrix(1, 1) = 0.231;
//   Matrix(1, 2) = 1;
//   Matrix(2, 0) = 6;
//   Matrix(2, 1) = 321;
//   Matrix(2, 2) = 1;

//   double check = 7342.809;
//   EXPECT_DOUBLE_EQ(Matrix.Determinant(), check);
// }

// TEST(OtherTest, CalcComplements_1) {
//   S21Matrix Matrix(3, 3);
//   S21Matrix ComplementsMatrix(3, 3);

//   Matrix(0, 0) = 1;
//   Matrix(0, 1) = -2;
//   Matrix(0, 2) = 6;
//   Matrix(1, 0) = 0;
//   Matrix(1, 1) = 0.5;
//   Matrix(1, 2) = 4;
//   Matrix(2, 0) = 8;
//   Matrix(2, 1) = 1;
//   Matrix(2, 2) = 2;

//   ComplementsMatrix(0, 0) = -3;
//   ComplementsMatrix(0, 1) = 32;
//   ComplementsMatrix(0, 2) = -4;
//   ComplementsMatrix(1, 0) = 10;
//   ComplementsMatrix(1, 1) = -46;
//   ComplementsMatrix(1, 2) = -17;
//   ComplementsMatrix(2, 0) = -11;
//   ComplementsMatrix(2, 1) = -4;
//   ComplementsMatrix(2, 2) = 0.5;

//   EXPECT_TRUE((Matrix.CalcComplements()) == ComplementsMatrix);
// }

// TEST(OtherTest, CalcComplements_2) {
//   S21Matrix Matrix(2, 2);
//   S21Matrix ComplementsMatrix(2, 2);

//   Matrix(0, 0) = -2;
//   Matrix(0, 1) = 0;
//   Matrix(1, 0) = 0.5;
//   Matrix(1, 1) = 8;

//   ComplementsMatrix(0, 0) = 8;
//   ComplementsMatrix(0, 1) = -0.5;
//   ComplementsMatrix(1, 0) = 0;
//   ComplementsMatrix(1, 1) = -2;

//   EXPECT_TRUE((Matrix.CalcComplements()) == ComplementsMatrix);
// }

// TEST(OtherTest, CalcComplements_3) {
//   S21Matrix Matrix(22, 2);

//   EXPECT_THROW((Matrix.CalcComplements()), std::invalid_argument);
// }

// TEST(OtherTest, InverseMatrix_1) {
//   S21Matrix Matrix(3, 3);
//   S21Matrix InversedMatrix(3, 3);

//   Matrix(0, 0) = 1;
//   Matrix(0, 1) = -2;
//   Matrix(0, 2) = 6;
//   Matrix(1, 0) = 0;
//   Matrix(1, 1) = 0.5;
//   Matrix(1, 2) = 4;
//   Matrix(2, 0) = 8;
//   Matrix(2, 1) = 1;
//   Matrix(2, 2) = 2;

//   InversedMatrix(0, 0) = 3.0 / 91.0;
//   InversedMatrix(0, 1) = -10.0 / 91.0;
//   InversedMatrix(0, 2) = 11.0 / 91.0;
//   InversedMatrix(1, 0) = -32.0 / 91.0;
//   InversedMatrix(1, 1) = 46.0 / 91.0;
//   InversedMatrix(1, 2) = 4.0 / 91.0;
//   InversedMatrix(2, 0) = 4.0 / 91.0;
//   InversedMatrix(2, 1) = 17.0 / 91.0;
//   InversedMatrix(2, 2) = -0.5 / 91.0;

//   EXPECT_TRUE((Matrix.InverseMatrix()) == InversedMatrix);
// }

// TEST(OtherTest, InverseMatrix_2) {
//   S21Matrix Matrix(3, 3);
//   S21Matrix InversedMatrix(3, 3);

//   Matrix(0, 0) = 1;
//   Matrix(0, 1) = 3;
//   Matrix(0, 2) = 1321;
//   Matrix(1, 0) = 5;
//   Matrix(1, 1) = 4;
//   Matrix(1, 2) = 4;
//   Matrix(2, 0) = 4;
//   Matrix(2, 1) = 452;
//   Matrix(2, 2) = 2;

//   InversedMatrix(0, 0) = -0.0006076;
//   InversedMatrix(0, 1) = 0.2015452;
//   InversedMatrix(0, 2) = -0.0017796;
//   InversedMatrix(1, 0) = 0.0000020;
//   InversedMatrix(1, 1) = -0.0017829;
//   InversedMatrix(1, 2) = 0.0022282;
//   InversedMatrix(2, 0) = 0.0007575;
//   InversedMatrix(2, 1) = -0.0001485;
//   InversedMatrix(2, 2) = -0.0000037;

//   EXPECT_TRUE((Matrix.InverseMatrix()) == InversedMatrix);
// }

// TEST(OtherTest, InverseMatrix_3) {
//   S21Matrix Matrix(3, 3);

//   Matrix(0, 0) = 1;
//   Matrix(0, 1) = 2;
//   Matrix(0, 2) = 3;
//   Matrix(1, 0) = 4;
//   Matrix(1, 1) = 5;
//   Matrix(1, 2) = 6;
//   Matrix(2, 0) = 7;
//   Matrix(2, 1) = 8;
//   Matrix(2, 2) = 9;

//   EXPECT_THROW((Matrix.InverseMatrix()), std::invalid_argument);
// }

// TEST(OtherTest, InverseMatrix_4) {
//   S21Matrix Matrix(7, 3);

//   EXPECT_THROW((Matrix.InverseMatrix()), std::invalid_argument);
// }

// TEST(OtherTest, EqMatrix_1) {
//   S21Matrix Matrix_1(3, 3);
//   S21Matrix Matrix_2(3, 3);
//   FillMatrixRandom(Matrix_1);

//   EXPECT_FALSE(Matrix_1.EqMatrix(Matrix_2));
// }

// TEST(OtherTest, EqMatrix_2) {
//   S21Matrix Matrix_1(3, 3);
//   S21Matrix Matrix_2(7, 5);

//   EXPECT_FALSE(Matrix_1.EqMatrix(Matrix_2));
// }

// TEST(MutatorTest, SetTest_1) {
//   S21Matrix Matrix(2, 2);

//   EXPECT_THROW(Matrix.SetRows(-23), std::logic_error);
// }

// TEST(MutatorTest, SetTest_2) {
//   S21Matrix Matrix(2, 2);

//   EXPECT_THROW(Matrix.SetCols(-23), std::logic_error);
// }

// TEST(MutatorTest, SetTest_3) {
//   S21Matrix Matrix(2, 2);
//   Matrix.SetRows(23);
//   EXPECT_EQ(Matrix.GetRows(), 23);
// }

// TEST(MutatorTest, SetTest_4) {
//   S21Matrix Matrix(2, 2);
//   Matrix.SetCols(23);
//   EXPECT_EQ(Matrix.GetCols(), 23);
// }

// #endif

// TEST(OperatorTest, OpAssing_1) {
//   S21Matrix Matrix_1(7, 8);
//   FillMatrixRandom(Matrix_1);
//   S21Matrix Matrix_2(4, 3);
//   Matrix_2 = Matrix_1;
//   EXPECT_TRUE(Matrix_1 == Matrix_2);
// }

// TEST(OperatorTest, OpBracket_1) {
//   S21Matrix Matrix(4, 3);
//   EXPECT_THROW(Matrix(-1, 25), std::invalid_argument);
// }

// TEST(OperatorTest, OpBracket_2) {
//   S21Matrix Matrix(1, 1);
//   Matrix(0, 0) = -5222.34;
//   const S21Matrix ConstMatrix(Matrix);
//   const double temp = ConstMatrix(0, 0);
//   EXPECT_DOUBLE_EQ(-5222.34, temp);
// }

// TEST(OperatorTest, OpBracket_3) {
//   S21Matrix Matrix(1, 1);
//   Matrix(0, 0) = -5222.34;
//   const S21Matrix ConstMatrix(Matrix);
//   EXPECT_THROW(ConstMatrix(0, 1), std::invalid_argument);
// }

// TEST(OperatorTest, OpSum_1) {
//   S21Matrix summand_1(3, 3);
//   S21Matrix summand_2(3, 3);
//   S21Matrix result(3, 3);

//   summand_1(0, 0) = 6;
//   summand_1(0, 1) = 45.1;
//   summand_1(0, 2) = -3.321;
//   summand_1(1, 0) = 0;
//   summand_1(1, 1) = 0;
//   summand_1(1, 2) = 4;
//   summand_1(2, 0) = -0.0005;
//   summand_1(2, 1) = 321.43;
//   summand_1(2, 2) = -898;

//   summand_2(0, 0) = 2;
//   summand_2(0, 1) = -43.2;
//   summand_2(0, 2) = 32.2;
//   summand_2(1, 0) = 12;
//   summand_2(1, 1) = 21.3;
//   summand_2(1, 2) = 2;
//   summand_2(2, 0) = 0;
//   summand_2(2, 1) = 0.0007;
//   summand_2(2, 2) = 45.04;

//   result(0, 0) = 8;
//   result(0, 1) = 1.9;
//   result(0, 2) = 28.879;
//   result(1, 0) = 12;
//   result(1, 1) = 21.3;
//   result(1, 2) = 6;
//   result(2, 0) = -0.0005;
//   result(2, 1) = 321.4307;
//   result(2, 2) = -852.96;

//   EXPECT_TRUE((summand_1 + summand_2) == result);
// }

// TEST(OperatorTest, OpSum_2) {
//   S21Matrix summand_1(5, 24);
//   S21Matrix summand_2(3, 4);
//   EXPECT_THROW(summand_1 + summand_2, std::invalid_argument);
// }

// TEST(OperatorTest, OpSub_1) {
//   S21Matrix minuend(3, 3);
//   S21Matrix subtrahend(3, 3);
//   S21Matrix result(3, 3);

//   minuend(0, 0) = 6;
//   minuend(0, 1) = 45.1;
//   minuend(0, 2) = -3.321;
//   minuend(1, 0) = 0;
//   minuend(1, 1) = 0;
//   minuend(1, 2) = 4;
//   minuend(2, 0) = -0.0005;
//   minuend(2, 1) = 321.43;
//   minuend(2, 2) = -898;

//   subtrahend(0, 0) = 2;
//   subtrahend(0, 1) = -43.2;
//   subtrahend(0, 2) = 32.2;
//   subtrahend(1, 0) = 12;
//   subtrahend(1, 1) = 21.3;
//   subtrahend(1, 2) = 2;
//   subtrahend(2, 0) = 0;
//   subtrahend(2, 1) = 0.0007;
//   subtrahend(2, 2) = 45.04;

//   result(0, 0) = 4;
//   result(0, 1) = 88.3;
//   result(0, 2) = -35.521;
//   result(1, 0) = -12;
//   result(1, 1) = -21.3;
//   result(1, 2) = 2;
//   result(2, 0) = -0.0005;
//   result(2, 1) = 321.4293;
//   result(2, 2) = -943.04;

//   EXPECT_TRUE((minuend - subtrahend) == result);
// }

// TEST(OperatorTest, OpSub_2) {
//   S21Matrix summand_1(5, 24);
//   S21Matrix summand_2(3, 4);
//   EXPECT_THROW(summand_1 - summand_2, std::invalid_argument);
// }

// TEST(OperatorTest, OpSumAndAssign_1) {
//   S21Matrix summand_1(3, 3);
//   S21Matrix summand_2(3, 3);
//   S21Matrix result(3, 3);

//   summand_1(0, 0) = 6;
//   summand_1(0, 1) = 45.1;
//   summand_1(0, 2) = -3.321;
//   summand_1(1, 0) = 0;
//   summand_1(1, 1) = 0;
//   summand_1(1, 2) = 4;
//   summand_1(2, 0) = -0.0005;
//   summand_1(2, 1) = 321.43;
//   summand_1(2, 2) = -898;

//   summand_2(0, 0) = 2;
//   summand_2(0, 1) = -43.2;
//   summand_2(0, 2) = 32.2;
//   summand_2(1, 0) = 12;
//   summand_2(1, 1) = 21.3;
//   summand_2(1, 2) = 2;
//   summand_2(2, 0) = 0;
//   summand_2(2, 1) = 0.0007;
//   summand_2(2, 2) = 45.04;

//   result(0, 0) = 8;
//   result(0, 1) = 1.9;
//   result(0, 2) = 28.879;
//   result(1, 0) = 12;
//   result(1, 1) = 21.3;
//   result(1, 2) = 6;
//   result(2, 0) = -0.0005;
//   result(2, 1) = 321.4307;
//   result(2, 2) = -852.96;

//   summand_1 += summand_2;
//   EXPECT_TRUE(summand_1 == result);
// }

// TEST(OperatorTest, OpSubAndAssign_1) {
//   S21Matrix minuend(3, 3);
//   S21Matrix subtrahend(3, 3);
//   S21Matrix result(3, 3);

//   minuend(0, 0) = 6;
//   minuend(0, 1) = 45.1;
//   minuend(0, 2) = -3.321;
//   minuend(1, 0) = 0;
//   minuend(1, 1) = 0;
//   minuend(1, 2) = 4;
//   minuend(2, 0) = -0.0005;
//   minuend(2, 1) = 321.43;
//   minuend(2, 2) = -898;

//   subtrahend(0, 0) = 2;
//   subtrahend(0, 1) = -43.2;
//   subtrahend(0, 2) = 32.2;
//   subtrahend(1, 0) = 12;
//   subtrahend(1, 1) = 21.3;
//   subtrahend(1, 2) = 2;
//   subtrahend(2, 0) = 0;
//   subtrahend(2, 1) = 0.0007;
//   subtrahend(2, 2) = 45.04;

//   result(0, 0) = 4;
//   result(0, 1) = 88.3;
//   result(0, 2) = -35.521;
//   result(1, 0) = -12;
//   result(1, 1) = -21.3;
//   result(1, 2) = 2;
//   result(2, 0) = -0.0005;
//   result(2, 1) = 321.4293;
//   result(2, 2) = -943.04;

//   minuend -= subtrahend;
//   EXPECT_TRUE(minuend == result);
// }

// TEST(OperatorTest, OpMul_1) {
//   S21Matrix multiplier_1(2, 3);
//   S21Matrix multiplier_2(3, 2);
//   S21Matrix result(2, 2);

//   multiplier_1(0, 0) = 10;
//   multiplier_1(0, 1) = -12.568;
//   multiplier_1(0, 2) = 15;
//   multiplier_1(1, 0) = 78;
//   multiplier_1(1, 1) = 0.58;
//   multiplier_1(1, 2) = 6;

//   multiplier_2(0, 0) = 35;
//   multiplier_2(0, 1) = 145;
//   multiplier_2(1, 0) = 0.22225;
//   multiplier_2(1, 1) = -89;
//   multiplier_2(2, 0) = 9;
//   multiplier_2(2, 1) = 10;

//   result(0, 0) = 482.206762;
//   result(0, 1) = 2718.552;
//   result(1, 0) = 2784.128905;
//   result(1, 1) = 11318.38;

//   EXPECT_TRUE((multiplier_1 * multiplier_2) == result);
// }

// TEST(OperatorTest, OpMul_2) {
//   S21Matrix multiplier_1(2, 2);
//   S21Matrix result(2, 2);
//   multiplier_1(0, 0) = 1.5;
//   multiplier_1(0, 1) = -2.0;
//   multiplier_1(1, 0) = 3.25;
//   multiplier_1(1, 1) = 4.75;

//   result(0, 0) = 9.0;
//   result(0, 1) = -12.0;
//   result(1, 0) = 19.5;
//   result(1, 1) = 28.5;

//   double multiplier_2 = 6;

//   EXPECT_TRUE((multiplier_1 * multiplier_2) == result);
// }

// TEST(OperatorTest, OpMulAndAssign_1) {
//   S21Matrix multiplier_1(2, 3);
//   S21Matrix multiplier_2(3, 2);
//   S21Matrix result(2, 2);

//   multiplier_1(0, 0) = 10;
//   multiplier_1(0, 1) = -12.568;
//   multiplier_1(0, 2) = 15;
//   multiplier_1(1, 0) = 78;
//   multiplier_1(1, 1) = 0.58;
//   multiplier_1(1, 2) = 6;

//   multiplier_2(0, 0) = 35;
//   multiplier_2(0, 1) = 145;
//   multiplier_2(1, 0) = 0.22225;
//   multiplier_2(1, 1) = -89;
//   multiplier_2(2, 0) = 9;
//   multiplier_2(2, 1) = 10;

//   result(0, 0) = 482.206762;
//   result(0, 1) = 2718.552;
//   result(1, 0) = 2784.128905;
//   result(1, 1) = 11318.38;
//   multiplier_1 *= multiplier_2;
//   EXPECT_TRUE(multiplier_1 == result);
// }

// TEST(OperatorTest, OpMulAndAssign_2) {
//   S21Matrix multiplier_1(2, 2);
//   S21Matrix result(2, 2);
//   multiplier_1(0, 0) = 1.5;
//   multiplier_1(0, 1) = -2.0;
//   multiplier_1(1, 0) = 3.25;
//   multiplier_1(1, 1) = 4.75;

//   result(0, 0) = 9.0;
//   result(0, 1) = -12.0;
//   result(1, 0) = 19.5;
//   result(1, 1) = 28.5;

//   double multiplier_2 = 6;

//   multiplier_1 *= multiplier_2;
//   EXPECT_TRUE(multiplier_1 == result);
// }