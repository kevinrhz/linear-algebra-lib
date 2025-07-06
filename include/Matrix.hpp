#pragma once

#include <vector>
#include <cstddef>
#include <iostream>

template<typename T>
class Matrix {
public:
    Matrix(std::size_t rows, std::size_t cols);
    T& operator()(std::size_t i, std::size_t j);
    const T& operator()(std::size_t i, std::size_t j) const;

    std::size_t numRows() const;
    std::size_t numCols() const;

    // Operations
    static Matrix<T> identity(std::size_t n);
    static Matrix<T> rowSwapMatrix(std::size_t n, std::size_t i, std::size_t j);
    static Matrix<T> rowScaleMatrix(std::size_t n, std::size_t row, T scalar);
    static Matrix<T> rowAddMatrix(std::size_t n, std::size_t srcRow, std::size_t destRow, T factor);

    // Utility
    void print() const;

private:
    std::size_t rows_, cols_;
    std::vector<T> data_;
};

#include "../src/Matrix.tpp"
