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
        int year() const {return y;}
    private:
        int y;
};

bool leapyear(Year y)
{
    if(!(((y.year() % 4 == 0) && (y.year() % 100 != 0)) || (y.year() % 400 == 0))) return false;
    else return true;
}

int dayofweek(const int d, const Month m, const Year y)  //returns 0 - sunday, 1 - monday, 2 - tuesday (...)
{
    int year=y.year();  
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  
    year -= int(m) < 3;  
    return ( year + year / 4 - year / 100 + year / 400 + t[int(m) - 1] + d) % 7;  
}



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
        int week_of_year();
        Date next_workday() const          //unable to handle month and year switches. Will throw error.
        {
            int weekday = dayofweek(d,m,y);
            switch (weekday)
            {
            case 5:
                return {y,m,d+3};
                break;
            case 6:
                return {y,m,d+2};
                break;
            case 0:
                return {y,m,d+1};
                break;
            default:
                return {y,m,d+1};
                break;
            }
        }
};

int Date::week_of_year()  //assuming sunday is the first day of the week. really crude implementation
{
    int jan1 {dayofweek(1,Month::jan,y)};

    int nextmonday {8-jan1};  //week 2

    int days {30*(int(m)-1)+d};
    int count {1};
    for (int i = nextmonday; i <= days; i+=7)
    {
        count++;
    }
    return count;
}

Date::Date(Year yy, Month mm, int dd)          
    :y{yy}, m{mm}, d{dd}
{
    if (yy.year()>0 && int(mm)>0 && int(mm)<=12 && dd>0 && dd<=31)
    {
        if (!leapyear(yy) && dd==29) error("not a leap year"); //check if it's a leap year
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
    Patron(string namee)
        :name{namee} {}
    string get_name() const {return name;}
    int get_id() const {return id;}
    double get_fees() const {return fees;}
    void set_fee(double d) {fees=d;}
    void set_id(int n) {id = n;}   //to be initialized by Library class
    bool check_fee() const {if(fees>0){return true;} else return false;}
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
        ISBN get_rawid() const {return ISBN{n1,n2,n3,x};}

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
    ISBN get_rawISBN() const {return id.get_rawid();}
    string get_title() const {return title;}
    string get_author() const {return author;}
    string get_date() const {return to_string(cright_date.year().year())+"/"+to_string(int(cright_date.month()))+"/"+to_string(cright_date.day());}

};

Book::Book(ISBN idd, string titlee, string authorr, Date cright_datee, Genre genree)
    :id{idd}, title{titlee}, author{authorr}, cright_date{cright_datee}, genre{genree} {}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << d.day() << '/' << int(d.month()) << '/' <<d.year().year() << '\n';
}

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

bool operator==(const Book& a, const Book& b)  //only need to check ISBN since these should be unique per book
{
    return (a.get_rawISBN()==b.get_rawISBN());
}


bool operator!=(const Book& a,const Book& b)
{
    return !(a==b);
}

bool operator==(const Patron& a, const Patron& b)  //only need to check ISBN since these should be unique per book
{
    return (a.get_id()==b.get_id());
}


bool operator!=(const Patron& a,const Patron& b)
{
    return !(a==b);
}

struct Transaction
{
    Book book;
    Patron patron;
    Date date;
    Transaction(Book bookk,Patron patronn,Date datee)
        :book{bookk},patron{patronn},date{datee}{}
};

class Library
{
private:
    int id = 0;   //guarantees unique id for patrons
    vector<Book>books;
    vector<Patron>patrons;
    vector<Transaction>transactions;
public:
    Library(/* args */);
    //int get_newid() {id++; return id;}
    void add_book(const Book book){books.push_back(book);}
    void add_patron(Patron& patron){id++; patron.set_id(id);patrons.push_back(patron);}  //generates unique id
    void check_out(const Book book, const Patron patron, const Date date)
    {
        if((find(books.begin(),books.end(),book)!=books.end()) && (find(patrons.begin(),patrons.end(),patron)!=patrons.end())) //checks if the book or patron already exist in the "database"
        {
            if(patron.check_fee()) error("Books cannot be checked out for patrons with pending fees");
            transactions.push_back({book,patron,date});
        }
        else error("Both book and patron need to already exist in the library. ");

    }
    vector<string>get_debtlist()
    {
        vector<string>debts;
        for (Patron p : patrons)
        {
            if(p.check_fee()) debts.push_back(p.get_name());
        }
        return debts;
    }

    vector<string>get_transactions()
    {
        vector<string>trans;
        for (Transaction t : transactions)
        {
            trans.push_back(t.book.get_title()+" "+to_string(t.date.day())+"/"+to_string(int(t.date.month()))+"/"+to_string(t.date.year().year())+" "+t.patron.get_name());
        }
        return trans;
    }
};

Library::Library(/* args */)
{
}



int main()
{
    Library teste;
    Patron maria {"Maria"};
    maria.set_fee(1.99);
    Patron marta {"Marta"};
    marta.set_fee(0.99);
    Patron joaquina {"Joaquina"};
    teste.add_patron(maria);
    teste.add_patron(marta);
    teste.add_patron(joaquina);

    Book somebook {{"111-232-444-m"},"Book about something cool","John H.",{Year(2016),Month::jul,3},Genre::nonfiction};
    Book somebook2 {{"113-232-444-m"},"Book about something cool 2","John H.",{Year(2016),Month::aug,3},Genre::children};

    teste.add_book(somebook);
    teste.add_book(somebook2);
    teste.add_book({
        {"321-32131-221231-i"},
        "hello book",
        "some guy",
        {{2009},Month::nov,3},
        Genre::biography}
    );

    Date teste1 {{2021},Month::jun,5};
    cout<<teste1<<teste1.next_workday();

    cout<<teste1.week_of_year();
}