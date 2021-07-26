#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 10

vector<string>split(const string &s)
{
    istringstream iss {s};
    vector<string>list;
    for(string st; iss>>st;)
    {
        list.push_back(st);
    }
    return list;
}

int main()
{
    string s {"this is a test string."};
    for(string st : split(s))
    {
        cout<<st<<'\n';
    }
}
