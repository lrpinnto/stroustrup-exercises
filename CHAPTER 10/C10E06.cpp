#include "../stroustrup/std_lib_facilities.h"

//CHAP 10 EX 06

const vector<string> roman_nums  {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
const vector<int> int_nums  {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

class Roman_int
{
private:
    int value;
    string roman;
public:
    int as_int() const {return value;}
    string as_string() const {return roman;}
    Roman_int(string roman);
    Roman_int(int value);
};

string int_to_roman(int n)
{
    string result;

    for (int i = 0; i < 13; ++i)
    {
        while(n - int_nums[i] >= 0)
        {
            result += roman_nums[i];
            n -= int_nums[i];
        }
    }
    return result;
}

int roman_to_int(string r)
{
    int n = int(r.length());
    if (0 == n) {
        return 0;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        switch (r[i]) {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default:
                error("String not a roman numeral.");
                break;
        }
    }

    for (int i = 1; i < n; i++) {
        if ((r[i] == 'V' || r[i] == 'X') && r[i - 1] == 'I') {
            result -= 1 + 1;
        }

        if ((r[i] == 'L' || r[i] == 'C') && r[i - 1] == 'X') {
            result -= 10 + 10;
        }

        if ((r[i] == 'D' || r[i] == 'M') && r[i - 1] == 'C') {
            result -= 100 + 100;
        }
    }
    return result;
}

Roman_int::Roman_int(string romann)
    :roman{romann}
{
    value = roman_to_int(romann);
    if(value==0) error("String not a roman numeral.");
}

Roman_int::Roman_int(int valuee)
    :value{valuee}
{
    roman=int_to_roman(valuee);
}

ostream& operator<<(ostream& os, const Roman_int& r)
{
    return os << r.as_string();
}

istream& operator>>(istream& is, Roman_int& r)
{
    string s;
    is>>s;
    if(!is) return is;
    //if(isdigit(s)) { int h {stoi(s)}; int s {h}; };  attempt at auto converting int to roman
    r = Roman_int {s};
    return is;
}

int main()
try{
    Roman_int h {"IV"};
    cout<<h.as_int()<<" = "<<h.as_string()<<'\n';
    Roman_int c {22021};
    cout<<"Roman "<<c<<" equals "<<c.as_int()<<'\n';
    cin>>c;
    cout<<c.as_int();
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Error: Something strange happened..\n";
    return 2;
}