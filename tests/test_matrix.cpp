#include <gtest/gtest.h>
#include "../include/Matrix.hpp"

TEST(MatrixTest, BasicElementAccess) {
    Matrix<int> mat(2, 2);
    mat(0, 0) = 5;
    mat(1, 1) = 10;

    EXPECT_EQ(mat(0, 0), 5);
    EXPECT_EQ(mat(1, 1), 10);
    EXPECT_EQ(mat.numRows(), 2);
    EXPECT_EQ(mat.numCols(), 2);
}

TEST(MatrixTest, OutOfBoundsThrows) {
    Matrix<float> mat(3, 3);
    EXPECT_THROW(mat(3, 0) = 1.0f, std::out_of_range);
}
