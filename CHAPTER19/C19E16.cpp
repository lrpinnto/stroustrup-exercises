//Chapter 19 EX 16
//Fully reworked vector version from ./vector.h
#include <iostream>
#include <vector>

//(...)vector itself consists only of a pointer to 
//a representation consisting of the elements
//the number of elements
//the space pointer
//sizeof(vector<int>)==sizeof(int*)


struct out_of_range : std::out_of_range {	// enhanced vector range error reporting
	int index;
	out_of_range(int i) :std::out_of_range("Range error: "+std::to_string(i)), index(i) { }
};

template<typename T> class allocator //manipulates uninitialized storage
{
public:
    T* allocate(int n){return (T*) malloc(n * sizeof(T));}
    void deallocate(T* p, int n){free(p);}

    void construct(T* p, const T& v){new(p) T{v};}
    void destroy(T* p){p->~T();}
};

template<typename T, typename A>
struct vector_base
{
    A alloc;
    T* elem;
    int sz;
    int space;

    vector_base(int n)
        :elem{alloc.allocate(n)},sz{n},space{n}{}
    ~vector_base() {alloc.deallocate(elem,space);}
};

template<typename T, typename A = allocator<T>>
class minivector 
{
    vector_base<T,A>* vec;
public:
//CONSTRUCTORS
    minivector()
        :vec{new vector_base<T,A>{0}} {}
    explicit minivector(int s) :vec{new vector_base<T,A>{s}}
    {/*
        for (int i = 0; i < vec->sz; ++i)
        {
            vec->elem[i]=0;
        }*/
    }
    minivector(std::initializer_list<T> lst)
        :vec{new vector_base<T,A>{static_cast<int>(lst.size())}}
    {
        std::copy(lst.begin(),lst.end(),vec->elem);
    }
//COPY CONSTRUCTOR
    minivector(const minivector& arg)
        :vec{new vector_base<T,A>{static_cast<int>(arg.vec->sz)}} //static cast just "in case"
    {
        std::cout<<"COPY CONSTRUCTOR";
        std::copy(arg.vec->elem,&arg.vec->elem[arg.vec->sz],vec->elem);
    }
    
//COPY ASSIGNMENT
    minivector& operator=(const minivector& a)
    {
        std::cout<<"COPY ASSIGNMENT";
        T* p=new T[a.vec->sz];
        std::copy(a.vec->elem,&a.vec->elem[a.vec->sz],p);
        delete[] vec->elem;
        vec->elem=p;
        vec->sz=a.vec->sz;
        return *this;
    }

//MOVING CONSTRUCTOR
    minivector(minivector&& a) //Not sure how to test
        :vec{new vector_base<T,A>{static_cast<int>(a.vec->sz)}}
    {
        std::cout<<"MOVING CONSTRUCTOR";
        std::copy(a.vec->elem,&a.vec->elem[a.vec->sz],vec->elem);
        a.vec->sz=0;
        a.vec->elem=nullptr;
    }
//MOVING ASSIGNMENT
    minivector& operator=(minivector&& a)
    {
        std::cout<<"MOVING ASSIGNMENT";
        delete[] vec->elem;
        vec->elem=a.vec->elem;
        vec->sz=a.vec->sz;
        a.vec->elem=nullptr;
        a.vec->sz=0;
        return *this;
    }
//DESTRUCTOR
    ~minivector(){ delete vec;}

    T& operator[](int n) {return vec->elem[n];}
    const T& operator[](int n) const {return vec->elem[n];}

    int size() const {return vec->sz;}
    int capacity() const {return vec->space;}
    /*
    void resize(int newsize,T val = T());
    void push_back(const T& d);
    void reserve(int newalloc);
    */

    T& at(int n){ if(n<0||vec->sz<=n)throw out_of_range(n); return vec->elem[n]; }
    const T& at(int n) const{ if(n<0||vec->sz<=n)throw out_of_range(n); return vec->elem[n]; }
};

template<typename T> minivector<T> f(const minivector<T>& something)
{
    minivector<T>abc{something};
    return abc;
}

int main()
try {
    //DEFAULT CONSTRUCTOR TEST
    minivector<int>abc;
    std::cout<<"minivector sizeof: "<<sizeof(abc);
    std::cout<<" = int* sizeof: "<<sizeof(int*);

    //CONSTRUCTOR TEST
    minivector<int>cnd(10);
    std::cout<<'\n';
    //INIT_LIST TEST
    minivector<int>dsf{1,2,3,4,5,6,7,8,9,10};
    std::cout<<dsf[9];
    std::cout<<'\n';
    //COPY CONSTRUCT TEST
    minivector<int>dasd(dsf);
    std::cout<<dasd[9];
    std::cout<<'\n';
    //COPY ASSIGN TEST
    abc=dasd;
    std::cout<<abc[9];
    std::cout<<'\n';
    //MOVING TEST

    minivector<int>saa(f(abc));
    std::cout<<saa[9];
    std::cout<<'\n';
    saa=f(abc);
    std::cout<<saa[9];

//-----------------
    std::cout<<'\n';
    
    std::vector<int> v;
    std::cout << "sizeof vector: " << sizeof(v) << "\n";
    minivector<int> mv;
    std::cout << "sizeof Mini_vec: " << sizeof(mv) << "\n";

    minivector<int> mv10 = minivector<int>(10);
    std::cout << mv10[1] << "\n";
    for (int i = 0; i<mv10.size(); ++i)
        mv10[i] = i;
    for (int i = 0; i<mv10.size(); ++i)
        std::cout << mv10[i] << ' ';
    std::cout << "\n";

    minivector<int> mv_cpctr = mv10;
    for (int i = 0; i<mv_cpctr.size(); ++i)
        std::cout << mv_cpctr[i] << ' ';
    std::cout << "\n";

    minivector<int> mv_cpasgn;
    mv_cpasgn = mv10;
    for (int i = 0; i<mv_cpasgn.size(); ++i)
        std::cout << mv_cpasgn[i] << ' ';
    std::cout << "\n";
    /*
    mv_cpasgn.resize(5);
    for (int i = 0; i<mv_cpasgn.size(); ++i)
        std::cout << mv_cpasgn[i] << ' ';
    std::cout << "\n";
    */
    std::vector<std::vector<std::vector<int> > > v3(100);
    minivector<minivector<minivector<int> > > mv3(100);
    std::cout << "sizeof vector<vector<vector<int> > >: " << sizeof(v3) << "\n";
    std::cout << "sizeof  Mini_vec<Mini_vec<Mini_vec<int> > >: " << sizeof(mv3) << "\n";
    /*
    Mini_vec<int> mv4;
    for (int i = 0; i<10; ++i)
        mv4.push_back(i);
    for (int i = 0; i<mv4.size(); ++i)
        std::cout << mv4[i] << ' ';
    std::cout << "\n";
    */
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}