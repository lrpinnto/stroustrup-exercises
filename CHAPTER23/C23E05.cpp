// CHAPTER 23 EX 05

// time multimap and unordored_multimap using a large email file

#include "./Mail_file.h"
#include <map>
#include <regex>
#include <unordered_map>
#include <chrono>

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

    std::unordered_multimap<std::string, const Message*> sender_unordered;

    auto t1 {std::chrono::system_clock::now()}; //start timer
    for (const auto& m : mfile) {
        std::string s;
        if (find_from_addr(&m,s))
            sender.insert(make_pair(s,&m));
    }
    auto t2 {std::chrono::system_clock::now()}; //end timer

    
    auto t3 {std::chrono::system_clock::now()}; //start timer
    for (const auto& m : mfile) {
        std::string s;
        if (find_from_addr(&m,s))
            sender_unordered.insert(make_pair(s,&m));
    }
    auto t4 {std::chrono::system_clock::now()}; //end timer

    std::cout<<"multimap insert took "
        <<std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    std::cout<<"unordered_multimap insert took "
        <<std::chrono::duration_cast<std::chrono::milliseconds>(t4-t3).count() << " milliseconds\n";

    auto t5 {std::chrono::system_clock::now()};
    auto pp = sender.equal_range("user@some.where");
    for (auto p = pp.first; p != pp.second; ++p)
        find_subject(p->second);
    auto t6 {std::chrono::system_clock::now()};

    auto t7 {std::chrono::system_clock::now()};
    auto pp_unordered = sender_unordered.equal_range("user@some.where");
    for (auto p = pp_unordered.first; p != pp_unordered.second; ++p)
        find_subject(p->second);
    auto t8 {std::chrono::system_clock::now()};

    std::cout<<"multimap equal_range() took "
        <<std::chrono::duration_cast<std::chrono::milliseconds>(t6-t5).count() << " milliseconds\n";

    std::cout<<"unordered_multimap equal_range() took  "
        <<std::chrono::duration_cast<std::chrono::milliseconds>(t8-t7).count() << " milliseconds\n";
}

/*
My results:
multimap insert took 702 milliseconds
unordered_multimap insert took 698 milliseconds
multimap equal_range() took 5 milliseconds
unordered_multimap equal_range() took  4 milliseconds

This was using 2000 emails entries. 

multimap insert took 14248 milliseconds
unordered_multimap insert took 14553 milliseconds
multimap equal_range() took 90 milliseconds
unordered_multimap equal_range() took  90 milliseconds

This was using 40000 emails entries

Unexpected results, perhaps I need a better hash function for unordered_multimap
*/