cmake_minimum_required(VERSION 3.24)
project(LinearAlgebraLib VERSION 0.1 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files for the core library
set(SRC_FILES
        src/Matrix.tpp
        src/Vector.tpp
        src/LinearSolver.cpp
        src/Determinant.cpp
        src/Transform.cpp
        src/Decomposition.cpp
        src/Eigen.cpp
        src/Orthogonality.cpp
        src/Utility.cpp
)

# Create static library target
add_library(LinearAlgebraLib STATIC ${SRC_FILES})

# Enable folders in IDEs (e.g., CLion)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_target_properties(LinearAlgebraLib PROPERTIES FOLDER "Library")

# ========== Test Executables ==========
add_executable(test_matrix tests/test_matrix.cpp)
target_link_libraries(test_matrix PRIVATE LinearAlgebraLib)
set_target_properties(test_matrix PROPERTIES FOLDER "Tests")

add_executable(test_vector tests/test_vector.cpp)
target_link_libraries(test_vector PRIVATE LinearAlgebraLib)
set_target_properties(test_vector PROPERTIES FOLDER "Tests")

add_executable(test_solvers tests/test_solvers.cpp)
target_link_libraries(test_solvers PRIVATE LinearAlgebraLib)
set_target_properties(test_solvers PROPERTIES FOLDER "Tests")

add_executable(test_determinants tests/test_determinants.cpp)
target_link_libraries(test_determinants PRIVATE LinearAlgebraLib)
set_target_properties(test_determinants PROPERTIES FOLDER "Tests")

add_executable(test_eigen tests/test_eigen.cpp)
target_link_libraries(test_eigen PRIVATE LinearAlgebraLib)
set_target_properties(test_eigen PROPERTIES FOLDER "Tests")

add_executable(test_decompositions tests/test_decompositions.cpp)
target_link_libraries(test_decompositions PRIVATE LinearAlgebraLib)
set_target_properties(test_decompositions PROPERTIES FOLDER "Tests")

add_executable(test_applications tests/test_applications.cpp)
target_link_libraries(test_applications PRIVATE LinearAlgebraLib)
set_target_properties(test_applications PROPERTIES FOLDER "Tests")

# ========== Example Executables ==========
add_executable(solve_system examples/solve_system.cpp)
target_link_libraries(solve_system PRIVATE LinearAlgebraLib)
set_target_properties(solve_system PROPERTIES FOLDER "Examples")

add_executable(simulate_pca examples/simulate_pca.cpp)
target_link_libraries(simulate_pca PRIVATE LinearAlgebraLib)
set_target_properties(simulate_pca PROPERTIES FOLDER "Examples")

add_executable(gram_schmidt_demo examples/gram_schmidt_demo.cpp)
target_link_libraries(gram_schmidt_demo PRIVATE LinearAlgebraLib)
set_target_properties(gram_schmidt_demo PROPERTIES FOLDER "Examples")

add_executable(markov_chain_sim examples/markov_chain_sim.cpp)
target_link_libraries(markov_chain_sim PRIVATE LinearAlgebraLib)
set_target_properties(markov_chain_sim PROPERTIES FOLDER "Examples")

# ========== Python Binding Setup ==========
# find_package(pybind11 REQUIRED)
# add_library(python_bindings MODULE bindings/pybind_interface.cpp)
# target_link_libraries(python_bindings PRIVATE LinearAlgebraLib pybind11::module)
# set_target_properties(python_bindings PROPERTIES FOLDER "Bindings")
