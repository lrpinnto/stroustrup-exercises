#include "../stroustrup/std_lib_facilities.h"

//CHAP 10 EX 08

int main()
try {
    cout<<"Please enter input filename: ";
    string iname;
    cin>>iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input fine",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    vector<string> text;

    while(true){
        string s;
        if(!(getline(ifs,s))) break;  //getline() won't ignore whitespace and newline
        text.push_back(s);
    }

    cout<<"\nPlease enter another input filename: ";
    cin>>iname;
    ifstream ifs2 {iname};
    if (!ifs2) error("can't open input fine",iname);
    ifs2.exceptions(ifs2.exceptions()|ios_base::badbit);

    while(true){
        string s;
        if(!(getline(ifs2,s))) break;
        text.push_back(s);
    }

    cout<<"Please enter output filename: ";
    string oname;
    cin>>oname;
    ofstream ost {oname};
    if(!ost) error("can't open input file ",oname);

    for (string s : text)
    {
        ost<<s<<'\n';
    }

}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}
