#include "../stroustrup/std_lib_facilities.h"

//Q: Why would people want to use a Rational class?
//A: No precision is lost. For example, while handling infinitely long numbers

//----------------------------- rational
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
//----------------------------- rational

//----------------------------- money
class Money
{
private:
    long int cents;
    int currency;
public:
    Money(double dollars, int currency);
    long int raw_money() const {return cents;}
    long int get_dollars() const {return cents*0.01;}
    char get_currency() const {return currency;}    //converts int to char to avoid narrow cast error with multi-character chars like €
    string get_cents() const {
        //return cents%100;
        int scents {cents%100};
        if (scents<10)
        {
            return "0"+to_string(scents);
        }
        else return to_string(scents);
    }
};


Money::Money(double dollarss, int currencyy)
    :currency{currencyy}
{    
    long int dollar = dollarss; //41,556
    double cent = (dollarss-dollar)*100; //55,6
    int centz = cent; //55
    cent = cent-centz; //0,6
    if (cent<0.5)
    {
        cent=floor(cent);
    }
    else cent=ceil(cent);

    centz+=cent;

    cents = (dollar*100)+centz;
}

ostream& operator<<(ostream& os, const Money& d)
{
    return os << d.get_currency() << d.get_dollars() << '.' << d.get_cents();
}

istream& operator>>(istream& is, Money& d)  //cannot handle multi-character chars
{
    int dollar, cents;
    char ch, currency;
    
    is>>currency>>dollar>>ch>>cents;
    if(!is) return is;
    if(ch!='.') is.clear(ios_base::failbit);
    int size_of_cents {to_string(cents).length()};

    double result {dollar+cents*(1/(pow(10,size_of_cents)))};
    
    d = Money(result,currency);
    return is;
}

Money operator+(const Money& a, const Money& b)
{
    if (a.get_currency()!=b.get_currency()) error("Money needs to have same currency");
    double result {};
    int carryover {0};
    int cents {stoi(a.get_cents())+stoi(b.get_cents())};
    if (cents>99)
    {
        cents-=100;
        carryover=1;
    }
    result = a.get_dollars()+b.get_dollars()+carryover+cents*0.01;
    return {result,a.get_currency()};
}
Money operator-(const Money& a, const Money& b)
{
    if (a.get_currency()!=b.get_currency()) error("Money needs to have same currency");
    long int dolares {(a.raw_money()-b.raw_money())*0.01}; //easier to work with raw values
    int centz  {(a.raw_money()-b.raw_money())%100};

    return {dolares+centz*0.01,a.get_currency()};

}

//----------------------------- money

int main()
{
    Money teste {1.99,'€'};
    Money teste2 {2,'€'};
    cout<<"Please enter a value:\n";
    cin>>teste;
    cout<<teste;
}
