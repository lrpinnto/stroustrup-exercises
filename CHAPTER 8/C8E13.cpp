#include "../stroustrup/std_lib_facilities.h"

//CAP 8 EXERCISE 13

//Q:How many seperate functions would you use for these tasks?
//A: Ideally, a function only performs a single specific task. In this case and following this rule, we would need 3 functions.
//  one for counting the chars, one to find the longest and shortest strings, and one for sorting lexicographically.

vector<int>countchars(const vector<string>& v)
{
    vector<int>result;
    for(const string& s: v) result.push_back(s.size());
    if (v.size()!=result.size()) error("mismatching vectors");
    else return result;
}

vector<string>longest_shortest(const vector<string>& v)
{
    vector<int>count=countchars(v);
    int small = count[0];
    int big = count[0];
    int smallindex = 0;
    int bigindex = 0;
    for (int i = 0; i < count.size(); i++)
    {
        if (count[i]>big)
        {
            big = count[i];
            bigindex=i;
        }
        if (count[i]<small)
        {
            small = count[i];
            smallindex=i;
        }
    }
    return {v[smallindex],v[bigindex]};
}

vector<string>lexicographically(const vector<string>& v)
{
    vector<string>result = v;
    sort(result.begin(),result.end());
    return result;
}

int main()
{
    vector<string>test = {"111","22222222","4","01","a","A","BB"};
    cout<<"countchars: ";
    for (int i : countchars(test))
    {
        cout<<i<<", ";
    }
    cout<<'\n';
    vector<string>b = longest_shortest(test);
    cout<<"shortest:"<<b[0]<<" longest: "<<b[1];
    cout<<'\n';
    
    cout<<"lexicographically: ";
    for(const string& s : lexicographically(test))
    {
        cout<<s<<", ";
    }
}