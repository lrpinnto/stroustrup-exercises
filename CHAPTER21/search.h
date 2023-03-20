namespace search
{
template<typename Ran, typename T>
bool binary_search(Ran first, Ran last, const T& val)
{
    auto middle = first + (last - first) / 2;
    if(last==middle) return false; //IS THIS RIGHT?
    if(*middle==val) return true;
    if(*middle>val) search::binary_search(first,middle,val);
    else search::binary_search(middle+1,last,val);
}

template<typename Ran, typename T, typename Cmp>
bool binary_search(Ran first, Ran last, const T& val, Cmp cmp)
{
    auto middle = first + (last - first) / 2;
    if(last==middle) return false; //IS THIS RIGHT?
    if (cmp(*middle,val)) search::binary_search(middle+1,last,val,cmp);
    else if (cmp(val,*middle))  search::binary_search(first,middle-1,val,cmp);
    else return true;
}
/*  FOR LIST
template<typename Iterator, typename T>
bool binary_search(Iterator first, Iterator last, const T& val)
{
    auto middle = first + (last - first) / 2;
    if(last==middle) return false; //IS THIS RIGHT?
    if(*middle==val) return true;
    if(*middle>val) search::binary_search(first,middle,val);
    else search::binary_search(middle+1,last,val);
}

template<typename Iterator, typename T, typename Cmp>
bool binary_search(Iterator first, Iterator last, const T& val, Cmp cmp)
{
    auto middle = first + (last - first) / 2;
    if(last==middle) return false; //IS THIS RIGHT?
    if (cmp(*middle,val)) search::binary_search(middle+1,last,val,cmp);
    else if (cmp(val,*middle))  search::binary_search(first,middle-1,val,cmp);
    else return true;
}*/
}