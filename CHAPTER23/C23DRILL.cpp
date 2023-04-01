// CHAPTER 23 DRILL

#include <regex>
#include <iostream>
#include <string>
#include <sstream>

std::string zip_codes {
    "address TX77845\n"
    "ffff tx 77843 asasasasaa\n"
    "ggg TX3456-23456\n"
    "howdy\n"
    "zzz TX23456-3456sss ggg TX33456-1234\n"
    "cvzcv TX77845-1234 sdsas\n"
    "xxxTx77845xxx\n"
    "TX12345-123456\n"
};

int main()
{
    std::istringstream in {zip_codes};
    if (!in) std::cerr << "no file\n";

    std::regex pat {R"(\w{2}\s*\d{5}(-\d{4})?)"};

    int lineno = 0;
    for (std::string line; std::getline(in,line); ) {
        ++lineno;
        std::smatch matches;
        if (std::regex_search(line, matches, pat)) {
            std::cout << lineno << ": " << matches[0] << '\n';
            if (1<matches.size() && matches[1].matched)
                std::cout << "\t: " << matches[1] << '\n';
        }
    }
}