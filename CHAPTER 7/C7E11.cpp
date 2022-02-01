#include "../stroustrup/std_lib_facilities.h"

//CAP 7 EX 11 (C5E14.cpp)

struct Token
{
    char kind;
    int value;
    Token(char ch) :kind(ch),value(0) { }
    Token(char ch, int i) :kind(ch),value(i) { }
};

struct week
{
    char kind;
    int value;
    vector<string>week_days;
    week(char ch, vector<string>vect, int i) :kind(ch),week_days(vect),value(i) { }
};

class Token_stream
{
    private:
        vector<week>weekdays;
    public:
        Token get();
        void init_week();
        void add_values(Token t, Token t2);
        
        void outputr();
        void sortinput();
};

Token_stream ts;

void Token_stream::init_week()
{
    weekdays.push_back(week('s',{ "Sunday", "sunday", "Sun", "sun" },0));
    weekdays.push_back(week('m',{ "Monday", "monday", "Mon", "mon" },0));
    weekdays.push_back(week('t',{ "Tuesday", "tuesday", "Tues", "tues" },0));
    weekdays.push_back(week('w',{ "Wednesday", "wednesday", "Wed", "wed" },0));
    weekdays.push_back(week('T',{ "Thursday", "thursday", "Thur", "thur" },0));
    weekdays.push_back(week('f',{ "Friday", "friday", "Fri", "fri" },0));
    weekdays.push_back(week('S',{ "Saturday", "saturday", "Sat", "sat" },0));
    weekdays.push_back(week('x',{},0));
}

Token Token_stream::get()
{
    char ch;
    cin.get(ch);
    if(!cin) error("Weird Input!");
    if (isalpha(ch))
    {
        string s;
        s+=ch;
        while (cin.get(ch) && (isalpha(ch)|| isdigit(ch) ))
        {
            s+=ch;
        }
        cin.unget(); //returns the character that dropped the while cycle
        //detect what it is and return right token
        if (s=="quit") return Token('q');
        for (int i = 0; i < weekdays.size(); i++)
        {
            for (string w : weekdays[i].week_days)
            {
                if (s == w)
                {
                    return Token(weekdays[i].kind);
                }
                
            }
        }
        return Token('x');
    }
    else if (isdigit(ch))
    {
        int numeric=0;
        vector<int>list_of_digits={int(ch)-48};  //awful hack for ch to int conversion
        while (cin.get(ch) && isdigit(ch))
        {
            list_of_digits.push_back(int(ch)-48);
            
        }
        cin.unget();
        for (int i = pow(10,list_of_digits.size()-1), j = 0; i >= 1; i/=10,j++)
        {
            numeric+=list_of_digits[j]*i;
        }
        return Token('i',numeric);    
    }
    else
    {
        if (isspace(ch))
        {
            get();
        }
        else error("weird");
    }
}

void Token_stream::outputr()
{
    cout<<"Sum days of the week:\n\t";
    for (int i = 0; i < weekdays.size()-1; i++)
    {
        cout<<weekdays[i].week_days[0]<<" "<<weekdays[i].value<<"\n\t";
    }
    cout<<"Amount of rejected values: "<<weekdays[weekdays.size()-1].value<<'\n';
}

void Token_stream::add_values(Token t, Token t2)
{
    if (t.kind=='x') {weekdays[7].value++;return;}
    for (int i = 0; i < weekdays.size(); i++)
    {
        if (weekdays[i].kind==t.kind)
        {
            weekdays[i].value+=t2.value;
        }
    }
}

void sortinput()
{
    ts.init_week();
    cout<<"Please type the weekday followed by a number:\n";
    while (true) try 
    {
        Token t = ts.get();
        if (t.kind=='q') return;
        if (t.kind == 'i') error("Expected string");
        Token t2 = ts.get();
        if (t2.kind!='i') error("Expected numeric value");
        ts.add_values(t,t2);
    }
    catch (runtime_error& e) {
		cerr << e.what() << endl;
	}
}

int main()
try
{
    sortinput();
    ts.outputr();
}
catch(exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception!\n";
    return 2;
}