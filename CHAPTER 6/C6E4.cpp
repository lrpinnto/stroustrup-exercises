#include "../stroustrup/std_lib_facilities.h"

//CAP 6 EX 04

class Name_value{
    public:
        string something;
        int value;
        Name_value(string n, int v)
            :something(n), value(v) {}
};

bool check_repeating(vector<Name_value>names, string name)
{
    for (Name_value h: names)
    {
        if (h.something==name)
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
    vector<Name_value> list;
    while (true)
    {
        cout<<"Please enter a name followed by age:\n\t";
        cin>>name>>age;
        if (name=="NoName" && age==0)
        {
            break;
        }
        else if (check_repeating(list,name))
        {
            cout<<"\nThat name was already entered. Please pick another name!\n";
        }
        
        else
        {
            list.push_back(Name_value{name, age});
        }
    }
    for (int i = 0; i < list.size(); i++)
    {
        cout<<list[i].something<<" aged "<<list[i].value<<".\n";
    }
    
    
}