//Chapter 19 Ex 11

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
class counted_ptr
{
private:
    T* object;
    int* counter;
public: //bug: unintended implicit conversions when numeric values are at play -> (double, int) tries to narrow convert int to double
    explicit counted_ptr(T, int num_of_elements = 1); //constructor
    explicit counted_ptr(initializer_list<T>);
    counted_ptr(const counted_ptr&); //copy constructor with counter
    T& operator*(){return *object;}
    T* operator->() const {return object;}
    ~counted_ptr(); //destructor
    T& operator[](int n){return object[n];};

    counted_ptr& operator=(counted_ptr&); //copy assignment
    counted_ptr(counted_ptr&&); //move constructor
    counted_ptr& operator=(counted_ptr&&); //move assignment
};

template<typename T> //bug: when using (int,int), initializer_list gets called instead
counted_ptr<T>::counted_ptr(T p, int num_of_elements ) //create an "array" of n repeating values
    :object{new T[num_of_elements]}, counter{new int}
{
    for (int i = 0; i < num_of_elements; i++) //not ideal. Instead need to find a way to directly call the constructor for each element instead of implicitly using
    {                                          //using default construction with new
        object[i]=p;
    }
}

template<typename T>
counted_ptr<T>::counted_ptr(initializer_list<T> lst )
    :object{new T[lst.size()]}, counter{new int}
{
    std::copy(lst.begin(),lst.end(),object); 
}

template<typename T>
counted_ptr<T>::counted_ptr(const counted_ptr& cp)
    : object{cp.object}, counter{cp.counter}
{
    (*counter)++;
}

template<typename T>
counted_ptr<T>::~counted_ptr()
{
    cout<<"calling destructor with current counter "<<*counter<<'\n';
    if(*counter<1)
    {
        delete[] object;
        delete counter;
    }
    else
    {
        (*counter)--;
    }   
}

template<typename T>
counted_ptr<T>& counted_ptr<T>::operator=(counted_ptr& cp) //copy assignment
{
    object=cp.object;
    counter=cp.counter;
    (*counter)++;

    return *this;
}

template<typename T>
counted_ptr<T>::counted_ptr(counted_ptr&& cp) //move constructor
    :object{cp.object}, counter{cp.counter}
{
    cout<<"Moving counter_ptr through construction...\n"; //won't output?
    //since it's a move, there is no need to increment the counter
    cp.object=nullptr;
    cp.counter=nullptr;
}

template<typename T>
counted_ptr<T>& counted_ptr<T>::operator=(counted_ptr&& cp) //move assignment
{
    cout<<"Moving counter_ptr through assingment...\n";
    delete[] object;
    object=(cp.object);
    delete counter;
    counter=cp.counter;

    cp.object=nullptr;
    cp.counter=nullptr;

    return *this;
}

counted_ptr<string> f1(string d, int n)
{
    counted_ptr<string> cpr {d,n};
    return cpr;
}

int main()
{
    counted_ptr<int> pr {10,3};
    cout<<pr[1];

    counted_ptr<string> pre {"test",20};
    cout<<pre[19];

    counted_ptr<string>abc {pre};
    cout<<abc[2];

    counted_ptr<string> something{f1("123",4)};
}