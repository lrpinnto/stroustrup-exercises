#include "../stroustrup/std_lib_facilities.h"

//CHAP 10 EX 11

int main()
try {
    cout<<"Please enter input filename: ";
    string iname;
    cin>>iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    vector<int>numbers;

    while(true){
        string s;
        if(!(ifs>>s)) break; 
        if(s[0]=='-' || s[0]=='+') {if(isdigit(s[1])) numbers.push_back(stoi(s));}
        else if (isdigit(s[0])) numbers.push_back(stoi(s));
    }

    int sum {0};

    for (int h : numbers) sum+=h;
    cout<<sum;

}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}
