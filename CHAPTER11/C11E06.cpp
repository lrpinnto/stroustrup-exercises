#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 06, 07
//TO DO: EX 08
//BUG: Sometimes returns same line twice, using the authors "suggested" for loop results in missing words.

/*
vector<string> vs;
for (string word; ps>>word;)
    vs.push_back(word);

for(int i=0;i<vs.size();++i)
    if(i==0 || vs[i]!=vs[i-1]) cout<<vs[i]<<'\n';
*/

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
void nots(string& word, istringstream& buffer)  //I'm not sure how the author intends for me to handle examples like don't -> do not. Maybe with a list of all exceptions?
{                        //using a generic solution. Won't work with words like "won't" which is a contraction of "will not" and other such examples
    int index {word.find("n't")};
    word.erase(word.begin()+index,word.end());
    string rest_of_stream {"not "};
    for(string s ; buffer>>s;)
        rest_of_stream+=s+" ";
    buffer.clear();
    buffer.str(rest_of_stream);
}
Punct_stream& Punct_stream::operator>>(string& s)
{
    while(!(buffer>>s)) {
        if(buffer.bad() || !source.good()) return *this;
        buffer.clear();

        string line;
        getline(source,line);
        bool ignore_char {false};
        for(char& ch : line)
        {
            if(ch=='"')
                if(ignore_char) ignore_char=false;
                else ignore_char=true;
            if(ignore_char) continue;
            if(is_whitespace(ch))
                ch=' ';
            else{
                if(!sensitive) ch=tolower(ch);
                if(!vowel && is_vowel(ch)) ch='\0';  //replaces char with NULL character
            }
        }
        buffer.str(line);
    }
    if (s.find("n't") != string::npos) nots(s,buffer);
    return *this;  //points towards string s
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
    cout<<"Please filepath for input text: ";
    string iname;
    cin>>iname;
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);
    while(ifs){
        getline(ifs,iname);
        istringstream iss {iname};
        Punct_stream ps {iss};
        ps.whitespace(".;,?");  //don't use the as-if rule
        while(true){
            string word;
            if(!(ps>>word)) {cout<<word<<'\n';break;} ///on eof, input stream will break without first running ost effectively cutting the output stream one word short. This "fixes" that
            cout<<word<<' ';
        }
    }
}
