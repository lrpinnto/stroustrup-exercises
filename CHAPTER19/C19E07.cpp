//Chapter 19 EX 07

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class Number
{
private:
    T num; //Class Number != Number
public:
    Number():num{0}{} //default

    Number(const T& val):num{val}{} //copy constructor (convert Number to Number)
    Number& operator=(const T& val){num=val;return *this;} //copy assignment (convert Number to Number)

    Number(const Number& val):num{val.get()}{} //copy constructor
    Number& operator=(const Number& val){num=val.get();return *this;} //copy assignment

    Number(Number&& val):num{val.get()}{val=0;} //move constructor
    Number& operator=(Number&& val) //move assignment
    {
        num=val.get();
        val=0;
        return *this;
    }

    T get() const {return num;} 
};

//arithmetic
template<typename T>
Number<T> operator+(const Number<T>& val1, const Number<T>& val2){return Number<T>(val1.get()+val2.get());}
template<typename T>
Number<T> operator-(const Number<T>& val1, const Number<T>& val2){return Number<T>(val1.get()-val2.get());}
template<typename T>
Number<T> operator*(const Number<T>& val1, const Number<T>& val2){return Number<T>(val1.get()*val2.get());}
template<typename T>
Number<T> operator/(const Number<T>& val1, const Number<T>& val2){return Number<T>(val1.get()/val2.get());}
template<class T>
Number<T> operator%(const Number<T>& val1, const Number<T>& val2){return Number<T>(val1.get()%val2.get());}

template<typename T>
ostream& operator << (ostream& os, const Number<T>& v) 
{
    return os<<v.get();
}

template<typename T>
istream& operator >> (istream& is, Number<T>& v) 
{
    int i{0};
    is>>i;
    v=i;
    return is;
}

template<typename T>
int f(const vector<Number<T>>& vt, const vector<Number<T>>& vu)
{
    vector<Number<T>> vect ;
    vector<Number<T>> v ;
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
    Number<T> temp;
    for (int i = 0; i < v.size(); i++)
    {
        temp=Number<T>(sum)+Number<T>(v[i]*vect[i]);
        sum=temp.get();
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
    vector<Number<int>> a {1,2,3,4,5,6};
    vector<Number<int>> b {1,1,1,1,1}; //if vect size() b < a then f() adds b default constructor
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