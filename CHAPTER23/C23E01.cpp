// CHAPTER 23 EX 01

// Test the email file example with a larger file 

#include "./Mail_file.h"
#include <cstdlib>
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
    // Generates mock emails on demand since writting them by hand is tiresome
    // requires python3 and bash
    // tested using linux
    // creates a file email_messages.txt full of mock emails to test!
    // (generate_emails.sh might need to have execute permissions)
    std::system("./generate_emails.sh");

    Mail_file mfile {"email_messages.txt"};     // initialize mfile from a file

    // first gather messages from each sender together in a multimap

    std::multimap<std::string, const Message*> sender;

    for (const auto& m : mfile) {
        std::string s;
        if (find_from_addr(&m,s))
            sender.insert(make_pair(s,&m));
    }

    // now iterate through the multimap
    // and extract the subjects of John Doe's messages:
    auto pp = sender.equal_range("user@some.where");
    for (auto p = pp.first; p != pp.second; ++p)
        std::cout << find_subject(p->second) << '\n';
}