//Chapter 19 Ex 12

#include <iostream>
#include <fstream>
using namespace std;

class File_handle
{
private:
    fstream fs;
public:
    enum fs_modes{app,ate,bin,in,out,trunc};
    File_handle(string,fs_modes);
    ~File_handle();
    void close() //manually close the file
    {
        if(fs.is_open())
            fs.close();
    }
    fstream& get(){return fs;}
};

File_handle::File_handle(string filename,fs_modes fsm)
{
    switch (fsm)
    {
    case app:
        fs.open(filename,ios_base::app);
        break;
    case ate:
        fs.open(filename,ios_base::ate);
        break;
    case bin:
        fs.open(filename,ios_base::binary);
        break;
    case in:
        fs.open(filename,ios_base::in);
        break;
    case out:
        fs.open(filename,ios_base::out);
        break;
    case trunc:
        fs.open(filename,ios_base::trunc);
        break;
    default:
        throw("Impossible state");
        break;
    }
    
    if(!fs) throw runtime_error("can't open file "+filename);
    fs.exceptions(fs.exceptions()|ios_base::badbit);
}

File_handle::~File_handle()
{
    if(fs.is_open())
        cout<<"closing file...\n";
        fs.close();
}

int main()
try {
    cout<<"enter a filename: ";
    string filename;
    cin>>filename;
    File_handle fl {filename,File_handle::fs_modes::in};
    string s;
    getline(fl.get(),s);
    cout<<"The first line of your file is "<<s<<'\n';
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}