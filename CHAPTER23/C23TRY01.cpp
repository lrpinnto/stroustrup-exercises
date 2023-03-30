// CHAPTER 23 TRY 01

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <stdexcept>

typedef std::vector<std::string>::const_iterator Line_iter;   

class Message { // a Message points to the first and the last lines of a message
    Line_iter first;
    Line_iter last;
public:
    Message(Line_iter p1, Line_iter p2) : first{p1}, last{p2} { }
    Line_iter begin() const { return first; }
    Line_iter end() const { return last; }
    // ...
};

using Mess_iter = std::vector<Message>::const_iterator;  

struct Mail_file {                        // a Mail_file holds all the lines from a file
                                          // and simplifies access to messages
    std::string name;                     // file name (NOT USED?)
    std::vector<std::string>lines;        // the lines in order
    std::vector<Message> m;               // Messages in order

    Mail_file(const std::string& n);      // read file n into lines

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

Mail_file::Mail_file(const std::string& n)
    // open file named n
    // read the lines from n into lines
    // find the messages in the lines and compose them in m
    // for simplicity assume every message is ended by a ---- line
{
    std::ifstream in {n};                                   // open the file
    if (!in) {
        std::cerr << "no " << n << '\n';
        exit(1);                                            // terminate the program
    }

    for (std::string s; getline(in,s); )                    // build the vector of lines
        lines.push_back(s);

    auto first = lines.begin();                             // build the vector of Messages
    for (auto p = lines.begin(); p != lines.end(); ++p) {
        if (*p == "----") {                                 // end of message
            if (p != first)                                 // don't count consecutive ----'s as Msg (As requested per TRY01)
                m.push_back(Message(first,p));
            first = p+1;                                    // ---- not part of message
        }
    }
}

// find the name of the sender in a Message;
// return true if found
// if found, place the sender's name in s:
bool find_from_addr(const Message* m, std::string& s);

// return the subject of the Message, if any, otherwise "":
std::string find_subject(const Message* m);

// Definitions of undefined functions after TRY THIS --------------
int is_prefix(const std::string& s, const std::string& p)
    // is p the first part of s?
{
    int n = p.size();
    if (std::string(s,0,n) == p) return n;
    return 0;
}

bool find_from_addr(const Message* m, std::string& s)
{
    for (const auto& x : *m)
        if (int n = is_prefix(x, "From: ")) {
            s = std::string(x,n);
            return true;
        }
    return false;
}

std::string find_subject(const Message* m)
{
    for (const auto& x : *m)
        if (int n = is_prefix(x, "Subject: ")) return std::string(x,n);
    return "";
}
// ------------------------------------------------------------ 

int main()
{
    Mail_file mfile {"my-mail-file.txt"};     // initialize mfile from a file

    // first gather messages from each sender together in a multimap

    std::multimap<std::string, const Message*> sender;

    for (const auto& m : mfile) {
        std::string s;
        if (find_from_addr(&m,s))
            sender.insert(make_pair(s,&m));
    }

    // now iterate through the multimap
    // and extract the subjects of John Doe's messages:
    auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
    for (auto p = pp.first; p != pp.second; ++p)
        std::cout << find_subject(p->second) << '\n';
}