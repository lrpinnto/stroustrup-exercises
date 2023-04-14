// CHAPTER 26 DRILL

#include <iostream>
#include <vector>
#include <iterator>
// binary_search I wrote prior to this chapter
#include "../CHAPTER21/search.h"
#include <fstream>
#include <random>
#include <sstream>

// random number generators. See 24.7.

std::default_random_engine& get_rand()
{
	static std::default_random_engine ran;
	return ran;
};

void seed_randint(int s) { get_rand().seed(s); }

inline int randint(int min, int max) {  return std::uniform_int_distribution<>{min, max}(get_rand()); }

inline int randint(int max) { return randint(0, max); }

struct Test {
    std::string label;
    int val;
    std::vector<int> seq;
    bool res;
};

// 1.
std::istream& operator>>(std::istream& is, Test& t) // use the described format
{
    // Example input: { 27 7 { 1 2 3 5 8 13 21} 0 }
    std::string a, b;

    if (is >> a >> t.label >> t.val >> b && (a != "{" || b != "{"))
    {
        std::cerr << "ERROR: Invalid test file format" << std::endl;
        return is;
    }

    //cout << a << '|' << t.label << '|'  << b << '|'  << t.val << '|' ;

    t.seq.clear();
    std::copy(
        std::istream_iterator<int>(is),
        std::istream_iterator<int>(),
        std::back_inserter(t.seq)
    );

    is.clear();

    //std::copy(t.seq.begin(), t.seq.end(), std::ostream_iterator<int>(cout," "));
    std::string c, d;
    int res = 0;

    if (is >> c >> res >> d && (c != "}" || d != "}"))
    {
        std::cerr << "ERROR: Invalid test file format" << std::endl;
        return is;
    }

    t.res = res;
    //cout << c << '|' << t.res << '|' << d << '|' ;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Test& t)
{
    os << "{ " << t.label << ' ' << t.val << " { ";
    std::copy(t.seq.begin(), t.seq.end(), std::ostream_iterator<int>(os," "));
    return os << "} " << t.res << " }";
}

int test_all(std::istream& is) 
{
    int error_count = 0;
    Test t;
    for (Test t ; is >> t;) {
        std::cout << t << std::endl;
        bool r = search::binary_search( t.seq.begin(), t.seq.end(), t.val);
        if (r !=t.res) {
            std::cout << "failure: test " << t.label
                 << " binary_search: "
                 << t.seq.size() << " elements, v==" << t.val
                 << " -> " << t.res << '\n';
            ++error_count;
        }
    }
    return error_count;
}

void make_test(const std::string& lab, int n, int base, int spread)
// write a test description with the label lab to cout
// generate a sequence of n elements starting at base
// the average distance between elements is uniformly distributed
// in [0:spread)
{
    std::cout << "{ " << lab << " " << n << " { ";
    std::vector<int> v;
    int elem = base;
    for (int i = 0; i<n; ++i) {           // make elements
        elem+= randint(spread);
        v.push_back(elem);
    }

    int val = base+ randint(elem-base);  // make search value
    bool found = false;
    for (int i = 0; i<n; ++i) {           // print elements and see if val is found
        if (v[i]==val) found = true;
        std::cout << v[i] << " ";
    }
    std::cout << "} " << found << " }\n";
}

int main()
{
    // get the test of binary_search to run:
    std::ifstream ifs {"my_tests.txt"};
    int errors = test_all(ifs);
    std::cout << "number of errors: " << errors << "\n";

    // 3.

    // stream redirect so I can use the output of make_test
    std::ostringstream oss;
    std::streambuf* stream_bufffer = oss.rdbuf();
    std::streambuf* old_buffer = std::cout.rdbuf(stream_bufffer);

    // a.
    make_test("3.a.",10000,0,1); // large sequence = 10000??? maybe?
    oss<<'\n';
    // b.
    for (int i = 0; i < 10; i++)
    {
        make_test("3.b."+std::to_string(i)+'.',randint(1000),0,10);
    }
    oss<<'\n';
    // c.
    for (int i = 0; i < 10; i++)
    {
        make_test("3.c."+std::to_string(i)+'.',i,0,10);
    }
    oss<<'\n';

    std::istringstream iss {oss.str()};
    oss.str(""); // flush oss from make_test input.

    int errors_3 = test_all(iss);

    // 4.
    std::ifstream ifs_strings {"C26DRILL_string_tests.txt"};
    if(!ifs_strings) std::runtime_error("could not open file");
    int errors_4 = test_all(ifs_strings); // Needs to be fixed to be able to handle strings

    std::ofstream ofs {"C26DRILL.txt"};
    ofs<<oss.str(); // results from test_all
    std::cout.rdbuf(old_buffer); // back to normal
    std::cout<<errors_3<<" errors for 3. and "<< errors_4 <<" erros for 4. . Check C26DRILL.txt for more info."<<std::endl;
}