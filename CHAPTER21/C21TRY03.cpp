// CHAPTER 21 TRY 03

// Define a vector<Record>, initialize it with 4 records of your choice, and compute their total price using the functions above.

#include <vector>
#include <iostream>

struct Record
{
    double unit_price;
    int units;
};

template<typename In, typename T, typename BinOp>
T accumulate(In first, In last, T init, BinOp op)
{
    while (first!=last)
    {
        init=op(init, *first);
        ++first;
    }
    return init;
} 

double price(double v, const Record& r)
{
    return v + r.unit_price * r.units;
}

double f(const std::vector<Record>& vr)
{
    double total = accumulate(vr.begin(), vr.end(), 0.0, price);
    return total;
}

int main()
{
    std::vector<Record> v (4);
    v[0].unit_price=10; v[0].units=5;
    v[1].unit_price=11; v[1].units=4;
    v[2].unit_price=12; v[2].units=3;
    v[3].unit_price=13; v[3].units=2;
    std::cout<<f(v)<<std::endl;
}