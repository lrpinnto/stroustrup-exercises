// CHAPTER 24 EX 05

// Cause the gaussian elimination to fail and then try with elim_with_partial_pivot()

#include "./classical_gaussian_elimination.h"
#include <iostream>
#include <stdexcept>

void elim_with_partial_pivot(Matrix& A, Vector& b)
{
    const Index n = A.dim1();

    for (Index j = 0; j < n; ++j)
    {
        Index pivot_row = j;

        // look for a suitable pivot:
        for (Index k = j + 1; k < n; ++k)
            if (abs(A(k, j)) > abs(A(pivot_row, j))) pivot_row = k;

        // swap the rows if we found a better pivot:
        if (pivot_row != j) 
        {
            A.swap_rows(j, pivot_row);
            std::swap(b(j), b(pivot_row));
        }

        // elimination:
        for (Index i = j + 1; i < n; ++i) 
        {
            const double pivot = A(j, j);
            if (pivot==0) throw std::runtime_error("can't solve: pivot==0");
            const double mult = A(i, j)/pivot;
            A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j)); 
            b(i) -= mult * b(j);
        }
    } 
}

Vector partial_pivot_elimination(Matrix A, Vector b)
{
    elim_with_partial_pivot(A, b);
    return back_substitution(A, b);
}

int main()
{
    // Testing partial pivot, expecting x = {1 2 3 }
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

    Vector x = partial_pivot_elimination(A, B);
    std::cout << "x="   << x << std::endl;
    std::cout<< "---------------=pivot test end=---------------\n"<<std::endl;

    double c[2][2] = 
        {
            {0,1},
            {1,0}
        };
    double d[2] = {5,6};
    try
    {
        Matrix C(c);
        Vector D(d);
        classical_gaussian_elimination(C,D);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // Expecting {6,5}
    Matrix C(c);
    Vector D(d);

    std::cout << "Solving C*y=D" << std::endl;
    std::cout << "C=\n" << C << std::endl;
    std::cout << "D="   << D << std::endl;

    Vector y = partial_pivot_elimination(C,D);

    std::cout << "y="   << y << std::endl;
}