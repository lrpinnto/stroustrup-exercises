// CHAPTER 21 EX 09

// Define an Order class with (customer) name, address, data, and vector<Purchase> members. Purchase is a class with a (product) name, unit_price, and count members.
// Define a mechanism for reading and writing Orders to and from a file.
// Define a mechanism for printing Orders.
// Create a file of at least 10 Orders, read it into a vector<Order>, sort it by name (of customer), and write it back out to a file.
// Create another file of at least 10 Orders of which about 1/3 are the same as in the first file, read it into a list<Order>, sort it by address
// (of customer), and write it back out to a file. Merge the 2 files into a third using std::merge().

#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <list>

class Date
{
private:
    int year_, month_, day_;
    std::chrono::time_point<std::chrono::system_clock> time_;

    static int days_since_epoch(int year, int month, int day)
    {
        int a { (14 - month) / 12 };
        int y { year + 4800 - a };
        int m { month + 12 * a -3 };
        return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    }
public:
    Date(int year=0, int month=0, int day=0)
        :year_{year}, month_{month}, day_{day}
    {
        auto tp { std::chrono::time_point<std::chrono::system_clock>{} };
        tp+=std::chrono::hours{ 24 * (days_since_epoch(year, month, day) - days_since_epoch(1970,1,1)) };
        time_ = tp;
    }

    int year() const { return year_;}
    int month() const { return month_;}
    int day() const { return day_;}
    std::time_t timestamp() const {return std::chrono::system_clock::to_time_t(time_);}
};

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    os << d.day() << '/' << d.month() << '/' << d.year();
    return os;
}

bool operator==(const Date& d1, const Date& d2)
{
    return d1.timestamp()==d2.timestamp();
}

struct Purchase
{
    std::string name;
    double unit_price;
    int count;
    Purchase(){}
    Purchase(const std::string& namee, const double& unit_pricee, const int& countt)
        : name{namee}, unit_price{unit_pricee}, count{countt} {}
};

bool operator==(const Purchase& p1, const Purchase& p2)
{
    return p1.name==p2.name && p1.unit_price==p2.unit_price && p1.count==p2.count;
}

struct Order
{
    std::string name;
    std::string address;
    Date d;
    std::vector<Purchase> pur;
    Order(){}
    Order(const std::string& namee, const std::string& addresss, const Date& dd, const std::vector<Purchase>& purr)
        :name{namee}, address{addresss}, d{dd}, pur{purr} {}
};

bool operator==(const Order& o1, const Order& o2)
{
    return o1.name==o2.name && o1.address==o2.address && o1.d==o2.d && o1.pur==o2.pur;
}

bool operator!=(const Order& o1, const Order& o2)
{
    return !(o1==o2);
}

std::istream& operator>>(std::istream& is, std::vector<Purchase>& v) //reads characters between {}
{
    char curlyBrackets;
    is>>curlyBrackets;
    std::string s;
    if(curlyBrackets!='{') throw std::runtime_error("Order input is incorrectly formatted: purchase");
    else std::getline(is,s); //exhaust useless line

    std::string s_name;
    std::string s_unit_price;
    std::string s_count;
    std::string s_fields; //meant for what's after name:,address:,...

    std::vector<Purchase> temp_vec;

    while(std::getline(is,s))
    {
        Purchase temp_purchase;
        std::stringstream ss {s};
        char c;
        double d;
        int i;
        ss>>c;
        if(c=='}') break;
        else ss.putback(c);

        ss >> s_name;
        if(s_name!="name:") throw std::runtime_error("Order input is incorrectly formatted: name");
        s.clear();
        while(ss>>s_fields)
        {
            if(s_fields==";") break;
            else if(s.empty()) s=s_fields;
            else s+=" "+s_fields;
        }
        temp_purchase.name=s;

        ss >> s_unit_price;
        if(s_unit_price!="unit_price:") throw std::runtime_error("Order input is incorrectly formatted: unit_price");
        s.clear();
        s_fields.clear();
        if(!(ss>>d>>c)) throw std::runtime_error("Order input is incorrectly formatted: unit_price"); 
        if(c!=';') throw std::runtime_error("Order input is incorrectly formatted: unit_price");
        temp_purchase.unit_price=d;

        ss >> s_count;
        if(s_count!="count:") throw std::runtime_error("Order input is incorrectly formatted: count");
        s.clear();
        s_fields.clear();
        if(!(ss>>i>>c)) throw std::runtime_error("Order input is incorrectly formatted: count"); 
        if(c!=';') throw std::runtime_error("Order input is incorrectly formatted: count");
        temp_purchase.count=i;

        temp_vec.push_back(temp_purchase);
    }
    
    for(const auto& p : temp_vec)
        v.push_back(p);

    return is;
}

