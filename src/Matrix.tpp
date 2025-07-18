#pragma once

#include <stdexcept>
#include <iomanip>

template<typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols)
    : rows_(rows), cols_(cols), data_(rows * cols, T()) {}

template<typename T>
std::size_t Matrix<T>::numRows() const { return rows_; }

template<typename T>
std::size_t Matrix<T>::numCols() const { return cols_; }

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
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (!isSameSize(other))
        throw std::invalid_argument("Matrix addition size mismatch");

    Matrix<T> result(rows_, cols_);
    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t j = 0; j < cols_; ++j) {
            result(i, j) = operator()(i, j) + other(i, j);
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
    if (!isSameSize(other))
        throw std::invalid_argument("Matrix subtraction size mismatch");

    Matrix<T> result(rows_, cols_);
    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t j = 0; j < cols_; ++j) {
            result(i, j) = operator()(i, j) - other(i, j);
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &B) const {
    const Matrix<T>& A = *this;
    if (A.numCols() != B.numRows())
        throw std::invalid_argument("Matrix dimensions mismatch for multiplication");

    Matrix<T> result(A.numRows(), B.numCols());
    for (std::size_t i = 0; i < A.numRows(); ++i) {
        for (std::size_t j = 0; j < B.numCols(); ++j) {
            T sum = T();
            for (std::size_t k = 0; k < A.numCols(); ++k) {
                sum += A(i, k) * B(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> result(cols_, rows_);  // swap rows and cols

    for (std::size_t i = 0; i < rows_; ++i) {
        for (std::size_t j = 0; j < cols_; ++j) {
            result(j, i) = operator()(i, j);
        }
    }

    return result;
}


template<typename T>
Matrix<T> Matrix<T>::identity(std::size_t n) {
    Matrix<T> I(n, n);
    for (std::size_t i = 0; i < n; ++i)
        I(i, i) = T(1);
    return I;
}

template<typename T>
void Matrix<T>::rowSwap(std::size_t i, std::size_t j) {
    if (i >= rows_ || j >= rows_)
        throw std::out_of_range("swapRows: row index out of range");
    for (std::size_t col = 0; col < cols_; ++col)
        std::swap(operator()(i, col), operator()(j, col));
}

template<typename T>
void Matrix<T>::rowScale(std::size_t row, T factor) {
    if (row >= rows_)
        throw std::out_of_range("scaleRow: row index out of range");
    for (std::size_t col = 0; col < cols_; ++col)
        operator()(row, col) *= factor;
}

template<typename T>
void Matrix<T>::rowAdd(std::size_t srcRow, std::size_t destRow, T factor) {
    if (srcRow >= rows_ || destRow >= rows_)
        throw std::out_of_range("addRow: row index out of range");
    for (std::size_t col = 0; col < cols_; ++col)
        operator()(destRow, col) += operator()(srcRow, col) * factor;
}


template<typename T>
Matrix<T> Matrix<T>::makeRowSwapMatrix(std::size_t n, std::size_t i, std::size_t j) {
    Matrix<T> E = identity(n);
    std::swap(E(i, i), E(j, j));
    E(i, j) = T(1);
    E(j, i) = T(1);
    E(i, i) = T(0);
    E(j, j) = T(0);
    return E;
}

template<typename T>
Matrix<T> Matrix<T>::makeRowScaleMatrix(std::size_t n, std::size_t row, T scalar) {
    Matrix<T> E = identity(n);
    E(row, row) = scalar;
    return E;
}

template<typename T>
Matrix<T> Matrix<T>::makeRowAddMatrix(std::size_t n, std::size_t srcRow, std::size_t destRow, T factor) {
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

template<typename T>
bool Matrix<T>::isSameSize(const Matrix<T>& other) const {
    return (rows_ == other.rows_) && (cols_ == other.cols_);
}
