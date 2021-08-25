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
    vector<double> v;
    int index;
public:
    Vector_iterator(const vector<double>& vv)
        : v{vv}, index{0} {}
    double* next() override {return &v[index++];} //it will return the x's value before incrementing it and after that the value of x will be + 1
};

class List_iterator : public Iterator
{
private:
    list<double> l;
    list<double>::iterator pointer;  //yet to be introduced in the book
public:
    List_iterator(const list<double>& ll)
        : l{ll}, pointer{l.begin()} {}
    double* next() override //pointers and lists not introduced yet in this chapter. Need to fully understand this code
    {
        double* p;
//if (l.size() && l.size() > distance(lis.begin(), pointer)) {
        p = &*pointer;
        pointer++;
        return p;
    }
};

ostream& operator<<(ostream& os, Iterator& ite)
{
    double* pointer;
    pointer = ite.next();
    double &value = *pointer;
    return os<<value<<'\n';
}

int main()
{
    vector<double> abc {1,2,3};
    Vector_iterator vi {abc};
    cout<<vi<<vi<<vi<<vi; //last vi returns 0. Needs if() check to avoid going out of bounds;
    list<double> cba {1,2,3};
    List_iterator li {cba};
    cout<<li<<li<<li<<li; //last vi returns gibberish. Needs if() check to avoid going out of bounds;
}
