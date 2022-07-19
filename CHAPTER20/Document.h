//Document facilities from the book

#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using Line = std::vector<char>;

struct Document
{
    std::list<Line> line;
    Document() {line.push_back(Line{});}

    Text_iterator begin()
    {
        return Text_iterator(line.begin(),(*line.begin()).begin());
    }

    Text_iterator end()
    {
        auto last = line.end();
        --last;
        return Text_iterator(last,(*last).end());
    }
};

class Text_iterator
{
private:
    std::list<Line>::iterator ln;
    Line::iterator pos;
public:
    Text_iterator(std::list<Line>::iterator ll, Line::iterator pp)
        :ln{ll}, pos{pp} { }

    char& operator*() {return *pos; }
    Text_iterator& operator++();
    bool operator==(const Text_iterator& other) const
    {
        return ln==other.ln && pos==other.pos;
    }
    bool operator!=(const Text_iterator& other) const
    {
        return !(*this==other);
    }
};

Text_iterator& Text_iterator::operator++()
{
    ++pos;
    if (pos==(*ln).end())
    {
        ++ln;
        pos=(*ln).begin();
    }
    return *this;
}


std::istream& operator>>(std::istream& is, Document& d)
{
    for (char ch; is.get(ch); )
    {
        d.line.back().push_back(ch);
        if(ch=='\n')
            d.line.push_back(Line{});
    }
    if(d.line.back().size()) d.line.push_back(Line{});
    return is;
}

void print(Document& d)
{
    for(auto p : d) std::cout<<p;
}
void erase_line(Document& d,int n)
{
    if(n<0 || d.line.size()-1<=n) return;
    auto p = d.line.begin();
    advance(p,n);
    d.line.erase(p);
}

template<typename Iter>
void advance(Iter& p, int n)
{
    while(0<n){++p;--n;}
}

//The match() function is trivial; it just compares two sequences of chatacters. Try writing it yourself. (Page 740)
template<typename Iter>
bool match(Iter first, Iter last, const std::string& s)
{
    for (char c : s)
    {
        if(first==last) return true;
        if(*first!= c) return false;
        ++first;
    }
}

Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string& s)
{
    if(s.size()==0) return last;
    char first_char = s[0];
    while(true)
    {
        auto p = std::find(first,last,first_char);
        if(p==last || match(p,last,s)) return p;
        first=++p;
    }
}