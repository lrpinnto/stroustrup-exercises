#include "../stroustrup/std_lib_facilities.h"

//CAP 6 EX 06
//Taken from calculator and based off https://github.com/Chrinkus/ solution.

/*
GRAMMAR
=======
Sentence:
    Noun Verb
    Article Noun Verb
    Sentence Conjunction Sentence
Conjunction:
    "and"
    "or"
    "but"
Noun:
    "birds"
    "fish"
    "C++"
Verb:
    "rules"
    "fly"
    "swim"
Article:
    "the"
*/


class String_stream {
    public:
        string get();
        void putback(string s);
    private:
        bool full = false;
        string buffer = "";
};

void String_stream::putback(string s)
{
    if (full) error("Buffer full, putback fail");
    buffer = s;
    full = true;
}

string String_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }
    
    string s;
    cin >> s;

    return s;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

String_stream stream;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool article()
{
    vector<string> articles = { "the" };
    bool found = false;
    string s = stream.get();

    for (string a : articles)
        if (a == s)
            found = true;

    if (!found) stream.putback(s);

    return found;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool noun()
{
    vector<string> nouns = { "birds", "fish", "C++" };
    bool found = false;
    string s = stream.get();

    for (string n : nouns)
        if (n == s)
            found = true;

    if (!found) stream.putback(s);

    return found;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool verb()
{
    vector<string> verbs = { "rules", "fly", "swim" };
    bool found = false;
    string s = stream.get();

    for (string v : verbs)
        if (v == s)
            found = true;

    if (!found) stream.putback(s);

    return found;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool conjunction()
{
    vector<string> conjunctions = { "and", "or", "but" };
    bool found = false;
    string s = stream.get();

    for (string c : conjunctions)
        if (c == s)
            found = true;

    if (!found) stream.putback(s);

    return found;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

bool sentence()
{
    if ((noun() || (article() && noun())) && verb()) {
        if (conjunction())
        {
            return sentence();
        }
        else
            return true;
    } else {
        string s = stream.get();           // burn the word
        if (s==".") 
        {
            stream.putback(".");      //to avoid the program getting stuck when entering the if conjunction. eg "the fish swim or ."
            return false;
        }
        else return false;
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

int main()
try {
    cout << "Type in a sentence and I will check the grammar.\n";
    bool is_sentence = false;
    bool end = false;

    while(!end) {
        string s = stream.get();
        if (s == ".") {
            if (is_sentence) cout << "OK\n";
            else cout << "not OK\n";
        } else if (s == "q") {
            cout << "Hope everything worked!\n";
            end = true;
        } else {
            stream.putback(s);
        }
        is_sentence = sentence();
    }
    return 0;
}
catch(exception& e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "Unknown exception\n";
    return 2;
}