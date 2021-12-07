//Chapter 18 ex 09

#include <iostream>
#include <stdexcept>

//for now this solution will be enough as I've dealt with a similar exercise before
//https://github.com/Chrinkus/stroustrup-ppp/blob/master/chapter18/ex09_mem_layout.cpp

int gai[] = { 1, 2, 3, 4, 5 };

void f(int ai[], int sz)
{
    for (int i = 0; i < sz; ++i)
        std::cout << ai[i] << ' ' << &ai[i] << '\n';
}

int main()
{
    // code
    int lai[] = { 1, 1, 2, 3, 5 };

    int* pai = new int[5]{ 3, 6, 9, 12, 15 };

    std::cout << "Static storage:\n";
    f(gai, 5);
    std::cout << '\n';
    std::cout << "Stack storage:\n";
    f(lai, 5);
    std::cout << '\n';
    std::cout << "Free-store:\n";
    f(pai, 5);
    std::cout << '\n';

    delete[] pai;
}