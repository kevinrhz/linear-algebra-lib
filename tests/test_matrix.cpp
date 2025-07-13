#include <gtest/gtest.h>
#include "../include/Matrix.hpp"

using Mat = Matrix<double>;

TEST(MatrixTest, IdentityMatrix) {
    Mat I = Mat::identity(3);
    for (std::size_t i = 0; i < 3; ++i) {
        for (std::size_t j = 0; j < 3; ++j) {
            if (i == j)
                EXPECT_EQ(I(i, j), 1.0);
            else
                EXPECT_EQ(I(i, j), 0.0);
        }
    }
}

TEST(MatrixTest, MatrixAddition) {
    Mat A(2, 2);
    Mat B(2, 2);

    A(0, 0) = 1; A(0, 1) = 2;
    A(1, 0) = 3; A(1, 1) = 4;

    B(0, 0) = 5; B(0, 1) = 6;
    B(1, 0) = 7; B(1, 1) = 8;

    Mat C = A + B;

    EXPECT_EQ(C(0, 0), 6);
    EXPECT_EQ(C(0, 1), 8);
    EXPECT_EQ(C(1, 0), 10);
    EXPECT_EQ(C(1, 1), 12);
}

TEST(MatrixTest, MatrixSubtraction) {
    Mat A(2, 2);
    Mat B(2, 2);

    A(0, 0) = 9; A(0, 1) = 8;
    A(1, 0) = 7; A(1, 1) = 6;

    B(0, 0) = 1; B(0, 1) = 2;
    B(1, 0) = 3; B(1, 1) = 4;

    Mat C = A - B;

    EXPECT_EQ(C(0, 0), 8);
    EXPECT_EQ(C(0, 1), 6);
    EXPECT_EQ(C(1, 0), 4);
    EXPECT_EQ(C(1, 1), 2);
}

TEST(MatrixTest, MatrixTranspose) {
    Mat A(2, 3);

    A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
    A(1, 0) = 4; A(1, 1) = 5; A(1, 2) = 6;

    Mat AT = A.transpose();

    EXPECT_EQ(AT.numRows(), 3);
    EXPECT_EQ(AT.numCols(), 2);

    EXPECT_EQ(AT(0, 0), 1);
    EXPECT_EQ(AT(0, 1), 4);
    EXPECT_EQ(AT(1, 0), 2);
    EXPECT_EQ(AT(1, 1), 5);
    EXPECT_EQ(AT(2, 0), 3);
    EXPECT_EQ(AT(2, 1), 6);
}

TEST(MatrixTest, MatrixMultiplication) {
    Mat A(2, 3);
    A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
    A(1, 0) = 4; A(1, 1) = 5; A(1, 2) = 6;

    Mat B(3, 2);
    B(0, 0) = 7; B(0, 1) = 8;
    B(1, 0) = 9; B(1, 1) = 10;
    B(2, 0) = 11; B(2, 1) = 12;

    Mat C = A * B;

    EXPECT_EQ(C.numRows(), 2);
    EXPECT_EQ(C.numCols(), 2);

    EXPECT_EQ(C(0, 0), 58);
    EXPECT_EQ(C(0, 1), 64);
    EXPECT_EQ(C(1, 0), 139);
    EXPECT_EQ(C(1, 1), 154);
}

TEST(MatrixTest, InPlaceRowSwap) {
    Mat A(2, 2);
    A(0, 0) = 1; A(0, 1) = 2;
    A(1, 0) = 3; A(1, 1) = 4;

    A.rowSwap(0, 1);

    EXPECT_EQ(A(0, 0), 3);
    EXPECT_EQ(A(0, 1), 4);
    EXPECT_EQ(A(1, 0), 1);
    EXPECT_EQ(A(1, 1), 2);
}

TEST(MatrixTest, InPlaceRowScale) {
    Mat A = Mat::identity(3);
    A.rowScale(1, 5);

    EXPECT_EQ(A(1, 1), 5);
    EXPECT_EQ(A(0, 0), 1);
    EXPECT_EQ(A(2, 2), 1);
}

TEST(MatrixTest, InPlaceRowAdd) {
    Mat A = Mat::identity(3);
    A(0, 0) = 2; A(0, 1) = 3;

    A.rowAdd(0, 1, 2);

    EXPECT_EQ(A(1, 0), 4);  // 0 + 2 × 2
    EXPECT_EQ(A(1, 1), 7);  // 1 + 2 × 3
}

TEST(MatrixTest, ElementaryRowSwapMatrix) {
    Mat E = Mat::makeRowSwapMatrix(3, 0, 2);

    Mat A(3, 3);
    int val = 1;
    for (std::size_t i = 0; i < 3; ++i)
        for (std::size_t j = 0; j < 3; ++j)
            A(i, j) = val++;

    Mat B = E * A;

    EXPECT_EQ(B(0, 0), A(2, 0));
    EXPECT_EQ(B(2, 0), A(0, 0));
}

TEST(MatrixTest, ElementaryRowScaleMatrix) {
    Mat E = Mat::makeRowScaleMatrix(3, 1, 3.0);

    Mat A = Mat::identity(3);
    Mat B = E * A;

    EXPECT_EQ(B(1, 1), 3);
}

TEST(MatrixTest, ElementaryRowAddMatrix) {
    Mat E = Mat::makeRowAddMatrix(3, 0, 2, 5);

    Mat A = Mat::identity(3);
    Mat B = E * A;

    EXPECT_EQ(B(2, 0), 5);
    EXPECT_EQ(B(2, 2), 1);
}
