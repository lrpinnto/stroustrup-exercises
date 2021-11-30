//Chapter 18 Try this 01

#include <iostream>
#include <vector>

using namespace std;

struct X
{
    int val;

    void out(const string& s, int nv)
        { cerr<< this << "->" << s << ":" << val << " int_from_member_function("<< nv <<")\n";}

    X(){ out("X()",0); val=0; } //default constructor
    X(int v ) { val=v; out("X(int)",v);}
    X(const X& x){val=x.val; out("X(X&) ",x.val);} //copy constructor
    X& operator=(const X& a)   //copy assignment
        { out("X::operator=()",a.val); val=a.val; return *this; } 
    ~X() { out("~X()",0); } //destructor
};

X glob(2); //global var

X copy(X a) {return a;}

X copy2(X a) {X aa=a; return aa;}

X& ref_to(X& a) {return a;}

X* make(int i) { X a(i); return new X(a);} //copies a to new X()

struct XX 
{
    X a;
    X b;
};

int main()
{
    cout<<"start of main()-------------- (global var declared before)\n";
    cout<<"local var:\t\t\t\t";
    X loc {4}; //local var
    cout<<"copy constructor:\t\t\t\t";
    X loc2 {loc}; //copy constructor
    cout<<"copy assignment:\t\t\t\t";
    loc=X{5}; //copy assignment 
    cout<<"call by value:\t\t\t\t";
    loc2=copy(loc); //call by value and return
    //i believe the difference between copy and copy2 is that the assignment operator happens at different scopes. One within the function itself and the other in main
    //both functions have the same number of calls and values except for operator=() which has a this.val=4 unlike copy2 with this.val=5
    cout<<"call by value and assignment inside function:\t\t\t\t";
    loc2=copy2(loc); // copy constructor called for both loc inside copy2 and X aa = aa
    cout<<"local var:\t\t\t\t";
    X loc3 {6};
    cout<<"call by reference and return:\t\t\t\t\n"; //no constructor/destructor appears to be called. Nothing is created therefore no constructor/destructor is called
    X& r=ref_to(loc); //call by reference and return 
    cout<<"make:\t\t\t\t";
    delete make(7);
    cout<<"make:\t\t\t\t";
    delete make(8);
    //returns copy constructor
    cout<<"vector:\t\t\t\t";
    vector<X>v(4); //default values
    //calls constructor for all elements
    cout<<"local struct with 2 X's:\t\t\t\t";
    XX loc4; //calls 2 defaults constructors
    cout<<"new call:\t\t\t\t";
    X* p = new X{9}; //an X on the free store
    cout<<"delete call:\t\t\t\t";
    delete p;
    cout<<"new call array:\t\t\t\t";
    X* pp= new X[5]; //an array of Xs on the free store
    //appears to call the constructor for every single element
    cout<<"delete call array:\t\t\t\t";
    delete[] pp; //appears to call the destructor for every single element
    cout<<"end of main()-------------- (calling destructrors now VVVVVVV\n";
}
