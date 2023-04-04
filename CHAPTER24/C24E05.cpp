// CHAPTER 24 EX 05

// Cause tge gaussian elimination to fail and then try with elim_with_partial_pivot()

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
}