#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 15

int main()
{
    cout<<"Enter a text file: ";
    string iname;
    cin>>iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);
    cout<<"Please enter output filename: ";
    string oname;
    cin>>oname;
    ofstream ost {oname};
    if(!ost) error("can't open input file ",oname);
    vector<double>nums;
    const string delimiter {"++++++++++++++++++++++\n"};
    while(ifs.good()){
        for(double h;ifs>>h;) { nums.push_back(h); if(nums.size()==4){break;}}
        ost<< delimiter;
        for(double d : nums)
        {
            ost << scientific << setprecision(8) << '|' << setw(20) << d << "|\n";
        }
        ost<< delimiter;
        nums.clear();
    }
}
