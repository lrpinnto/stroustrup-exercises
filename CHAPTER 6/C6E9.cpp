#include "../stroustrup/std_lib_facilities.h"

//CAP 6 EX 09

class string_stream
{
    public:
        int get();
        bool check_stream();
    private:
        bool end_of_stream=false;
};

string_stream ss;

bool string_stream::check_stream()
{
    if (end_of_stream==true)
    {
        end_of_stream=false;
        return true;
    }
    else return false;
}

int string_stream::get()
{

    
    char ch;
    cin>>ch;
    if(!cin) error("Wrong input");
    if(cin.peek()==10) //Checks for end of stream. If peek() returns 10 (for some unknown reason) it means cin will request input from keyboard. We don't want that. So we set end_of_stream flag as true and terminate the while loop
    {
        end_of_stream =true;
    }

    int ch2int = ch;  //simple char to int conversion
    if (ch2int<48 || ch2int >57)
    { 
        
        return ss.get(); //ignores value, gets another one
    }
    else
    {
        switch (ch2int)
        {
        case 48:
            return 0;
            break;
        case 49:
            return 1;
            break;
        case 50:
            return 2;
            break;
        case 51:
            return 3;
            break;
        case 52:
            return 4;
            break;
        case 53:
            return 5;
            break;
        case 54:
            return 6;
            break;
        case 55:
            return 7;
            break;
        case 56:
            return 8;
            break;
        case 57:
            return 9;
            break;
        default:
            return 999999;  //should never get here
            break;
        }
    }
}

int list2int(vector<int>list)
{
    int final=0;
    int pivot=0;
    int multiplier = pow(10,list.size()-1);
    for (int i : list)
    {
        pivot=i*multiplier;
        multiplier/=10;
        final+=pivot;
    }
    return final;
    
}

int main()
try {
    constexpr int maxVectorSize = 4;   //maximum vector size for this exercise
    const vector<string>multiples_of_10={"thousand","hundred","tens","ones"};
    vector<string>multiples_of_10_mirror;
    const int max_digits = 4;  //maximum number of digits
    vector<int>numbers;
    while(true)
    {
        cout<<"Please type max 4 digits:\n\t";
        while(!ss.check_stream() && numbers.size()<max_digits)
        {
            int ch = ss.get();
            numbers.push_back(ch);
        }
        cout<<'\n'<<list2int(numbers)<<" is ";
        multiples_of_10_mirror=multiples_of_10;
        for (int i = 0; i < maxVectorSize-numbers.size(); i++)
        {
            multiples_of_10_mirror.erase(multiples_of_10_mirror.begin());  //deletes the first element of the multiples_of_10 vector depending on the size of the user input.       
        }
        
        for(int i = 0 ; i<numbers.size() ; i++)
        {
            cout<<numbers[i]<<" "<<multiples_of_10_mirror[i]<<" ";
        }
        cout<<'\n';
        numbers.clear();
    }
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}
