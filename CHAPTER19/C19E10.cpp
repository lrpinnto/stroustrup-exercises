//Chapter 19 ex 10

#include <vector>
#include <iostream>

template<typename T>
class unique_ptr
{
private:
    T* object;
public:
    explicit unique_ptr(T*);
    ~unique_ptr();

    T& operator*(){return *object;}
    //https://stackoverflow.com/questions/8777845/overloading-member-access-operators
    T* operator->() const {return object;}
    T* release();
};

template<typename T>
unique_ptr<T>::unique_ptr(T* p)
    :object{p} {std::cout<<"calling constructor...";}

template<typename T>
unique_ptr<T>::~unique_ptr()
{
    std::cout<<"calling destructor...";
    delete object;
}

template<typename T>
T* unique_ptr<T>::release()
{
    T* temp_p {this->object};
    this->object=nullptr;
    return temp_p;
}

unique_ptr<std::string> f(std::string s)
{
    unique_ptr<std::string> p {new std::string{s}};
    return p;
}

int main()
{
    unique_ptr<std::vector<int>> abc {new std::vector<int>};
    std::cout<<abc->empty(); //test for empty vector
    abc->push_back(1);
    std::cout<<abc->empty(); //retest to see if operator-> works
    abc->clear();
    std::cout<<abc->empty();
    abc->push_back(9);
    std::cout<<(*abc)[0];
    std::vector<int>* p {abc.release()}; //returned a raw pointer. Someone still needs to delete it
    std::cout<<(*p)[0];
    delete p;
    unique_ptr<std::string> up {f("test string")}; //no need to delete or release the pointer. Will call destructor by the end of scope
}