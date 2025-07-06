#pragma once

#include <stdexcept>
#include <iomanip>

template<typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols)
    : rows_(rows), cols_(cols), data_(rows * cols, T()) {}

template<typename T>
T& Matrix<T>::operator()(std::size_t i, std::size_t j) {
    if (i >= rows_ || j >= cols_)
        throw std::out_of_range("Matrix index out of range");
    return data_[i * cols_ + j];
}

template<typename T>
const T& Matrix<T>::operator()(std::size_t i, std::size_t j) const {
    if (i >= rows_ || j >= cols_)
        throw std::out_of_range("Matrix index out of range");
    return data_[i * cols_ + j];
}

template<typename T>
std::size_t Matrix<T>::numRows() const { return rows_; }

template<typename T>
std::size_t Matrix<T>::numCols() const { return cols_; }

template<typename T>
Matrix<T> Matrix<T>::identity(std::size_t n) {
    Matrix<T> I(n, n);
    for (std::size_t i = 0; i < n; ++i)
        I(i, i) = T(1);
    return I;
}

template<typename T>
Matrix<T> Matrix<T>::rowSwapMatrix(std::size_t n, std::size_t i, std::size_t j) {
    Matrix<T> E = identity(n);
    std::swap(E(i, i), E(j, j));
    E(i, j) = T(1);
    E(j, i) = T(1);
    E(i, i) = T(0);
    E(j, j) = T(0);
    return E;
}

template<typename T>
Matrix<T> Matrix<T>::rowScaleMatrix(std::size_t n, std::size_t row, T scalar) {
    Matrix<T> E = identity(n);
    E(row, row) = scalar;
    return E;
}

template<typename T>
Matrix<T> Matrix<T>::rowAddMatrix(std::size_t n, std::size_t srcRow, std::size_t destRow, T factor) {
    Matrix<T> E = identity(n);
    E(destRow, srcRow) = factor;
    return E;
}


template<typename T>
void Matrix<T>::print() const {
    constexpr int width = 10;
    for (std::size_t i = 0; i < rows_; ++i) {
        std::cout << "[ ";
        for (std::size_t j = 0; j < cols_; ++j) {
            std::cout << std::setw(width) << operator()(i, j) << " ";
        }
        std::cout << "]\n";
    }
}

