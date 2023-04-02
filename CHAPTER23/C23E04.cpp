// CHAPTER 23 EX 04

// Modify the email example example to extract subject lines from sender names taken as input from the user

#include "./Mail_file.h"
#include <map>
#include <regex>

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
    std::regex pat {R"(^From: (\S+@\S+))"};
    for (const auto& x : *m)
    {
        std::smatch matches;
        if (std::regex_match(x,matches,pat)) {
            s = matches[1];
            return true;
        }
    }
    return false;
}

std::string find_subject(const Message* m)
{
    std::regex pat {R"(^Subject: (.+))"};
    for (const auto& x : *m)
    {
        std::smatch matches;
        if (std::regex_match(x,matches,pat)) {
            return matches[1];
        }
    }    
    return "";
}
// ------------------------------------------------------------ 

int main()
{
    // don't forget to generate the file with C23E01.cpp
    Mail_file mfile {"email_messages.txt"};     // initialize mfile from a file

    // first gather messages from each sender together in a multimap

    std::multimap<std::string, const Message*> sender;

    for (const auto& m : mfile) {
        std::string s;
        if (find_from_addr(&m,s))
            sender.insert(make_pair(s,&m));
    }

    std::string senderName;
    while(true)
    {
        std::cout<<"Input the sender's name: ";
        if(!(std::cin>>senderName)) throw std::runtime_error("input error"); // CTRL+d to stop
        
        // now iterate through the multimap
        // and extract the subjects of John Doe's messages:
        auto pp = sender.equal_range(senderName);
        for (auto p = pp.first; p != pp.second; ++p)
            std::cout << find_subject(p->second) << '\n';
    }
}