// CHAPTER 21 DRILL

#include "../CHAPTER20/vectoroperators.h"
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <sstream>
#include <numeric>

struct Item
{
    std::string name;
    int iid;
    double value;
};

std::ostream& operator<<(std::ostream& os, Item& it)
{
    return os << "[name: " << it.name << ' ' << "iid: " << it.iid << ' ' << "value: " << it.value << ']';
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::list<T>& li)
{
    for(T& i : li) os << i <<' ';
    return os;
}

struct lexCompare
{
    bool operator()(const Item& x, const Item& y) const
    {
        if(x.name.compare(y.name)<1) return true;
        else return false;
    }
};

std::vector<Item> f1_1() //PART 1.1
{
    std::ifstream ifs {"C21DRILL.txt"};
    if(!ifs.is_open())
        throw std::runtime_error("File failed to load");
    std::vector<Item> vi;
    std::string s;
    int in;
    double db;
    while(ifs>>s>>in>>db)
        vi.push_back(Item{s,in,db});
    std::sort(vi.begin(), vi.end(),lexCompare());
    std::cout<<vi<<"\n\n";

    std::sort(vi.begin(), vi.end(), [](const Item& x, const Item& y){return x.iid<y.iid;});
    std::cout<<vi<<"\n\n";

    std::sort(vi.begin(), vi.end(), [](const Item& x, const Item& y){return x.value>y.value;});
    std::cout<<vi<<"\n\n";

    vi.insert(vi.end()-(vi.size()/2),{Item{"horse shoe",99,12.34},Item{"Canon S400",9988,499.95}});

    vi.erase(std::find_if(vi.begin(),vi.end(),[](Item i){return i.name=="Some_item3";}));
    vi.erase(std::find_if(vi.begin(),vi.end(),[](Item i){return i.name=="Some_item5";}));

    vi.erase(std::find_if(vi.begin(),vi.end(),[](Item i){return i.iid==7;}));
    vi.erase(std::find_if(vi.begin(),vi.end(),[](Item i){return i.iid==6;}));

    std::cout<<vi<<"\n\n";
    return vi;
}

std::list<Item> f1_2() //PART 1.2
{
    std::ifstream ifs {"C21DRILL.txt"};
    if(!ifs.is_open())
        throw std::runtime_error("File failed to load");
    std::list<Item> li;
    std::string s;
    int in;
    double db;
    while(ifs>>s>>in>>db)
        li.push_back(Item{s,in,db});
    li.sort(lexCompare());
    std::cout<<li<<"\n\n";

    li.sort([](const Item& x, const Item& y){return x.iid<y.iid;});
    std::cout<<li<<"\n\n";

    li.sort([](const Item& x, const Item& y){return x.value>y.value;});
    std::cout<<li<<"\n\n";

    auto listIter {li.end()};
    for (size_t i = li.size(); i > li.size()/2; i--)
        listIter--;
    
    li.insert(listIter,{Item{"horse shoe",99,12.34},Item{"Canon S400",9988,499.95}});

    li.erase(std::find_if(li.begin(),li.end(),[](Item i){return i.name=="Some_item3";}));
    li.erase(std::find_if(li.begin(),li.end(),[](Item i){return i.name=="Some_item5";}));

    li.erase(std::find_if(li.begin(),li.end(),[](Item i){return i.iid==7;}));
    li.erase(std::find_if(li.begin(),li.end(),[](Item i){return i.iid==6;}));

    std::cout<<li<<"\n\n";
    return li;
}

bool operator==(std::vector<Item> vi, std::list<Item> li)
{
    if(vi.size()!=li.size()) return false;
    int counter {0};
    for (const Item& i : li)
    {
        if(i.iid!=vi[counter].iid || i.name!=vi[counter].name || i.value!=vi[counter].value) return false;
        counter++;
    }
    return true;
}

template<typename T,typename H>
std::ostream& operator<<(std::ostream& os, std::map<T,H>& mp)
{
    for(const auto& i : mp)
        os << i.first << ':' << i.second << ' ';
    return os;
}

void read_values(std::istream& is, std::map<std::string, int>& mp)
{
    std::string s;
    int i;
    while(is>>s>>i) 
        mp[s]=i;
}

void f2() //PART 2
{
    std::map<std::string,int> msi;
    for (size_t i = 1; i < 11; i++)
        msi["Some_item"+std::to_string(static_cast<char>(int(i)))]=i;

    std::cout<<msi<<"\n\n";

    msi.clear();

    std::cout<<"Input values separated by space. Ctrl+D to stop\n";
    read_values(std::cin, msi);
    std::stringstream ss ("Some_item8 8 Some_item7 7 Some_item1 1 Some_item9 9 Some_item10 10 Some_item3 3 Some_item2 2 Some_item4 4 Some_item5 5 Some_item6 6");
    read_values(ss, msi);
    
    std::cout<<msi<<"\n\n";

    std::cout << std::accumulate(msi.begin(),msi.end(),0,[](int a, std::pair<std::string,int> p){return a+p.second;}) <<"\n\n";

    std::map<int,std::string> mis;
    for(const auto& p : msi) //if there are matching values this will cause one of the elements to override since each key has to be unique
        mis[p.second]=p.first;

    std::cout<<mis<<"\n\n";
}

void f3() //PART 3
{
    std::ifstream ifs {"C21DRILL2.txt"};
    if(!ifs.is_open())
        throw std::runtime_error("File failed to load");
    std::vector<double> vd;
    float f;
    while(ifs>>f)
        vd.push_back(f);

    std::cout<<vd<<"\n\n";
    std::vector<int> vi(vd.size());
    std::copy(vd.begin(),vd.end(),vi.begin());
    for (size_t i = 0; i < vi.size(); i++)
        std::cout<<vd[i]<<','<<vi[i]<<'\n';
    
    std::cout<<'\n';

    std::cout<<std::accumulate(vd.begin(),vd.end(),0.0)<<"\n\n";
    std::cout<<std::accumulate(vd.begin(),vd.end(),0.0)-std::accumulate(vi.begin(),vi.end(),0.0)<<"\n\n";

    std::reverse(vd.begin(),vd.end());
    std::cout<<vd<<"\n\n";

    double mean {std::accumulate(vd.begin(),vd.end(),0.0)/vd.size()};
    std::cout<<mean<<"\n\n";

    std::vector<double> vd2(vd.size());
    std::copy_if(vd.begin(),vd.end(),vd2.begin(),[mean](double x){return x<mean;}); //since vd2 is initialized to vd.size() it means that left-over
                                                                                    //elements will be double()
    std::sort(vd.begin(),vd.end());
    std::cout<<vd<<'\n';
}

int main()
{
    if (f1_1()==f1_2())
        std::cout<<"List and vector match."<<"\n\n";
    else throw std::runtime_error("List and vector dont match");

    std::cout<<"-------------------------PART 2----------------\n";
    f2();
    std::cout<<"-------------------------PART 3----------------\n";
    f3();
}
