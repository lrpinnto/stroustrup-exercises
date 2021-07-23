#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 09

int main()
{
    cout<<"Please enter input file name\n";
    string iname;
    cin>>iname;
    ifstream ifs {iname,ios_base::binary};

    if(!ifs) error("can't open input file ",iname);
    
    cout<<"Please enter output file name\n";
    string oname;
    cin>>oname;
    ofstream ofs {oname, ios_base::binary}; //note: stream mode
        // binary tells the stream not to try anything clever with the bytes
    if(!ofs) error("can't open output file ",oname);

    vector<int> v;

    //read from binary file:
    for(int x; ifs.read( as_bytes(x), sizeof(int) ); )
        v.push_back(x);

    //do something with v

    for(int x : v)
        ofs.write(as_bytes(x),sizeof(int));
    return 0;
}
