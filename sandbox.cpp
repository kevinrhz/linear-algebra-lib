#include <iostream>
#include "include/Matrix.hpp"

int main() {
    Matrix<double> A(3, 3);
    A(0, 0) = 2; A(0, 1) = -1; A(0, 2) = 0;
    A(1, 0) = -1; A(1, 1) = 2; A(1, 2) = -1;
    A(2, 0) = 0; A(2, 1) = -1; A(2, 2) = 2;

    std::cout << "Matrix A:\n";
    A.print();

    // You can play with dot/cross products, transforms, etc. here too

    return 0;
}
