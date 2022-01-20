//Chapter 19 Try this 02 
//add header vector
void suspicious(vector<int>& v, int s)
{
    try{
        int* p = new int[s];
    }catch(bad_alloc)
    {
        delete[] p;
        throw;
    }
    vector<int>v1;
    try{
        int* q = new int[s];
    }catch(bad_alloc)
    {
        delete[] p;
        delete[] q;
        throw;
    }
    vector<double> v2;

    delete[] p;
    delete[] q;
}