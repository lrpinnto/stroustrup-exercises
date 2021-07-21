#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 05
//Needs an overhaul. Solution a bit hectic.

struct dictionary //python styled dict data type attempt
{
public:
    dictionary(string keyy, string valuee)
        : key{keyy}, value{valuee} {}
    dictionary(string keyy, bool evall)
        : key{keyy}, eval{evall} {}
    string get() {return value;}
    void set(bool x) {eval=x;}
    string getkey(bool val)
    {
        if(val==eval) return key;
        else return "\0";
    }
private:
    string key;
    string value;
    bool eval;
};

struct classification
{
public:
    classification(const string& s) {word=s;}
    string word;
    vector<dictionary>classlist
    {
        {"isspace",false}, //0
        {"isalpha",false}, //1
        {"isdigit",false}, //2
        {"isxdigit",false}, //3
        {"isupper",false}, //4
        {"islower",false}, //5
        {"isalnum",false}, //6
        {"iscntrl",false}, //7
        {"ispunct",false}, //8
        {"isprint",false}, //9
        {"isgraph",false} //10
    };
};

ostream& operator<<(ostream& os, const classification& cs)
{
    string h;
    for(dictionary d : cs.classlist) 
        if(d.getkey(true)!="\0") h+=d.getkey(true)+", ";
    h.erase(h.begin()+(h.size()-2),h.end());
    return os << h;
}

vector<classification> eval_char(const string& s) //takes string of unknown amount of words
{
    istringstream is {s};
    vector<classification> list;
    for(string word; is>>word; )  //outputs a single whitespace separated word each time.
    {
        if(!is) error("string stream error.");
        classification cs {word};
        for(char& ch : word)  //checks each char one by one
        {
            if(isspace(ch)) cs.classlist[0].set(true); //is a space character
            if(isalpha(ch)) cs.classlist[1].set(true); //is alphabetic (a,b,c)
            if(isdigit(ch)) cs.classlist[2].set(true); //is int (1,2,3)
            if(isxdigit(ch)) cs.classlist[3].set(true); //is a hexadecimal numeric character (0123456789abcdefABCDEF)
            if(isupper(ch)) cs.classlist[4].set(true); //is capital
            if(islower(ch)) cs.classlist[5].set(true); //is not capital
            if(isalnum(ch)) cs.classlist[6].set(true); //is true if either isalpha or isdigit would also return true
            if(iscntrl(ch)) cs.classlist[7].set(true); //characters with the codes 0x00-0x1F and 0x7F
            if(ispunct(ch)) cs.classlist[8].set(true); //!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
            if(isprint(ch)) cs.classlist[9].set(true); //A printable character is a character that occupies a printing position on a display (this is the opposite of a control character, checked with iscntrl).
            if(isgraph(ch)) cs.classlist[10].set(true); //The characters with graphical representation are all those characters than can be printed (as determined by isprint) except the space character (' ').
        }
        list.push_back(cs);
    }
    return list;
}


int main()
try {
    string input;
    cout<<"Enter some input to be evaluated: ";
    getline(cin,input);
    vector<classification> list {eval_char(input)};

    for(classification cs : list) cout<<cs.word<<" is composed of "<<cs<<" characters"<<'\n'<<'\n';
}
catch(exception& e) {
    cerr << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Error of unknown type\n";
    return 2;
}
