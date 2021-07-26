#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 12

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
        string invertedline;
        for (int i = line.size(); i >= 0; i--)
        {
            invertedline+=line[i];
        }
        cout<<invertedline<<'\n';
    }
}
