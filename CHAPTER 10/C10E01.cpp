#include "../stroustrup/std_lib_facilities.h"

//CHAP 10 EX 01

//create a file with integers separated by space before running the code

int sum_all(const vector<int>& v)
{
    int sum {0};
    for (int i: v) sum+=i;
    return sum;
}

int main()
{
    cout<<"Please enter input filename: ";
    string iname;
    cin>>iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input fine",iname);

    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    vector<int>numbers;
    while(true){
        int i;
        if(!(ifs>>i)) break;
        numbers.push_back(i);
    }

    cout<<"The total sum of all numbers in "<<iname<<" is "<<sum_all(numbers)<<".\n";
}
