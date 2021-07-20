#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 02
//I assumed the word needed to be separated by whitespace to be considered. 
int main()
try {
    string iname;
    cout<<"Enter input filename: ";
    cin>>iname;
    string wordd;
    cout<<"Enter word: ";
    cin>>wordd;
    ifstream ifs {iname};
    if (!ifs) error("could not read from file ", iname);

    string lines;
    int linenum {0};
    while(getline(ifs,lines)){
        linenum++;
        istringstream ss {lines};
        for(string word; ss>>word; )
        {
            if(!ss) error("string stream error.");
            if(word==wordd) {cout<<"line "<<linenum<<'\t'<<lines<<'\n';}
        }
    }
}
catch(exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Error of unknown type\n";
    return 2;
}
