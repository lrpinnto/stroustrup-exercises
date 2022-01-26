//CHAPTER 19 EX 06

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

int main()
try {
    Number<int> copy_const {10};
    cout<<"Copy constructor(Number): "<<copy_const<<'\n';
    copy_const=11;
    cout<<"Operator=(Number) "<<copy_const<<'\n';

    Number<int> copy_constt {Number<int>(20)};
    cout<<"Copy constructor: "<<copy_constt<<'\n';
    copy_constt=Number<int>(21);
    cout<<"Operator= "<<copy_constt<<'\n';

    Number<int> abc;
    cin>>abc;
    cout<<copy_const+(copy_constt)*abc<<'\n';

    Number<double> h1{2};
    Number<int> h2{2};
    //cout<<h1%h1; //error: invalid operands of types ‘double’ and ‘double’ to binary ‘operator%’
    cout<<h2%h2<<'\n';
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}