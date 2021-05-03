#include "../stroustrup/std_lib_facilities.h"
#include "C802.cpp"

//CAP 8 EXERCISE 9

class string_stream
{
    private:
        vector<double>ages;
        vector<string>names;
        bool getting_ints = false;

    public:
        void get();
        int get_int(const string&);
        string get_string();
        void print(bool);

};

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}




void string_stream::get()
{
    
    string s;
    while(true)
    {
        cin>>s;
        if(!cin) error("weird input");
        if(is_number(s))
        { 
             
            getting_ints=true;
            ages.push_back(stoi(s));
            if (ages.size()==names.size()) return; 
        }
        else
        {
            if(getting_ints) error("Expected an integer.");
            names.push_back(s);

        }
    }
}

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

void string_stream::print(bool sorted)
{
    if (sorted)
    {
        vector<string>copy_names = names;
        vector<double>ages_sorted ;

        sort(names.begin(),names.end());
        vector<int>sort_order;
        for (string s : names)
        {
            sort_order.push_back(get_index_n(s,copy_names));
        }

        for (int i : sort_order)
        {
            ages_sorted.push_back(ages[i]);
        }
        str_printer("sorted",names,ages_sorted);
    }
    else str_printer("unsorted",names,ages);
    
}

double sum_price_weight(const vector<double>& price, const vector<double>& weight)
{
    if(price.size()!=weight.size()) error("vectors need to be same size");
    double sum=0;
    for (int i = 0; i < price.size(); i++)
    {
        sum+=price[i]*weight[i];
    }
    return sum;
    
}

int maxv(const vector<double>& v)
{
    double high = v[0];
    int high_int=0;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i]>high) 
        {
            high=v[i];
            high_int=i;
        }
    }
    return high_int;
    
}



int main()
{
    vector<double>price={1.1,2.2,3.3};
    vector<double>weight={1,2,3};
    cout<<sum_price_weight(price,weight)<<" "<<maxv(price)<<"=2";

    string_stream ss;
    ss.get();

    ss.print(false);
    ss.print(true);    
}