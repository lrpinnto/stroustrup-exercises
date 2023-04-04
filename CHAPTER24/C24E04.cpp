// CHAPTER 24 EX 04

// Test the Gaussian elimination program

#include "./classical_gaussian_elimination.h"
#include <iostream>

int main()
{
    double a[3][3] = 
    {
       {1,2,3},
       {2,3,4},
       {3,4,1}
    };
    double b[3] = {14,20,14};

    Matrix A(a);
    Vector B(b);

    std::cout << "Solving A*x=B" << std::endl;
    std::cout << "A=\n" << A << std::endl;
    std::cout << "B="   << B << std::endl;

    Vector x = classical_gaussian_elimination(A, B);
    std::cout << "x="   << x << std::endl;
}