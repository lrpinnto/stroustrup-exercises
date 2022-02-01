#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 19

bool check_repeating(vector<string>names, string name)
{
    for (string h: names)
    {
        if (h==name)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string name;
    int age = 0;
    vector<int>ages;
    vector<string>names;
    cout<<"Enter \"NoName 0\" to finish the program.\n";
    while (true)
    {
        cout<<"Please enter a name followed by age:\n\t";
        cin>>name>>age;
        if (name=="NoName" && age==0)
        {
            break;
        }
        else if (check_repeating(names,name))
        {
            cout<<"\nThat name was already entered. Please pick another name!\n";
        }
        else
        {
            ages.push_back(age);
            names.push_back(name);
        }
    }
    for (int i = 0; i < names.size(); i++)
    {
        cout<<names[i]<<" aged "<<ages[i]<<".\n";
    }
}