std::istream& operator>>(std::istream& is, Order& o)
{
    std::string s;
    std::getline(is,s);
    if(is.peek() == EOF /*|| is.peek() == ' '*/) 
    {
        getline(is,s); //exhaust useless line
        return is;
    }
    std::stringstream ss {s};

    std::vector<Purchase> temp_purchase;
    Order temp_order;
    std::string s_name;
    std::string s_address;
    std::string s_date;
    std::string s_purchase;
    std::string s_fields; //meant for what's after name:,address:,...

    ss >> s_name;
    if(s_name!="name:") throw std::runtime_error("Order input is incorrectly formatted: name");
    s.clear();
    while(ss>>s_fields)
    {
        if(s_fields==";") break;
        else if(s.empty()) s=s_fields;
        else s+=" "+s_fields;
    }
    temp_order.name=s;

    ss >> s_address;
    if(s_address!="address:") throw std::runtime_error("Order input is incorrectly formatted: address");
    s.clear();
    s_fields.clear();
    while(ss>>s_fields)
    {
        if(s_fields==";") break;
        else if(s.empty()) s=s_fields;
        else s+=" "+s_fields;
    }
    temp_order.address=s;

    ss >> s_date;
    if(s_date!="date:") throw std::runtime_error("Order input is incorrectly formatted: date");
    s.clear();
    s_fields.clear();
    while(ss>>s_fields)
    {
        if(s_fields==";") break;
        else s+=" "+s_fields;
    }
    std::replace(s.begin(),s.end(),'/',' ');
    std::stringstream process_date {s};
    int year, month, day;
    process_date>>day>>month>>year;
    temp_order.d = Date(year,month,day);

    ss >> s_purchase;
    if(s_purchase!="purchase:") throw std::runtime_error("Order input is incorrectly formatted: purchase");

    is >> temp_purchase;
    temp_order.pur = temp_purchase;
    o=temp_order;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Purchase& p)
{
    os << "name: " << p.name << " ; unit_price: " << p.unit_price << " ; count: " << p.count << " ;";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Order& o)
{
    os << "name: " << o.name << " ; address: " << o.address << " ; date: " << o.d << " ; purchase:\n{\n";
    for (const auto& p : o.pur)
        os << p <<'\n';
    os << "}";
    return os;
}

void read_orders(std::istream& is, std::vector<Order>& v)
{
    Order o;
    while(is>>o) v.push_back(o);   
}

void read_orders(std::istream& is, std::list<Order>& l)
{
    Order o;
    while(is>>o) l.push_back(o);   
}

template<typename T>
void write_orders(std::ostream& os, const T& v)
{
    for(const auto& o : v)
        os<<o<<'\n';
}

int main()
{  
    std::vector<Order> v;
    std::ifstream ifs {"C21E09.txt"};
    if(!ifs.is_open())
        throw std::runtime_error("File failed to load");
    read_orders(ifs,v);
    ifs.close();

    std::sort(v.begin(),v.end(),[](Order a, Order b){ return a.name < b.name; });

    std::ofstream ofs {"C21E09out.txt"};
    if(!ofs.is_open())
        throw std::runtime_error("File failed to load");
    write_orders(ofs,v);
    ofs.close();

    std::list<Order> l;
    std::ifstream ifs2 {"C21E09_2.txt"};
    if(!ifs2.is_open())
        throw std::runtime_error("File failed to load");
    read_orders(ifs2,l);
    ifs2.close();

    l.sort([](Order a, Order b){ return a.address < b.address; });

    std::ofstream ofs2 {"C21E09out_2.txt"};
    if(!ofs2.is_open())
        throw std::runtime_error("File failed to load");
    write_orders(ofs2,l);
    ofs2.close();

    std::ifstream ifs3 {"C21E09out.txt"};
    if(!ifs3.is_open())
        throw std::runtime_error("File failed to load");
    
    std::ifstream ifs4 {"C21E09out_2.txt"};
    if(!ifs4.is_open())
        throw std::runtime_error("File failed to load");

    std::string ifs3_s;
    char c;
    while(ifs3.get(c)) ifs3_s.push_back(c);
    std::string ifs4_s;
    while(ifs4.get(c)) ifs4_s.push_back(c);

    std::ofstream ofs3 {"C21E09out_final.txt"};
    if(!ofs3.is_open())
        throw std::runtime_error("File failed to load");

    std::vector<char> oo (ifs3_s.size()+ifs4_s.size());

    std::merge(ifs3_s.begin(),ifs3_s.end(),ifs4_s.begin(),ifs4_s.end(),oo.begin());

    for(const auto& k : oo)
        ofs3<<k;
}
