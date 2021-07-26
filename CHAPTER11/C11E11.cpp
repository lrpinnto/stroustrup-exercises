#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 11

void apply_whitespace(string& s, const string& w)
{
    for(char& ch : s)
    {
        for(char cw : w) if(ch==cw) {ch=' ';};
    }
}

vector<string>split(const string& s, const string& w )
{
    string ss = s;
    apply_whitespace(ss,w);
    istringstream iss {ss};
    vector<string>list;
    for(string st; iss>>st;)
    {
        list.push_back(st);
    }
    return list;
}

int main()
{
    string s {"this/is-a.test£string,"};
    string whitespace {"/-.,£"};
    for(string st : split(s,whitespace))
    {
        cout<<st<<'\n';
    }
}
