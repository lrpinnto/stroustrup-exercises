//Chapter 17 Try this 01

#include <iostream>
#include <vector>

using namespace std;

void sizes(char ch, int i, int* p, bool b, double d, float f, string s) //reports number of bytes
{
    cout<<"the size of char is "<<sizeof(char)<<' '<<sizeof(ch)<<'\n';
    cout<<"the size of int is "<<sizeof(int)<<' '<<sizeof(i)<<'\n';
    cout<<"the size of int* is "<<sizeof(int*)<<' '<<sizeof(p)<<'\n';
    cout<<"the size of bool is "<<sizeof(bool)<<' '<<sizeof(b)<<'\n';
    cout<<"the size of double is "<<sizeof(double)<<' '<<sizeof(d)<<'\n';
    cout<<"the size of float is "<<sizeof(float)<<' '<<sizeof(f)<<'\n';
    cout<<"the size of string is "<<sizeof(string)<<' '<<sizeof(s)<<'\n';
}

int main()
{
    int x = 17;
    int* pi = &x;

    double e = 2.71828;
    double* pd = &e;

    cout << "pi=="<< pi <<"; contents of pi =="<<*pi<<"\n";
    cout << "pd=="<< pd <<"; contents of pd =="<<*pd<<"\n";

    cout << "-----------------------\n";

    char ch = 'a';
    bool b = true;
    float f = 1.9281;
    string s = "some random text.";

    sizes(ch,x,pi,b,e,f,s);

    cout << "-----------------------\n";

    vector<int>v(1000);
    cout << "the size of vector<int>(1000) is "<< sizeof(v)<<'\n'; //should be 20 according to book. Getting 24
}
