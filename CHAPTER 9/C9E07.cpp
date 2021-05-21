#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 9 EXERCISE 7 ONWARDS

enum class Month{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Year {
        static const int min = 1800;
        static const int max = 2200;
    public:
        class Invalid {};
        Year(int x) : y{x} {if (x<min || max <= x) throw Invalid{};}
        int year() {return y;}
    private:
        int y;
};

struct Date
{
    private:
        int d;
        Month m;
        Year y;
    public:
        Date(Year y, Month m, int d);
        void add_day(int n);
        Month month() const {return m;}
        int day() const {return d;}
        Year year() const {return y;}
};

Date::Date(Year yy, Month mm, int dd)          
    :y{yy}, m{mm}, d{dd}
{
    if (yy.year()>0 && int(mm)>0 && int(mm)<=12 && dd>0 && dd<=31)
    {
        if (!(((yy.year() % 4 == 0) && (yy.year() % 100 != 0)) || (yy.year() % 400 == 0)) && dd==29) error("leap year"); //check if it's a leap year
    }
    else error("out of bounds date");
}

vector<string>tokenize(string s, string deli)
{
    vector<string>result;
    int start = 0;
    int end = s.find(deli);
    while (end != -1) {
        result.push_back(s.substr(start, end - start));
        start = end + deli.size();
        end = s.find(deli, start);
    }
    result.push_back(s.substr(start, end - start));
    return result;
}

class Patron
{
private:
    string name;
    int id;
    double fees=0;   //all patrons start with no fees
public:
    Patron(string namee, int idd)
        :name{namee},id{idd} {};
    string get_name() const {return name;}
    int get_id() const {return id;}
    double get_fees() const {return fees;}
    void set_fee(double d) {fees=d;}
    bool check_fee() {if(fees>0){return true;} else return false;}
};


class ISBN
{
    int n1;       //n1-n2-n3-x
    int n2;
    int n3;
    char x;
    public:
        ISBN(int n1, int n2, int n3, char x);
        ISBN(string s);
        string get_string() const {return to_string(n1)+"-"+to_string(n2)+"-"+to_string(n3)+"-"+x;}

};

ISBN::ISBN(int n11, int n22, int n33, char xx)
    :n1{n11},n2{n22},n3{n33},x{xx}
{
    if(n11<0 || n22<0 || n33<0) error("invalid ISBN number");
}

ISBN::ISBN(string s)  //string needs to follow pattern n-n-n-x
{
    vector<int>numbers;
    string number;
    for(char ch :s)
    {
        if(ch=='-')
        {
            numbers.push_back(stoi(number));
            number.clear();
        }
        else number+=ch; 
    }
    if (number.size()!=1) error("x needs to be a single character");
    x=number[0];
    if (numbers.size()!=3) error("ISBN needs to be composed of 3 ints only");
    for (int i = 0; i < numbers.size(); i++)
    {
        switch (i)
        {
        case 0:
            n1=numbers[0];
            break;
        case 1:
            n2=numbers[1];
            break;
        case 2:
            n3=numbers[2];
            break;
        default:
            break;
        }
    }
}

enum class Genre{
    fiction=1, nonfiction, periodical, biography, children
};

class Book
{
private:
    ISBN id;                               //A 13-digit ISBN, 978-3-16-148410-0, as represented by an EAN-13 bar code
    string title;
    string author;
    Date cright_date;
    bool checked_out = false;
    Genre genre;            
public:
    Book(ISBN id, string title, string author, Date cright_date, Genre genre);
    bool is_checked(){return checked_out;}   //checks if checked out or not
    void check_out(){if(checked_out==true)error("Book already checked out");else checked_out=true;}
    void check_in(){if(checked_out==false)error("Book already checked in");else checked_out=false;}

    string get_ISBN() const {return id.get_string();}
    string get_title() const {return title;}
    string get_author() const {return author;}
    string get_date() const {return to_string(cright_date.year().year())+"/"+to_string(int(cright_date.month()))+"/"+to_string(cright_date.day());}

};

Book::Book(ISBN idd, string titlee, string authorr, Date cright_datee, Genre genree)
    :id{idd}, title{titlee}, author{authorr}, cright_date{cright_datee}, genre{genree} {}

ostream& operator<<(ostream& os, const Book& d)
{
    return os << d.get_title() << '\n' << d.get_author() << '\n' <<d.get_ISBN() << '\n';
}

bool operator==(const ISBN& a, const ISBN& b)
{
    vector<string>alist=tokenize(a.get_string(),"-");
    vector<string>blist=tokenize(b.get_string(),"-");

    return alist[0]==blist[0] && alist[1]==blist[1] && alist[2]==blist[2] && alist[3]==blist[3];
}


bool operator!=(const ISBN& a,const ISBN& b)
{
    return !(a==b);
}


int main()
{
    Patron teste {"maria",1};
    cout<<teste.get_name();
    cout<<teste.check_fee();
    teste.set_fee(2.99);
    cout<<teste.check_fee()<<teste.get_fees();
}