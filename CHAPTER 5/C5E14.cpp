#include "../stroustrup/std_lib_facilities.h"

//CAP 5 EX 14

//dictionary
const vector<string> sun_var = { "Sunday", "sunday", "Sun", "sun" };
const vector<string> mon_var = { "Monday", "monday", "Mon", "mon" };
const vector<string> tues_var = { "Tuesday", "tuesday", "Tues", "tues" };
const vector<string> wed_var = { "Wednesday", "wednesday", "Wed", "wed" };
const vector<string> thur_var = { "Thursday", "thursday", "Thur", "thur" };
const vector<string> fri_var = { "Friday", "friday", "Fri", "fri" };
const vector<string> sat_var = { "Saturday", "saturday", "Sat", "sat" };

int weekdays(string s)
{
    constexpr int stop_cin_input = 99;
    constexpr int weird_input = 101;

    for (string h : sun_var)
    {
        if(h==s) return 1;
    }
    for (string h : mon_var)
    {
        if(h==s) return 2;
    }
    for (string h : tues_var)
    {
        if(h==s) return 3;
    }
    for (string h : wed_var)
    {
        if(h==s) return 4;
    }
    for (string h : thur_var)
    {
        if(h==s) return 5;
    }
    for (string h : fri_var)
    {
        if(h==s) return 6;
    }
    for (string h : sat_var)
    {
        if(h==s) return 7;
    }
    if (s=="stop" || s=="end" || s=="exit" || s=="quit")
    {
        return stop_cin_input; //set to stop cin
    }
    return weird_input; //set to ignore input
}

double vector_sum(vector<int>input)
{
    double sum = 0;
    for (double i : input)
    {
        sum+=i;
    }
    return sum;
}

int main()
try
{
    vector<int> sun_vals;
    vector<int> mon_vals;
    vector<int> tues_vals;
    vector<int> wed_vals;
    vector<int> thur_vals;
    vector<int> fri_vals;
    vector<int> sat_vals;

    bool stop=false;
    int reject_count = 0;
    string day ;
    int val;
    while (!stop)
    {
        cin>>day;
        if (day=="stop" || day=="end" || day=="exit" || day=="quit") break;
        if(!cin) error("Weird Input!");
        cin>>val;
        if(!cin) error("Weird Input!");
        switch (weekdays(day))
        {
        case 1:
            sun_vals.push_back(val);
            break;
        case 2:
            mon_vals.push_back(val);
            break;
        case 3:
            tues_vals.push_back(val);
            break;
        case 4:
            wed_vals.push_back(val);
            break;
        case 5:
            thur_vals.push_back(val);
            break;
        case 6:
            fri_vals.push_back(val);
            break;
        case 7:
            sat_vals.push_back(val);
            break;
        case 99:
            stop=true;
            break;
        default: //ignore input (101). do nothung.
            reject_count++;
            break;
        }
    }
    cout<<"Sum days of the week:\n\t"<<sun_var[0]<<" "<<vector_sum(sun_vals)<<"\n\t"<<mon_var[0]<<" "<<vector_sum(mon_vals)<<"\n\t"<<tues_var[0]<<" "<<vector_sum(tues_vals)<<"\n\t"<<wed_var[0]<<" "<<vector_sum(wed_vals)<<"\n\t"<<thur_var[0]<<" "<<vector_sum(thur_vals)<<"\n\t"<<fri_var[0]<<" "<<vector_sum(fri_vals)<<"\n\t"<<sat_var[0]<<" "<<vector_sum(sat_vals)<<"\n\t"<<"Amount of rejected values: "<<reject_count<<'\n';
}
catch(exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception!\n";
    return 2;
}