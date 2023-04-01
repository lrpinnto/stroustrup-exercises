// CHAPTER 23 EX 02

// Add a multimap and have it hold subjects. let the program take an input string from the keyboard and print out every message with that string
// as its subject.

#include "./Mail_file.h"
#include <map>

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
    // don't forget to generate the file with C23E01.cpp
    Mail_file mfile {"email_messages.txt"};     // initialize mfile from a file

    // first gather messages from each sender together in a multimap

    std::multimap<std::string, const Message*> subject;

    for (const auto& m : mfile) {
        subject.insert(make_pair(find_subject(&m),&m));
    }

    std::cout<<"Please input a subject: ";
    std::string subj;
    if(!(getline(std::cin,subj))) throw std::runtime_error("Input error");
    auto pp = subject.equal_range(subj); //get all messages with this subject
    if(pp.first==pp.second)
    {
        std::cout<<"Nothing found\n";
        exit(0);
    }
    for (auto p = pp.first; p != pp.second; ++p)  
        std::cout << find_subject(p->second) << ' ' << (*p).second << '\n';
}