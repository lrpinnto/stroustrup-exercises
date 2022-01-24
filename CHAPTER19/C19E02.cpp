//Chapter 19 EX 02

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
int f(const vector<T>& vt, const vector<T>& vu)
{
    vector<T> vect ;
    vector<T> v ;
    if(vt.size()>vu.size())
    {
        vect =vu;
        v =vt;
        vect.resize(vt.size());
    }
    else
    {
        vect =vt;
        v =vu;
        vect.resize(vu.size());
    }
    if(v.size()!=vect.size()) throw runtime_error("vectors size() not equal");
    int sum {0};
    for (int i = 0; i < v.size(); i++)
    {
        sum+=v[i]*vect[i];
    }
    return sum;
}

template < class T >
ostream& operator << (ostream& os, const vector<T>& v) //cout behaviour for vector<int> (and any other typename)
{
    os << "[";
    for (typename vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        os << " " << *ii;
    }
    os << "]";
    return os;
}

int main()
try {
    vector<int> a {1,2,3,4,5,6};
    vector<int> b {1,1,1,1,1}; //if vect size() b < a then f() adds b default constructor
    cout<<f(a,b);
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}