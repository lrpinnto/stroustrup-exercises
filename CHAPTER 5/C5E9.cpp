#include "/home/pinto/stroustrup/std_lib_facilities.h"

//CAP 5 EX 09

//no idea what he is asking for

int main ()
try {
    vector<int>numbers;
    int n = 0;
    int sum = 0;
    cout<<"Please enter the number of values you want to sum:";
    cin>>n;
    cout<<"\nPlease enter some integers (press | to stop):";
    cout<<std::numeric_limits<int>::max();
    for (int i; cin>>i;)
    {
        if(i>std::numeric_limits<int>::max())error("Null value!");
        cout<<i;
        numbers.push_back(i);
    }
    if (numbers.size() < n) error("Less values provided than initially indicated.\n");
    
    cout<<"The sum of the first "<<n<<" numbers ( ";
    for (int i = 0; i < n; i++)
    {
        cout<<numbers[i]<<" ";
        sum+=numbers[i];
    }
    cout<<") is "<<sum<<".\n";

    return 0;
}

catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception!\n";
    return 2;
}