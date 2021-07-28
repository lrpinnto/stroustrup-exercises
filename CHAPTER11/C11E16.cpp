#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 16

struct numr
{
    int number;
    int counter;
    numr(int numberr) : number{numberr}, counter{1} {}
};

int main()
{
    cout<<"Enter a text file: ";
    string iname;
    cin>>iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    vector<int>numbers;
    vector<numr> counter;
    string line;
    while(getline(ifs,line))
    {
        istringstream iss {line};
        for(int val;iss>>val;)
        {
            numbers.push_back(val);
        }
    }
    
    sort(numbers.begin(),numbers.end());
    int current_number {numbers[0]-1}; //initialize a value out of the list range
    for (int i = 0 ; i<numbers.size(); i++)
    {
        if(current_number==numbers[i]) {counter[counter.size()-1].counter++;} //get the last entry on the vector which should correspond to the current number, and increment the counter
        else counter.push_back({numbers[i]});
        current_number=numbers[i];
    }

    for (numr nm : counter)
    {
        cout<<nm.number<<'\t';
        if(nm.counter==1) cout<<'\n';
        else cout<<nm.counter<<'\n';
    }
}
