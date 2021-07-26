#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 13

int main()
{
    cout<<"Enter a text file: ";
    string iname;
    cin>>iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);
    string line;
    while(getline(ifs, line))
    {
        vector<string>words;
        istringstream iss {line};
        for(string ss ; iss>>ss;) words.push_back(ss);
        reverse(words.begin(), words.end());
        for (string ss : words) cout<<ss<<' ';
        cout<<'\n';
    }
}
