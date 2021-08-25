//CHAPTER 14 EX 15

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Iterator
{
private:
    /* data */
public:
    virtual double* next() = 0; //pure virtual function
};

class Vector_iterator : public Iterator
{
private:
    /* data */
public:
    Vector_iterator(const vector<double>& v){}
    double* next() override {}
};

class List_iterator : public Iterator
{
private:
    /* data */
public:
    List_iterator(const list<double>& l){}
    double* next() override {}
};
