#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 14

struct dictionary
{
    dictionary(string ss, int ii)
        :s(ss), i(ii) {}
    dictionary(string ss)
        :s(ss), i(0) {}

    dictionary operator++(int)
    {
        i++;
    }

    int get_count() const
    {
        return i;
    }
private:
    string s;
    int i;    
};

int main()
{
    cout<<"Enter a text file: ";
    string iname;
    cin>>iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    dictionary space {"space"};
    dictionary alpha {"alpha"};
    dictionary digit {"digit"};
    dictionary xdigit {"xdigit"};
    dictionary upper {"upper"};
    dictionary lower {"lower"};
    dictionary alnum {"alnum"};
    dictionary cntrl {"cntrl"};
    dictionary punct {"punct"};
    dictionary print {"print"};
    dictionary graph {"graph"};

    char ch;
    while(ifs.get(ch))
    {
        if (isspace(ch)) {space++;}
        if (isalpha(ch)) {alpha++;}
        if (isdigit(ch)) {digit++;}
        if (isxdigit(ch)) {xdigit++;}
        if (isupper(ch)) {upper++;}
        if (islower(ch)) {lower++;}
        if (isalnum(ch)) {alnum++;}
        if (iscntrl(ch)) {cntrl++;}
        if (ispunct(ch)) {punct++;}
        if (isprint(ch)) {print++;}
        if (isgraph(ch)) {graph++;}
    }

    cout << "space: " << space.get_count() << '\n';
    cout << "alpha: " << alpha.get_count() << '\n';
    cout << "digit: " << digit.get_count() << '\n';
    cout << "xdigit: " << xdigit.get_count() << '\n';
    cout << "upper: " << upper.get_count() << '\n';
    cout << "lower: " << lower.get_count() << '\n';
    cout << "alnum: " << alnum.get_count() << '\n';
    cout << "cntrl: " << cntrl.get_count() << '\n';
    cout << "punct: " << punct.get_count() << '\n';
    cout << "print: " << print.get_count() << '\n';
    cout << "graph: " << graph.get_count() << '\n';
}
