#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 03

class Punct_stream
{
public:
    Punct_stream(istream& is)
        : source{is}, sensitive{true}, vowel{true} { }
    
    void whitespace(const string& s)
        { white =s; }
    void add_white(char c) { white += c; }
    bool is_whitespace(char c);
    void case_sensitive(bool b) { sensitive = b; }
    bool is_case_sensitive() {return sensitive; }
    bool is_vowel(char c);  //should probably be declared on the global namespace
    void with_vowel(bool v) {vowel=v;}

    Punct_stream& operator>>(string& s);
    operator bool();
private:
    istream& source;
    istringstream buffer;
    string white;
    bool sensitive;
    bool vowel;
};

Punct_stream& Punct_stream::operator>>(string& s)
{
    while(!(buffer>>s)) {
        if(buffer.bad() || !source.good()) return *this;
        buffer.clear();

        string line;
        getline(source,line);

        for(char& ch : line)
        {
            if(is_whitespace(ch))
                ch=' ';
            else{
                if(!sensitive) ch=tolower(ch);
                if(!vowel && is_vowel(ch)) ch='\0';  //replaces char with NULL character
            }
        }
        buffer.str(line);
    }
    return *this;
}

bool Punct_stream::is_whitespace(char c)
{
    for(char w : white)
        if(c==w) return true;
    return false;
}

bool Punct_stream::is_vowel(char c)
{
    vector<char>vowel_list {'a','e','i','o','u'};
    for(char w : vowel_list)
        if(tolower(c)==w) return true;
    return false;
}

Punct_stream::operator bool()
{
    return !(source.fail() || source.bad()) && buffer.good();
}

int main()
{
    cout<<"Please enter input filename: ";
    string iname;
    cin>>iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);

    Punct_stream ps {ifs};
    ps.case_sensitive(false);
    ps.whitespace(" ");
    ps.with_vowel(false);



    while(true){
        string word;
        if(!(ps>>word)) {cout<<word;break;} ///on eof, input stream will break without first running ost effectively cutting the output stream one word short. This "fixes" that
        cout<<word<<' ';
    }
}
