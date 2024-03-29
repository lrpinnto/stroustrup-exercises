#include "../stroustrup/std_lib_facilities.h"

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

class ISBN
{
    int n1;       //n1-n2-n3-x
    int n2;
    int n3;
    char x;
    public:
        ISBN(int n1, int n2, int n3, char x);
        ISBN(string s);
        string get_string(){return to_string(n1)+"-"+to_string(n2)+"-"+to_string(n3)+"-"+x;}

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


class Book
{
private:
    ISBN id;                               //A 13-digit ISBN, 978-3-16-148410-0, as represented by an EAN-13 bar code
    string title;
    string author;
    Date cright_date;
    bool checked_out = false;            
public:
    Book(ISBN id, string title, string author, Date cright_date);
    bool is_checked(){return checked_out;}   //checks if checked out or not
    void check_out(){if(checked_out==true)error("Book already checked out");else checked_out=true;}
    void check_in(){if(checked_out==false)error("Book already checked in");else checked_out=false;}

    string get_ISBN(){return id.get_string();}
    string get_title(){return title;}
    string get_author(){return author;}
    string get_date(){return to_string(cright_date.year().year())+"/"+to_string(int(cright_date.month()))+"/"+to_string(cright_date.day());}

};

Book::Book(ISBN idd, string titlee, string authorr, Date cright_datee)
    :id{idd}, title{titlee}, author{authorr}, cright_date{cright_datee} {}


int main()
{
    Book harry_potter_ps {{"9781-4088-5565-2"},"Harry Potter and the Philosopher's Stone","J.K.Rowling",{Year{2014},Month::sep,1}};
    cout<<"Book checked out?:"<<harry_potter_ps.is_checked()<<endl;
    cout<<"Checking out book..."<<endl;
    harry_potter_ps.check_out();
    cout<<"Book checked out?:"<<harry_potter_ps.is_checked()<<endl;

    cout<<"The book's title is "<<harry_potter_ps.get_title()<<" written by "<<harry_potter_ps.get_author()<<" with the ISBN "<<harry_potter_ps.get_ISBN()<<" and copy right date "<<harry_potter_ps.get_date()<<endl;
}

