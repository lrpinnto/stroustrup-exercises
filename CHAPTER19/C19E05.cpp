//CHAPTER 19 EX 05

#include <iostream>
//I had an idea to either use vector or a similar array structure to implement a "long int" but the exercise specifically asks for a single member of class int
using namespace std;

class Int
{
private:
    int num; //Class Int != int
public:
    Int():num{0}{} //default

    Int(const int& val):num{val}{} //copy constructor (convert int to Int)
    Int& operator=(const int& val){num=val;return *this;} //copy assignment (convert int to Int)

    Int(const Int& val):num{val.get()}{} //copy constructor
    Int& operator=(const Int& val){num=val.get();return *this;} //copy assignment

    Int(Int&& val):num{val.get()}{val=0;} //move constructor
    Int& operator=(Int&& val) //move assignment
    {
        num=val.get();
        val=0;
        return *this;
    }

    int get() const {return num;} 
};

//arithmetic
Int operator+(const Int& val1, const Int& val2){return Int(val1.get()+val2.get());}
Int operator-(const Int& val1, const Int& val2){return Int(val1.get()-val2.get());}
Int operator*(const Int& val1, const Int& val2){return Int(val1.get()*val2.get());}
Int operator/(const Int& val1, const Int& val2){return Int(val1.get()/val2.get());}

ostream& operator << (ostream& os, const Int& v) 
{
    return os<<v.get();
}

istream& operator >> (istream& is, Int& v) 
{
    int i{0};
    is>>i;
    v=i;
    return is;
}

int main()
try {
    Int copy_const {10};
    cout<<"Copy constructor(int): "<<copy_const<<'\n';
    copy_const=11;
    cout<<"Operator=(int) "<<copy_const<<'\n';

    Int copy_constt {Int(20)};
    cout<<"Copy constructor: "<<copy_constt<<'\n';
    copy_constt=Int(21);
    cout<<"Operator= "<<copy_constt<<'\n';

    Int abc;
    cin>>abc;
    cout<<-1+copy_const+(copy_constt/21)*abc;
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}