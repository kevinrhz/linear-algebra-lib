#pragma once

#include <vector>
#include <cstddef>
#include <iostream>

/**
 * @brief A simple, fixed-size, row-major matrix template.
 *
 * Provides core linear algebra operations and factory functions
 * for elementary matrices. Designed for educational clarity and
 * future Python/CUDA bindings.
 *
 * @tparam T Numeric type (e.g., float, double, int).
 */
template<typename T>
class Matrix {
private:
    std::size_t rows_, cols_;   ///< Dimensions
    std::vector<T> data_;       ///< Row-major data storage

public:
    // --- Constructors ---
    /**
     * @brief Construct a rows × cols matrix, initialized to zero.
     *
     * @param rows Number of rows
     * @param cols Number of columns
     */
    Matrix(std::size_t rows, std::size_t cols);

    // --- Element Access ---
    /**
     * @brief Number of rows in the matrix.
     * @return rows count
     */
    std::size_t numRows() const;

    /**
     * @brief Number of columns in the matrix.
     * @return columns count
     */
    std::size_t numCols() const;

    /**
     * @brief Access element at (i, j) for modification.
     *
     * Throws std::out_of_range if indices are invalid.
     *
     * @param i Row index (0-based)
     * @param j Column index (0-based)
     * @return Reference to element
     */
    T& operator()(std::size_t i, std::size_t j);

    /**
     * @brief Access element at (i, j) without modification.
     *
     * Throws std::out_of_range if indices are invalid.
     *
     * @param i Row index (0-based)
     * @param j Column index (0-based)
     * @return Const reference to element
     */
    const T& operator()(std::size_t i, std::size_t j) const;

    // --- Basic Matrix Operations ---
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator-(const Matrix<T>& other) const;

    /**
     * @brief Multiply two matrices (this * other).
     *
     * @param other Right-hand operand.
     * @return New matrix equal to this × other.
     * @throw std::invalid_argument if dimensions don’t match.
     */
    Matrix<T> operator*(const Matrix<T> &other) const;


    Matrix<T> transpose() const;

    /**
     * @brief Create an n×n identity matrix.
     *
     * All diagonal elements = 1, off-diagonals = 0.
     *
     * @param n Dimension of the matrix
     * @return Identity matrix of size n
     */
    static Matrix<T> identity(std::size_t n);

    // --- In-Place Row Operations ---
    /**
     * @brief Swap two rows of this matrix in place.
     */
    void rowSwap(std::size_t i, std::size_t j);

    /**
     * @brief Multiply a row by a scalar in place.
     */
    void rowScale(std::size_t row, T factor);

    /**
     * @brief Add factor × srcRow into destRow in place.
     */
    void rowAdd(std::size_t srcRow, std::size_t destRow, T factor);

    // --- Elementary Matrix Generators ---
    /**
     * @brief Elementary matrix that swaps rows i and j when left-multiplied.
     *
     * @param n    Dimension of the square matrix
     * @param i    First row to swap
     * @param j    Second row to swap
     * @return Row-swap matrix
     */
    static Matrix<T> makeRowSwapMatrix(std::size_t n, std::size_t i, std::size_t j);

    /**
     * @brief Elementary matrix that scales a single row by a factor when left-multiplied.
     *
     * @param n      Dimension of the matrix
     * @param row    Row index to scale
     * @param scalar Multiplicative factor for the row
     * @return Row-scale matrix
     */
    static Matrix<T> makeRowScaleMatrix(std::size_t n, std::size_t row, T scalar);

    /**
     * @brief Elementary matrix that adds (factor × srcRow) to destRow when left-multiplied.
     *
     * @param n        Dimension of the square matrix
     * @param srcRow   Source row index
     * @param destRow  Destination row index
     * @param factor   Multiplier for source row
     * @return Row-addition matrix
     */
    static Matrix<T> makeRowAddMatrix(std::size_t n, std::size_t srcRow, std::size_t destRow, T factor);

    // --- Utility ---
    /**
     * @brief Print the matrix to stdout in a lined-up, readable format.
     *
     * Uses fixed-width fields for alignment.
     */
    void print() const;

    /**
     * @brief Check if this matrix has the same dimensions as another.
     *
     * @param other Matrix to compare with.
     * @return true if dimensions match, false otherwise.
     */
    bool isSameSize(const Matrix<T>& other) const;
};

#include "../src/Matrix.tpp"
