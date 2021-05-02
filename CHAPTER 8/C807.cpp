#include "../stroustrup/std_lib_facilities.h"
#include "C802.cpp"

//CAP 8 EXERCISE 3

void str_printer(string label, const vector<string>& words, const vector<double>& numbers)
{
    cout << label << ": ";

    for (int i = 0; i<words.size(); i++)
        cout << words[i] <<" "<<numbers[i] << ' ';

    cout << '\n';
}

int get_index_n (string s, vector<string>vect)
{
    for (int i = 0; i < vect.size(); i++) if (s==vect[i]) return i;
    error("No index found.");
    return 0;
}



int main()
{
    vector<string>name;
    vector<double>age;
    string nam;
    cout<<"names?\n";
    while(name.size()<5)
    {
        cin>>nam;
        name.push_back(nam);
    }
    double ag;
    cout<<"ages?\n";
    while(age.size()<5)
    {
        cin>>ag;
        age.push_back(ag);
    }

    str_printer("unsorted",name,age);

    vector<string>copy_names = name;
    vector<double>ages ;

    sort(name.begin(),name.end());
    vector<int>sort_order;
    for (string s : name)
    {
        sort_order.push_back(get_index_n(s,copy_names));
    }

    for (int i : sort_order)
    {
        ages.push_back(age[i]);
    }

    str_printer("sorted",name,ages);
    

    
}