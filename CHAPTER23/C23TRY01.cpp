// CHAPTER 23 TRY 01

// Run the example and modify Mail_file's constructor to handle likely formatting errors related to the use of ----.

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