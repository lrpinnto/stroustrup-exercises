//Chapter 19 Try this 01

#include <iostream>

class vector
{
private:
    int sz;
    double* elem;
    int space;
public:
    void resize(int newsize);
    void reserve(int newalloc);
    int capacity() const {return space;}
    int size() const {return sz;}
    vector():sz{0},elem{nullptr},space{0}{}
    ~vector(){delete[] elem;}
};

void vector::reserve(int newalloc)
{
    if (newalloc<=space) return;
    double* p = new double[newalloc];
    for(int i=0; i<sz; ++i) p[i]=elem[i];
    delete[] elem;
    elem=p;
    space=newalloc;
}
void vector::resize(int newsize)
{
    reserve(newsize); 
    if(newsize<0 || newsize==sz) return; //BUG: We cannot have sizes less than 0
                                        //also set to return when newsize is the same as sz to avoid unnecessary operations
    for (int i = sz; i < newsize; ++i) 
    {
        elem[i]=0;
    }
    sz=newsize;
}

int main()
{
    vector abc;
    abc.reserve(10);
    abc.resize(0);
    std::cout<<"0:space->"<<abc.capacity()<<":size->"<<abc.size()<<'\n';
    abc.resize(-40000);
    std::cout<<"-40000:space->"<<abc.capacity()<<":size->"<<abc.size()<<'\n';
    abc.resize(10);
    std::cout<<"10:space->"<<abc.capacity()<<":size->"<<abc.size()<<'\n';
    abc.resize(10);
    std::cout<<"10:space->"<<abc.capacity()<<":size->"<<abc.size()<<'\n';
    abc.resize(10000);
    std::cout<<"10000:space->"<<abc.capacity()<<":size->"<<abc.size()<<'\n';
    abc.resize(0);
    std::cout<<"0:space->"<<abc.capacity()<<":size->"<<abc.size()<<'\n';
}

//All edge cases are handled correctly since no new allocation will be smaller than the last one. Therefore, space will either increase or stay the same.
//Size can decrease and will be between 0 to int_max. 