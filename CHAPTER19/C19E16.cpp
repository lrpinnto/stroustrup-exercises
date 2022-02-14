//Chapter 19 Ex 16
//TO BE REDONE (placeholder code)

#include <iostream>
#include <vector>

template<class T> struct Vec_rep {
    int sz;
    T* elem;
    int space;

    Vec_rep() : sz(0), elem(0), space(0) { }
    Vec_rep(int s) : sz(s), elem(new T[s]), space(s)
    {
        for (int i = 0; i<sz; ++i) elem[i]=T();
    }
};

template<class T> class Mini_vec {
    Vec_rep<T>* vec;
public:
    Mini_vec() : vec(new Vec_rep<T>()) { }
    explicit Mini_vec(int s) : vec(new Vec_rep<T>(s)) { }

    Mini_vec(const Mini_vec& arg) : vec(new Vec_rep<T>(arg.vec->sz))
    {
        for (int i = 0; i<arg.vec->sz; ++i) vec->elem[i] = arg.vec->elem[i];
    }

    Mini_vec& operator=(const Mini_vec& a)
    {
        if (this==&a) return *this;

        if (a.vec->sz <= vec->space) {
            for (int i = 0; i<a.vec->sz; ++i) vec->elem[i] = a.vec->elem[i];
            vec->sz = a.vec->sz;
            return *this;
        }

        Vec_rep<T>* p = new Vec_rep<T>(a.vec->sz);
        for (int i = 0; i<a.vec->sz; ++i) p->elem[i] = a.vec->elem[i];
        delete vec;
        vec = p;
        return *this;
    }

    ~Mini_vec() { delete vec; }

    T& operator[](int n) { return vec->elem[n]; }
    const T& operator[](int n) const { return vec->elem[n]; }

    int size() const { return vec->sz; }
    int capacity() const { return vec->space; }

    void resize(int newsize)
    {
        reserve(newsize);
        vec->sz = newsize;
    }

    void push_back(const T& d)
    {
        if (vec->space==0) reserve(8);
        else if (vec->sz==vec->space) reserve(2*vec->space);
        vec->elem[vec->sz] = d;
        ++vec->sz;
    }

    void reserve(int newalloc)
    {
        if (newalloc<=vec->space) return;
        Vec_rep<T>* p = new Vec_rep<T>(newalloc);
        p->sz = vec->sz;
        for (int i = 0; i<vec->sz; ++i) p->elem[i] = vec->elem[i];
        delete vec;
        vec = p;
    }
};

int main()
try {
    std::vector<int> v;
    std::cout << "sizeof vector: " << sizeof(v) << "\n";
    Mini_vec<int> mv;
    std::cout << "sizeof Mini_vec: " << sizeof(mv) << "\n";

    Mini_vec<int> mv10 = Mini_vec<int>(10);
    std::cout << mv10[0] << "\n";
    for (int i = 0; i<mv10.size(); ++i)
        mv10[i] = i;
    for (int i = 0; i<mv10.size(); ++i)
        std::cout << mv10[i] << ' ';
    std::cout << "\n";

    Mini_vec<int> mv_cpctr = mv10;
    for (int i = 0; i<mv_cpctr.size(); ++i)
        std::cout << mv_cpctr[i] << ' ';
    std::cout << "\n";

    Mini_vec<int> mv_cpasgn;
    mv_cpasgn = mv10;
    for (int i = 0; i<mv_cpasgn.size(); ++i)
        std::cout << mv_cpasgn[i] << ' ';
    std::cout << "\n";

    mv_cpasgn.resize(5);
    for (int i = 0; i<mv_cpasgn.size(); ++i)
        std::cout << mv_cpasgn[i] << ' ';
    std::cout << "\n";

    std::vector<std::vector<std::vector<int> > > v3(100);
    Mini_vec<Mini_vec<Mini_vec<int> > > mv3(100);
    std::cout << "sizeof vector<vector<vector<int> > >: " << sizeof(v3) << "\n";
    std::cout << "sizeof  Mini_vec<Mini_vec<Mini_vec<int> > >: " << sizeof(mv3) << "\n";

    Mini_vec<int> mv4;
    for (int i = 0; i<10; ++i)
        mv4.push_back(i);
    for (int i = 0; i<mv4.size(); ++i)
        std::cout << mv4[i] << ' ';
    std::cout << "\n";
}
catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
}
catch (...) {
    std::cerr << "exception\n";
}