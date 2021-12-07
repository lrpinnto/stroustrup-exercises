char* strdup(const char * s) //EX 1
{
    int n {1};
    while(*s){++s;++n;}
    for (int i = 1; i < n; i++)
        --s;
    char* p {new char[n]{*s}};
    for (int i = 1; i < n; i++)
    {
        *++p=*++s;
    }
    for (int i = 1; i < n; i++)
        --p;
    return p;
}

const char* findx(const char* s, const char* x) //EX 2
{
    int is {1};
    while(*s){++s;++is;} //get array size
    for (int i = 1; i < is; i++)
        --s;
    
    int ix {1};
    while(*x){++x;++ix;} //get array size
    for (int i = 1; i < ix; i++)
        --x;
    if(ix>=is) return nullptr; //throw error 

    while(*s)
    {
        if (*s==*x)
        {
            for (int u = 0;x;u++)
            {   
                if(*x!=*s)
                {
                    //rewind and break
                    for (int h = 0; h < u; h++)
                    {
                        --s;
                        --x;
                    }
                    break;
                }
                else if(!*++x) //check if next char is 0
                {
                    --x; //extra rewind for 0
                    for (int h = 0; h < u; h++)
                    {
                        --x; 
                        --s;
                    }
                    return s;
                }
                ++s;
            }
        }
        ++s;
    }
    return nullptr;
}
int strcmp(const char* s1, const char* s2) //EX 3
{
    while(*s1 && *s2)
    {
        if(*s1<*s2)
            return -1;
        else if(*s1>*s2)
            return 1;
        ++s1;
        ++s2;
    }
    if(*s1<*s2)
        return -1;
    else if(*s1>*s2)
        return 1;
    else return 0;
}

namespace improved //EX 4   (untested)
{
    char* strdup(const char * s, const int max = 128) 
    {
        int n {1};
        while(*s && n<max){++s;++n;} //restricts array size to int max
        for (int i = 1; i < n; i++)
            --s;
        char* p {new char[n]{*s}};
        for (int i = 1; i < n; i++)
        {
            *++p=*++s;
        }
        for (int i = 1; i < n; i++)
            --p;
        return p;
    }
    const char* findx(const char* s, const char* x, const int max = 128) 
    {
        int is {1};
        while(*s && is<max){++s;++is;} //get array size
        for (int i = 1; i < is; i++)
            --s;
        
        int ix {1};
        while(*x && ix<max){++x;++ix;} //get array size
        for (int i = 1; i < ix; i++)
            --x;
        if(ix>=is) return nullptr; //throw error 

        while(*s)
        {
            if (*s==*x)
            {
                for (int u = 0;x;u++)
                {   
                    if(*x!=*s)
                    {
                        //rewind and break
                        for (int h = 0; h < u; h++)
                        {
                            --s;
                            --x;
                        }
                        break;
                    }
                    else if(!*++x) //check if next char is 0
                    {
                        --x; //extra rewind for 0
                        for (int h = 0; h < u; h++)
                        {
                            --x; 
                            --s;
                        }
                        return s;
                    }
                    ++s;
                }
            }
            ++s;
        }
        return nullptr;
    }
    int strcmp(const char* s1, const char* s2, const int max = 128) //EX 3
    {
        int counter {0};
        while(*s1 && *s2 && counter<max)
        {
            if(*s1<*s2)
                return -1;
            else if(*s1>*s2)
                return 1;
            ++s1;
            ++s2;
            ++counter;
        }
        if(*s1<*s2)
            return -1;
        else if(*s1>*s2)
            return 1;
        else return 0;
    }
}