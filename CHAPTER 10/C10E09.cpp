#include "../stroustrup/std_lib_facilities.h"

//CHAP 10 EX 09

int main()
try {
    cout<<"Please enter input filename: ";
    string iname;
    cin>>iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    vector<string> text1;
    vector<string> text2;

    while(true){
        string s;
        if(!(ifs>>s)) break;  
        text1.push_back(s);
    }

    cout<<"Please enter another input filename: ";
    cin>>iname;
    ifstream ifs2 {iname};
    if (!ifs2) error("can't open input file",iname);
    ifs2.exceptions(ifs2.exceptions()|ios_base::badbit);

    while(true){
        string s;
        if(!(ifs2>>s)) break;
        text2.push_back(s);
    }

    cout<<"Please enter output filename: ";
    string oname;
    cin>>oname;
    ofstream ost {oname};
    if(!ost) error("can't open input file ",oname);

    int size1 {int(text1.size())};
    int size2 {int(text2.size())};

    int bigger_text = size2;
    if (size1>=size2) bigger_text=size1;

    for (int i = 0; i<bigger_text ; i++)
    {
        if(size1>i) ost<<text1[i]<<' ';
        if(size2>i) ost<<text2[i]<<' ';
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
