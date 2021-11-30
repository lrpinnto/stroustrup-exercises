//CHAPTER 18 DRILL

#include <iostream>
#include <vector>

const int ga_size {10};
int ga[ga_size]{1,2,4,8,16,32,64,128,254,512};

std::vector<int> gv {1,2,4,8,16,32,64,128,254,512};

int fact(int n)
{
    if(n > 1)
        return n * fact(n - 1);
    else
        return 1;
}
namespace drill_1{
void f(const int* int_array, const int n)
{
    int la[10];
    for (int i = 0; i < sizeof(ga)/sizeof(int); i++)
    {
        la[i]=ga[i];
        std::cout<<la[i]<<'|';
    }
    std::cout<<'\n';
    int* p {new int[n]};
    for (int i = 0; i < n; i++)
    {
        p[i]=int_array[i];
        std::cout<<p[i]<<'|';
    }
    std::cout<<'\n';
    delete[] p;
}
}

namespace drill_2{
void f(const std::vector<int>& int_vector)
{
    std::vector<int>lv(int_vector.size());
    for (int i = 0; i < ((lv.size()>gv.size()) ? gv.size() : lv.size()); i++)
    {
        lv[i]=gv[i];
    }
    for(int i : lv) std::cout<<i<<'|';
    std::cout<<'\n';
    std::vector<int>lv2 {int_vector};
    for(int i : lv2) std::cout<<i<<'|';
    std::cout<<'\n';
}
}

int main()
{
    drill_1::f(ga,ga_size);
    int aa[10]{fact(1),fact(2),fact(3),fact(4),fact(5),fact(6),fact(7),fact(8),fact(9),fact(10)};
    drill_1::f(aa,10);

    std::cout<<"\n\n";//-----------

    drill_2::f(gv);
    std::vector<int> vv{fact(1),fact(2),fact(3),fact(4),fact(5),fact(6),fact(7),fact(8),fact(9),fact(10)};
    drill_2::f(vv);
}