#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 14
//There's probably a cleaner way to do this

class classification
{
private:
    int space;
    int alpha;
    int digit;
    int xdigit;
    int upper;
    int lower;
    int alnum;
    int cntrl;
    int punct;
    int print;
    int graph;

    void get_class(char ch);
public:
    classification(const string& s);
    classification() : space{0}, alpha{0}, digit{0}, xdigit{0}, upper{0}, lower{0}, alnum{0}, cntrl{0}, punct{0}, print{0}, graph{0} {}
    int get_space() const {return space;}
    int get_alpha() const {return alpha;}
    int get_digit() const {return digit;}
    int get_xdigit() const {return xdigit;}
    int get_upper() const {return upper;}
    int get_lower() const {return lower;}
    int get_alnum() const {return alnum;}
    int get_cntrl() const {return cntrl;}
    int get_punct() const {return punct;}
    int get_print() const {return print;}
    int get_graph() const {return graph;}

    void set_space(int i) {space=i;}
    void set_alpha(int i) {alpha=i;}
    void set_digit(int i) {digit=i;}
    void set_xdigit(int i) {xdigit=i;}
    void set_upper(int i) {upper=i;}
    void set_lower(int i) {lower=i;}
    void set_alnum(int i) {alnum=i;}
    void set_cntrl(int i) {cntrl=i;}
    void set_punct(int i) {punct=i;}
    void set_print(int i) {print=i;}
    void set_graph(int i) {graph=i;}
};

classification::classification(const string& ss)
    : space{0}, alpha{0}, digit{0}, xdigit{0}, upper{0}, lower{0}, alnum{0}, cntrl{0}, punct{0}, print{0}, graph{0}
{
    istringstream iss {ss};
    for(char ch; iss.get(ch);) get_class(ch);
}

void classification::get_class(char ch)
{
    if (isspace(ch)) {space++;}
    if (isalpha(ch)) {alpha++;}
    if (isdigit(ch)) {digit++;}
    if (isxdigit(ch)) {xdigit++;}
    if (isupper(ch)) {upper++;}
    if (islower(ch)) {lower++;}
    if (isalnum(ch)) {alnum++;}
    if (iscntrl(ch)) {cntrl++;}
    if (ispunct(ch)) {punct++;}
    if (isprint(ch)) {print++;}
    if (isgraph(ch)) {graph++;}
}

classification operator+(const classification& a, const classification& b)
{
    classification c;
    c.set_space(a.get_space()+b.get_space());
    c.set_alpha(a.get_alpha()+b.get_alpha());
    c.set_digit(a.get_digit()+b.get_digit());
    c.set_xdigit(a.get_xdigit()+b.get_xdigit());
    c.set_upper(a.get_upper()+b.get_upper());
    c.set_lower(a.get_lower()+b.get_lower());
    c.set_alnum(a.get_alnum()+b.get_alnum());
    c.set_cntrl(a.get_cntrl()+b.get_cntrl());
    c.set_punct(a.get_punct()+b.get_punct());
    c.set_print(a.get_print()+b.get_print());
    c.set_graph(a.get_graph()+b.get_graph());
    return c;
}

int main()
{
    cout<<"Enter a text file: ";
    string iname;
    cin>>iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);
    string line;
    classification counter;
    while(getline(ifs, line))  //line by line to try and avoid issues with string size for bigger documents
    {
        classification w {line};
        counter=w+counter;
    }
    cout << "space: " << counter.get_space() << '\n';
    cout << "alpha: " << counter.get_alpha() << '\n';
    cout << "digit: " << counter.get_digit() << '\n';
    cout << "xdigit: " << counter.get_xdigit() << '\n';
    cout << "upper: " << counter.get_upper() << '\n';
    cout << "lower: " << counter.get_lower() << '\n';
    cout << "alnum: " << counter.get_alnum() << '\n';
    cout << "cntrl: " << counter.get_cntrl() << '\n';
    cout << "punct: " << counter.get_punct() << '\n';
    cout << "print: " << counter.get_print() << '\n';
    cout << "graph: " << counter.get_graph() << '\n';
}
