//Chapter 17 DRILL
#include <iostream>
#include <vector>
using namespace std;

void print_array10(ostream& os, int* a) //4.
{
    //assumed to have 10 elements
    for (int i = 0; i < 10; i++)
    {
        os<<a[i];
    }
    cout<<'\n';
}

void print_array(ostream& os, int* a, int n) //7.
{
    for (int i = 0; i < n; i++)
    {
        os<<a[i];
    }
    cout<<'\n';
}

void print_vector(ostream& os, vector<int>v)
{
    for(int i : v) os<<i;
    cout<<'\n';
}

int main()
{
    const int array_size {10};
    int* pi = new int[array_size];  //1.
    for (int i = 0; i < array_size; i++) 
    {
        cout<<pi[i];  //2.
    }
    cout<<'\n';
    delete[] pi; //3.

    int* qi = new int[10]{100,101,102,103,104,105,106,107,108,109}; //5.
    //unable to initialize with implicit number of elements as describe in the book -> new int[]{100,101,...}
    print_array10(cout,qi);
    int* ri = new int[11]{100,101,102,103,104,105,106,107,108,109,110}; //6.
    print_array10(cout,ri);
    cout<<ri[10]<<'\n';
    int* ti = new int[20]{100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119}; //8.
    print_array(cout,ti,20);
    delete[] qi;//9.
    delete[] ri;
    delete[] ti;

    //10.
    vector<int>a {100,101,102,103,104,105,106,107,108,109};
    vector<int>b {100,101,102,103,104,105,106,107,108,109,110};
    vector<int>c {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119};
    print_vector(cout,a);
    print_vector(cout,b);
    print_vector(cout,c);

    //SECOND PART
    cout<<"-----------\n";

    int* p1 {new int {7}}; //2.1
    cout<<p1<<'\t'<<*p1<<'\n'; //2.2
    int* p2 {new int[7]{1,2,4,8,16,32,64}}; //2.3
    cout<<p2<<'\t'; print_array(cout,p2,7); //2.4

    int* p3 {p2}; //2.5
    p2=p1; //2.6
    p2=p3; //2.7
    cout<<p1<<'\t'; print_array(cout,p1,1); cout<<p2<<'\t'; print_array(cout,p2,7); //2.8

    delete[] p1; //2.9
    delete[] p2;
    //delete[] p3;  //this attempts to delete p2 when it no longer exists
    p1 =new int[10]{1,2,4,8,16,32,64,128,264,512}; //2.10
    p2 =new int[10]; //2.11
    
    for (int i = 0; i < 10; i++)
    {
        p2[i] = p1[i]; //2.12
    }
    cout<<p1<<'\t'; print_array(cout,p1,10);
    cout<<p2<<'\t'; print_array(cout,p2,10);
    delete[] p1;
    delete[] p2;
    //2.13

    vector<int>v1 {1,2,4,8,16,32,64,128,264,512};
    vector<int>v2 (10);
    v2=v1;
    for(int i : v1) cout<<i; cout<<'\n';
    for(int i : v2) cout<<i; cout<<'\n';
}