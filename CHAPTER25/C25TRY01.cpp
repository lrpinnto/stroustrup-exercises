// CHAPTER 25 TRY 01

// Complete the program and print out the addresses and sizes of the objects created to observe memory fragmentation

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <stdexcept>

struct Device {};

struct Message
{
    Message(std::string sS)
        :s{sS} {}
    std::string s;
};

Message* get_input(Device& d)
{
    std::string s;
    for (size_t i = 0; i < 100; i++)
        s.push_back(32+rand()%(128-32)); // random 100 char string
    return new Message {s};
}

struct Node
{
    double i,j;
    int n;
};

int main()
{
    srand(time(0));

    Device dev;
    std::cout<<"Node size:"<<sizeof(Node)<<" Message size:"<<sizeof(Message)<<std::endl;

    unsigned int memoryFragmentation {0};
    bool firstPass {true};
    Message* firstAddress = get_input(dev);
    delete firstAddress;
    for (size_t i = 0; i < 40; i++)
    {
        Message* p = get_input(dev);
        if(p==firstAddress) {firstPass=false;}
        else if(firstPass) throw std::runtime_error("firstAddress fail"); // test if the first address does match the first "real" allocation
        Node* n1 = new Node;
        uintptr_t n1_hex = reinterpret_cast<uintptr_t>(n1);
        delete p;
        Node* n2 = new Node;
        uintptr_t n2_hex = reinterpret_cast<uintptr_t>(n2);
        size_t h = n1_hex-n2_hex+sizeof(n2_hex); // calculate size of fragmentation
        std::cout<<h<<'\n';
        memoryFragmentation+=h;
    }
    std::cout<<memoryFragmentation<<" bytes of memory fragmentation!\n";
    // attempt to allocate new Message object and measure the distance from the first memory allocation
    Message* p = get_input(dev);

    std::cout<<p-firstAddress;
}

// Allocation not happening as described in the book