// CHAPTER 23 TRY 03

// Get the program to run and use it to try out some patterns, such as abc, x.*x, (.*), \([^)]*\), and \w+ \w+(Jr\.)?

#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// accept a pattern and a set of lines from input
// check the pattern and search for lines with that pattern

int main()
{
    std::regex pattern;
    
    std::string pat;
    std::cout << "enter pattern: ";
    std::getline(std::cin,pat);         // read pattern

    try {
        pattern = pat;                  // this checks pat
        std::cout << "pattern: " << pat << '\n';
    }
    catch(std::regex_error) {
        std::cout << pat << " is not a valid regular expression\n";
        exit(1);
    }

    std::cout << "now enter lines:\n";
    int lineno = 0;

    for (std::string line; std::getline(std::cin,line); ) {
        ++lineno;
        std::smatch matches;
        if (std::regex_search(line,matches,pattern)) {
            std::cout << "line " << lineno << ": " << line << '\n';
            for (int i = 0; i < matches.size(); ++i)
                std::cout << "\tmatches[" << i << "]: "
                          << matches[i] << '\n';
        } 
        else 
            std::cout << "didn't match\n";
    }
}