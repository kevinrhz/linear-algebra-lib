#include <iostream>
#include "include/Matrix.hpp"

int main() {
    Matrix<double> A(3,3);
    for (size_t i = 0, v=1; i<3; ++i)
        for (size_t j=0; j<3; ++j)
            A(i,j)=v++;

    std::cout<<"Original A:\n"; A.print();

    A.rowSwap(0,2);
    std::cout<<"\nAfter swapRows(0,2):\n"; A.print();

    A = Matrix<double>::identity(3);
    A(1,0) = 2;
    A(1,1) = 3;
    A(1,2) = 4;
    std::cout<<"\nReset + modify row1:\n"; A.print();

    A.rowScale(1, 5);
    std::cout<<"\nAfter scaleRow(1,5):\n"; A.print();

    A = Matrix<double>::identity(3);
    std::cout<<"\nReset to I_3:\n"; A.print();

    A.rowAdd(0, 2, 3.0);
    std::cout<<"\nAfter addRow(0->2,x3):\n"; A.print();

    return 0;
}
