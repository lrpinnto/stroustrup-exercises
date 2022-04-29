//Chapter 18 ex 10

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string.h>

using namespace std;

//Comment: Skipped

bool is_palindrome(const char s[], int n)
    // s points to the first character of an array of n characters
{
    int first = 0;
    int last = n-1;
    while(first<last)
    {
        if(s[first]!=s[last]) return false;
        ++first;
        --last;
    }
    return true;
}

istream& read_word_a(istream& is, char* buffer, int max)  //exercise a) report if string is too long
    //read at most max-1 characters from is into buffer
{
    is.width(max);
    is>>buffer;

    if (strlen(buffer) == max-1) {
        cout << "Input cut off after " << max-1 << " characters! ";
        char ch;
        while (is.get(ch)) {
            if (ch=='\n')
            {
                cout<<" -> is overflowing.\n";
                break;
            }
            cout<<ch;
        }
    }

    return is;
}

istream& read_word_b(istream& is, char*& buffer, int max)  //exercise b) handle long strings 
    //read at most max-1 characters from is into buffer
{
    char* temp1 = new char[max];
    *temp1 = 0;
    char ch;
    while (cin.get(ch)) {
        if (ch=='\n') break;
        if (strlen(temp1) == max-1) {
            // double length of temp1
            char* temp2 = new char[max];
            strcpy(temp2,temp1);
            delete[] temp1;
            max *= 2;
            temp1 = new char[max];
            strcpy(temp1,temp2);
            delete[] temp2;
        }
        temp1[strlen(temp1)+1] = 0;
        temp1[strlen(temp1)] = ch;
    }
    buffer = temp1;
    return is;
}

int main()
{
    constexpr int max {128};
    char choice;
    while(choice!='a' && choice!='b')
    {
        cout<<"a or b?";
        cin.get(choice);
    }
    cout<<'\n';
    cin.ignore(); //should flush the input buffer until newline (?)
    cin.clear();
    if(choice=='a')
    {
        for (char s[max]; read_word_a(cin,s,max);)
        {
            cout<<s<<" is";
            if (!is_palindrome(s,strlen(s))) 
            {
                cout<<" not.\n";
            }
            else cout<<".\n";
        }
    }
    else if(choice=='b')
    {
        for (char* s2 {nullptr};read_word_b(cin,s2,max);) {
            cout << s2 <<  " is";
            if (!is_palindrome(s2,strlen(s2))) cout << " not";
            cout << " a palindrome\n";
            delete[] s2;
        }
    }
    else cout<<"impossible";
}