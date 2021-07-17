#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 TRY THIS

int main()
{
    cout<<"decimal "<<dec<<1900<<'\n'
        <<"hexadecimal "<<hex<<1900<<'\n'
        <<"octal "<<oct<<1900<<'\n'
        <<"age "<<100<<'\n';

    int a;
    int b;
    int c;
    int d;
    cin>>dec>>a>>hex>>b>>oct>>c>>d;
    cout<<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\n';
    //R: Stores the value as an hex/oct or dec, then outputs the dec equivalent. So if input is hex 4d2, the dec equivalent will be 1234. 

    cout<<"defaultfloat "<<defaultfloat<<1234567.89<<'\n'
        <<"fixed "<<fixed<<1234567.89<<'\n'
        <<"scientific "<<scientific<<1234567.89<<'\n';
    //R: Fixed is the most accurate as there is no rounding involved.

    //3 Row table
    cout << '|' << setw(9) << "Forename" << '|' << setw(10) << "Surname" << '|' << setw(19) << "email@mail.com" << '|' << setw(12) << "07001001000" << "|\n"
         << '|' << setw(9) << "Someone" << '|' << setw(10) << "Somewhere" << '|' << setw(19) << "someemail@mail.com" << '|' << setw(12) << "07001001000" << "|\n";
}