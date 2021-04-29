#include "../stroustrup/std_lib_facilities.h"
#include "C802.cpp"

//CAP 8 EXERCISE 3

void str_printer(string label, const vector<string>& words)
{
    cout << label << ": ";

    for (string s : words)
        cout << s << ' ';

    cout << '\n';
}

void fibonacci(int x, int y, vector<string>& v, int n)
{
    v={to_string(x),to_string(y)};
    while(v.size()<n)
    {
        v.push_back(to_string(stoi(v[v.size()-2])+stoi(v[v.size()-1])));
    }

}

vector<string>reverse_fibo(const vector<string>& v)
{
    vector<string>vec=v;
    reverse(vec.begin(),vec.end());
    return vec;
}

void reverse_noret(vector<string>& v)
{
    reverse(v.begin(),v.end());
}

int main()
{
    vector<string>abc={"1","2","3","4"};
    str_printer("test",abc);
    fibonacci(1,2,abc,10);
    str_printer("test vector changed",abc);
    str_printer("test reverse_fibo()",reverse_fibo(abc));
    reverse_noret(abc);
    str_printer("test reverse_noret()",abc);
}