# LinearAlgebraLib

A modular, educational C++ library for learning and implementing core linear algebra concepts.  
This project aligns with my University linear algebra course and is designed to reinforce mastery through real code.

---

## 🔍 Overview

This library includes templated implementations of:

- `Matrix` and `Vector` classes
- Matrix operations (add, multiply, transpose)
- Solving systems of equations (Gaussian Elimination, LU)
- Determinant calculation (recursive + cofactor)
- Vector space tools (basis, rank, span)
- Linear transformations
- Eigenvalues and eigenvectors (power iteration)
- Orthogonalization and SVD (in progress)
- Real-world applications: PCA, Markov chains, projections

Bindings for Python (`pybind11`) and real-time plotting/benchmarking are planned.

---

## 🗂 Project Structure

- include/ → Header files and core API
- src/ → Implementations (.tpp/.cpp)
- tests/ → Unit tests for each module
- examples/ → Small apps that apply the library
- bindings/ → Python/CUDA interop (optional)
- CMakeLists.txt → Build config


---

## ✅ Status

This project is in active development alongside a linear algebra course.  
Check back weekly for new modules and example applications.

---

## 📌 Goals

- Reinforce theory by implementing each concept from scratch
- Build an API-first, testable C++ library
- Create visual + interactive examples to deepen understanding
- Enable future use of this library in Python and CUDA projects

---

## 🚀 Getting Started

```bash
mkdir build && cd build
cmake ..
make
./test_runner         # Run tests
./solve_example       # Run demo (if built)
```
You’ll need a C++20 compiler and CMake 3.24+