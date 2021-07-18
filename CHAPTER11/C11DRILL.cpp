#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 DRILL
//this drill is essentially a repetition of what was already asked on "Try this" challenges

int main()
{
    int birth_year {1900};
    cout<<"decimal "<<dec<<'\t'<<showbase<<birth_year<<'\n'
        <<"hexadecimal "<<hex<<'\t'<<showbase<<birth_year<<'\n'
        <<"octal "<<oct<<"\t\t"<<showbase<<birth_year<<'\n';

    cout<<dec<<birth_year;
}