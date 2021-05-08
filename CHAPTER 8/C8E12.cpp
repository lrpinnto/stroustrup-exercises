#include "../stroustrup/std_lib_facilities.h"

//CAP 8 EXERCISE 12

void print_until_s(const vector<string>& v, const string& quit)
    // improved by passing const-ref
{
    for (const string& s : v) {
        if (s == quit) return;
        cout << s << '\n';
    }
}

void print_until_ss(const vector<string>& v, const string& quit) //note: doesn't print "quit"
{
    int count = 0;
    for (const string& s : v) {
        if (s == quit && count==1) return;
        else if (s == quit && count ==0)
        {
            count=1;
        }
        else cout << s << '\n';
    }
}


int main()
{
    vector<string>test={"0","1","2","3","4","5","6","7","8","9","0","1","2","3","4","5","6","7","8","9","0","1"};
    print_until_ss(test,"0");
}