class vector
{
private:
    int sz;
    double* elem;
public:
    vector(int szz);
    ~vector();
    double operator[](int n) {return elem[n];}
};

vector::vector(int szz)
    :sz{szz}
{
    elem = new double[sz];
}

vector::~vector()
{
    delete[] elem;
}

int main()
{
    vector v(10);
    double x = v[2];
    v[3]=x;
}

/*
C18TRY02.cpp: In function ‘int main()’:
C18TRY02.cpp:27:10: error: lvalue required as left operand of assignment
*/