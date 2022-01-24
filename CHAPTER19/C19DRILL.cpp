//CHAPTER 19 Drill

#include <string>
#include <vector>
#include <iostream>
using namespace std;

template<typename T> //1.
struct S
{
    S(T vall){val=vall;} //2.
    T& get(); //5.
    const T& get() const; //11.
    void set(T vall); //9.

    S& operator=(const T&); //10.
private:
    T val; //7.
};

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

template < class T >
istream& operator >> (istream& is, vector<T>& v) //14.
{
    char c {0};
    while(c!='{')
        is.get(c);
    if(c!='{') return is;
    v.clear();
    T val;
    while(c!='}')
    {
        cin>>val; //trust cin
        v.push_back(val);
        is.get(c);
        if(is.fail())
        {
            is.clear(ios::failbit);
            return is;
        }
        while(c!=',' && c!='}') //seeks either a comma or }
            is.get(c);
    }
    return is;
}

template < class T >
istream& operator >> (istream& is, S<T>& s) //14.
{
    T val;
    cin>>val;
    s.set(val);
    return is;
}

template < class T >
S<T>& S<T>::operator= (const T& vall) //10.
{
    val=vall;
    return *this;
}

template < class T >
T& S<T>::get() //6.
{
    return val;
}

template < class T >
void S<T>::set(T vall) //9.
{
    val=vall;
}

template<typename T> 
void read_val(T& v) //12.
{
    cin>>v;
}

int main()
{
    S<int> a {1}; //3.
    S<char> b {'a'};
    S<double> c {1.1};
    S<string> d {"ab"};
    S<vector<int>> e {vector<int>{1,2}};
    cout<<a.get()<<'\n'<<b.get()<<'\n'<<c.get()<<'\n'<<d.get()<<'\n'<<e.get()<<'\n'; //4. 8.

    cout<<"--------\n";

    a.set(9); //9.
    cout<<a.get()<<'\n';

    a=5; //10.
    cout<<a.get()<<'\n';

    const int h {a.get()};
    S<int> f {h}; //11.

    read_val(a); //13.
    read_val(b);
    read_val(c);
    read_val(d);
    read_val(e); //{val,val,val}
    cout<<a.get()<<'\n'<<b.get()<<'\n'<<c.get()<<'\n'<<d.get()<<'\n'<<e.get()<<'\n';
}