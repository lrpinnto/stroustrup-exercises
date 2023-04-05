// CHAPTER 24 DRILL

#include <iostream>
#include "../stroustrup/Matrix.h"
#include "../stroustrup/MatrixIO.h"
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <complex>
#include <numeric>

using namespace Numeric_lib;

void sizes_types()
{
    std::cout<<"char: "<<sizeof(char)<<" bytes.\t"<<"short: "<<sizeof(short)<<" bytes.\t"<<"int: "<<sizeof(int)<<" bytes.\t"
            <<"long: "<<sizeof(long)<<" bytes.\t"<<"float: "<<sizeof(float)<<" bytes.\t"<<"double: "<<sizeof(double)<<" bytes.\t"
            <<"int*: "<<sizeof(int*)<<" bytes.\t"<<"double*: "<<sizeof(double*)<<" bytes."<<std::endl;
}

void sizes_matrix()
{
    Matrix<int> a (10);
    Matrix<int> b (100);
    Matrix<double> c (10);
    Matrix<int,2> d (10,10);
    Matrix<int,3> e (10,10,10);
    std::cout<<"1D: "<<a.size()<< " elements: "<<sizeof(a)<<" bytes.\t"<<b.size()<<" elements: "<<sizeof(b)<<" bytes.\t"<<c.size()<<" elements(doubles): "<<sizeof(c)<<" bytes.\t"
            <<"2D: 10x10="<<d.size()<<": "<<sizeof(d)<<" bytes.\t"<<"3D: 10x10x10="<<e.size()<<": "<<sizeof(e)<<" bytes."<<std::endl;
}

int main()
{
    // 1.
    sizes_types();
    // 2. 3.
    sizes_matrix();
    // 4.
    std::cout<<"input 5 ints to sqrt():\n";
    for (int i = 0; i < 5; i++)
    {
        errno=0;
        int x;
        if(!(std::cin>>x)) throw std::runtime_error("Wrong input");
        int y = sqrt(x);
        if(errno==EDOM) std::cerr<<"The square root of "<<x<<" is outside the real domain.\n";
        else std::cout<<"The square root of "<<x<<" is "<<y<<'\n';
    }
    // 5.
    std::cout<<"input 10 doubles to 1D Matrix:\n";
    Matrix<double> m (10);
    for (int i = 0; i < 10; i++)
    {
        double d;
        if(!(std::cin>>d)) throw std::runtime_error("Wrong input");
        m[i]=d;
    }
    std::cout<<m<<std::endl;
    // 6.
    int nTable,mTable;
    std::cout << "Multiplication table\nn:";
    if(!(std::cin >> nTable)) throw std::runtime_error("Invalid n");
    std::cout << "m:";
    if(!(std::cin >> mTable)) throw std::runtime_error("Invalid m");
    Matrix<double,2> table(nTable,mTable);

    for (size_t j = 0; j < mTable; j++)
    {
        for (size_t i = 0; i < nTable; i++)
        {
            if (i==0 || j==0)
            {
                table[i][j]= i>0 ? i : j;
            }
            else table[i][j]= i*j;
        }
    }
    
    for (int j = 0; j < table.dim2(); ++j) {
        for (int i = 0; i < table.dim1(); ++i)
            std::cout << std::setw(5) << table(i,j);
        std::cout << '\n';
    }
    // 7.
    Matrix<std::complex<int>> complexTable (10);

    std::cout<<"Read complex values into a Matrix. Use (real,imaginary) for complex values.\n";
    for (size_t i = 0; i < complexTable.size(); i++)
        if(!(std::cin>>complexTable[i])) throw std::runtime_error("Wrong input");

    std::cout<<complexTable<<'\n';
    std::cout<<"accumulate: "<<std::accumulate(complexTable.data(),complexTable.data()+complexTable.size(),std::complex<int>())<<std::endl;
    // 8.
    Matrix<int,2> mM (2,3);
    for (size_t j = 0; j < mM.dim1(); j++)
    {
        for (size_t i = 0; i < mM.dim2(); i++)
        {
            std::cout<<'('<<i<<','<<j<<"):";
            if(!(std::cin>>mM[j][i])) throw std::runtime_error("bad input");
        } 
    }
    std::cout<<mM<<std::endl;
}