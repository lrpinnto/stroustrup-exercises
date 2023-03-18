// CHAPTER 21 TRY 05

// Write a small program using #include<unordered_map>.

#include <unordered_map>
#include <string>
#include <iostream>

struct Person
{
    std::string name;
    std::string address;

    bool operator==(const Person& person2) const {
        return name==person2.name && address==person2.address;
    }
};

struct PersonHash
{
    std::size_t operator()(const Person& p) const {
        std::cout<<"hash:"<<(std::hash<std::string>()(p.name) ^ ( std::hash<std::string>()(p.address) << 1 ))<<'\n';
        return std::hash<std::string>()(p.name) ^ ( std::hash<std::string>()(p.address) << 1 );
    }
    //std::hash<std::string>() is creating a temporary object (using the default constructor) and imediatly invoking the operator() with the
    //argument p.name.
    //both expressions generate an hash value, the one on the right is left-shifted by 1 bit
    // '^'  performs a bitwise XOR operation between the 2 values 
    // the resuling hash is then returned
};

int main()
{
    std::unordered_map<Person, int, PersonHash> personMap; 
    Person pa {"Some person1"," Some address1"};
    Person pb {"Some person2"," Some address2"};
    Person pc {"Some person3"," Some address3"};

    personMap[pa] = 45;
    personMap[pb] = 46;
    personMap[pc] = 47;

    std::cout << personMap[pb] <<'\n';
    std::cout << personMap[{"Some person2"," Some address2"}] <<'\n'; //both are equivalent 
}