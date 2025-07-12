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
public:
    /**
     * @brief Construct a rows × cols matrix, initialized to zero.
     *
     * @param rows Number of rows
     * @param cols Number of columns
     */
    Matrix(std::size_t rows, std::size_t cols);

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

    /**
     * @brief Multiply two matrices (this * other).
     *
     * @param other Right-hand operand.
     * @return New matrix equal to this × other.
     * @throw std::invalid_argument if dimensions don’t match.
     */
    Matrix<T> operator*(const Matrix<T> &other) const;


    // ────── Elementary / Factory Matrices ──────

    /**
     * @brief Create an n×n identity matrix.
     *
     * All diagonal elements = 1, off-diagonals = 0.
     *
     * @param n Dimension of the matrix
     * @return Identity matrix of size n
     */
    static Matrix<T> identity(std::size_t n);

    /**
     * @brief Swap two rows of this matrix in place.
     */
    void swapRows(std::size_t i, std::size_t j);

    /**
     * @brief Elementary matrix that swaps rows i and j when left-multiplied.
     *
     * @param n    Dimension of the square matrix
     * @param i    First row to swap
     * @param j    Second row to swap
     * @return Row-swap matrix
     */
    static Matrix<T> rowSwapMatrix(std::size_t n, std::size_t i, std::size_t j);

    /**
     * @brief Multiply a row by a scalar in place.
     */
    void scaleRow(std::size_t row, T factor);

    /**
     * @brief Elementary matrix that scales a single row by a factor when left-multiplied.
     *
     * @param n      Dimension of the matrix
     * @param row    Row index to scale
     * @param scalar Multiplicative factor for the row
     * @return Row-scale matrix
     */
    static Matrix<T> rowScaleMatrix(std::size_t n, std::size_t row, T scalar);

    /**
     * @brief Add factor × srcRow into destRow in place.
     */
    void addRow(std::size_t srcRow, std::size_t destRow, T factor);

    /**
     * @brief Elementary matrix that adds (factor × srcRow) to destRow when left-multiplied.
     *
     * @param n        Dimension of the square matrix
     * @param srcRow   Source row index
     * @param destRow  Destination row index
     * @param factor   Multiplier for source row
     * @return Row-addition matrix
     */
    static Matrix<T> rowAddMatrix(std::size_t n, std::size_t srcRow, std::size_t destRow, T factor);

    // ────── Utility ──────

    /**
     * @brief Print the matrix to stdout in a lined-up, readable format.
     *
     * Uses fixed-width fields for alignment.
     */
    void print() const;

private:
    std::size_t rows_, cols_;   ///< Dimensions
    std::vector<T> data_;       ///< Row-major data storage
};

#include "../src/Matrix.tpp"
