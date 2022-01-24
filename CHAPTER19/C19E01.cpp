//Chapter 19 EX 01
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
vector<T>& f(vector<T>& a, const vector<T>& b)
{
    vector<T> vect {b};
    vect.resize(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        a[i]+=vect[i];
    }
    return a;
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