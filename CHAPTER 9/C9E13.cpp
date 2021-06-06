#include "../stroustrup/std_lib_facilities.h"

//Q: Why would people want to use a Rational class?
//A: No precision is lost. For example, while handling infinitely long numbers

class rational
{
private:
    int numerator;
    int denominator;
public:
    rational(int numerator, int denominator);
    double aprox() const {return (numerator*1.0)/denominator;}  //returns aproximation as double
    int num() const {return numerator;}  //returns numerator as int
    int den() const {return denominator;} //returns denominator as int
};

int lcm(const int& a, const int& b)  //math function it's probably not called "lcm"
{
    int max = (a > b) ? a : b;
    while (true){
        if (a%max==0 && b%max==0)
        {
            return max;
        }
        else max--;
    }
    return max;
}

rational::rational(int num, int den)
    :numerator{num},denominator{den}
{
    if(den==0) error("cannot divide by 0");
}

ostream& operator<<(ostream& os, const rational& d)
{
    return os << d.num() << '/' << d.den();
}

rational operator+(const rational& a, const rational& b)
{
    int common_den  {a.den()*b.den()};
    int new_num {a.num()*b.den()+b.num()*a.den()};
    return rational(new_num/lcm(new_num,common_den),common_den/lcm(new_num,common_den));
}
rational operator-(const rational& a, const rational& b)
{
    int common_den  {a.den()*b.den()};
    int new_num {a.num()*b.den()-b.num()*a.den()};
    return rational(new_num/lcm(new_num,common_den),common_den/lcm(new_num,common_den));
}

rational operator*(const rational& a, const rational& b)
{
    return rational(a.num()*b.num(),a.den()*b.den());
}

rational operator/(const rational& a, const rational& b)
{
    return rational(a.num()*b.den(),a.den()*b.num());
}

bool operator==(const rational& a, const rational& b)  
{
    rational reduced_a {a.num()/lcm(a.num(),a.den()),a.den()/lcm(a.num(),a.den())};
    rational reduced_b {b.num()/lcm(b.num(),b.den()),b.den()/lcm(b.num(),b.den())};
    return (reduced_a.num()==reduced_b.num() && reduced_a.den()==reduced_b.den());
}

bool operator!=(const rational& a, const rational& b)  
{
    return !(a==b);
}

int main()
{
    rational h {1,2};
    rational b {2*40,4*40};
    cout<<(h==b);
}
