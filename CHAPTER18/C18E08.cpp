//Chapter 18 Ex 8

#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

bool is_palidrome_s(const string &s)
{
    return s==string(s.rbegin(),s.rend());
}

bool is_palidrome_a(const char s[], int n)
{
    string a {string(&s[0],&s[n])};
    return s==string(a.rbegin(),a.rend());
}

bool is_palidrome_p(const char* first, const char* last)
{
    string s {string(first,last)};
    return s==string(s.rbegin(),s.rend());
}

istream& read_word(istream& is, char* buffer, int max)
{
    is.width(max);
    is>>buffer;
    return is;
}

int main()
{
    constexpr int max = 128;
    string input;
    while(getline(cin,input))
    {
        istringstream iss {input};
        for (string s; iss>>s;)
        {
            cout<<s<<" is";
            if(!is_palidrome_s(s)) cout<<" not";
            cout<<" a palindrome(string)\n";
        }
        iss.clear(); //This clears any iostate flags that are set in the previous iteration or by setting the string
        iss.str(input);
        for(char s[max]; read_word(iss,s,max);)
        {
            cout<<s<<" is";
            if(!is_palidrome_a(s,strlen(s))) cout<<" not";
            cout<<" a palindrome(array)\n";
        }
        iss.clear(); //This clears any iostate flags that are set in the previous iteration or by setting the string
        iss.str(input);
        for (char s[max]; read_word(iss,s,max); )
        {
            cout<<s<<" is";
            if(!is_palidrome_p(&s[0],&s[strlen(s)])) cout<<" not";
            cout<<" a palindrome(pointer)\n";
        }
    }
}