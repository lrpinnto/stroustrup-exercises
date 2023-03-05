#include <iostream>

template<typename T>
class Number
{
private:
    T num; //Class Number != Number
public:
    Number():num{T()}{} //default

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
template<typename T, typename U>
Number<T> operator+(const Number<T>& val1, const Number<U>& val2){return Number<T>(val1.get()+val2.get());}
template<typename T, typename U>
Number<T> operator-(const Number<T>& val1, const Number<U>& val2){return Number<T>(val1.get()-val2.get());}
template<typename T, typename U>
Number<T> operator*(const Number<T>& val1, const Number<U>& val2){return Number<T>(val1.get()*val2.get());}
template<typename T, typename U>
Number<T> operator/(const Number<T>& val1, const Number<U>& val2){return Number<T>(val1.get()/val2.get());}
template<typename T, typename U>
Number<T> operator%(const Number<T>& val1, const Number<U>& val2){return Number<T>(val1.get()%val2.get());}

template<typename T>
std::ostream& operator << (std::ostream& os, const Number<T>& v) 
{
    return os<<v.get();
}

template<typename T>
std::istream& operator >> (std::istream& is, Number<T>& v) 
{
    int i{0};
    is>>i;
    v=i;
    return is;
}