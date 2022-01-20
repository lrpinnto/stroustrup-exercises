//Chapter 19 Try this 01 - Unsure how to handle this question

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
    reserve(newsize); //already deals with negative and 0 values
    for (int i = sz; i < newsize; i++) 
    {
        elem[i]=0;
    }
    sz=newsize;
}

//newsize>old alloc
//newsize>old size && newsize<=old alloc
//newsize==old size
//newsize<old size

int main()
{
    vector abc;
    abc.reserve(10);
    //abc.resize(-77);
}