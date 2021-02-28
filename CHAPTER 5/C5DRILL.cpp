#include "../stroustrup/std_lib_facilities.h"

//CAP 5 DRILL

int main()
{
    try
    {
        /*CODE GOES HERE*/
        //cout<<"Success!\n";
        //cout<<"Success!\n";
        //cout<<"Success"<<"!\n";
        //string success="Success!"; cout<<success<<'\n';
        //string res = "7"; vector<string>v(10);v[5]=res; cout<<"Success!\n";
        //vector<int>v(10);v[5]=7;if(v[5]=7)cout<<"Success!\n";
        //if(true)cout<<"Success!\n";else cout<<"nao";

        //string s = "ape"; bool c = true; if(c) cout<<"Success!\n";

        //string s = "Success!\n"; for(int i =0;i<6;i++) cout<<s;

        //int x = 2000; char c = x;x=c;cout<<x; if(c==-48) cout<<"Success!\n";

        //int i =0; int j = 9; while(j<10) ++j; if(j>i) cout<<"Success!\n";

        int x=2; double d = 5/(x/2); if(d==2*(x+0.5)) cout<<"Success!\n";
        return 0;
    }
    catch(exception& e)
    {
        cerr << "error"<< e.what() << '\n';
        return 1;
    }
    
    catch (...)
    {
        cerr<<"Oops: unknown exception!\n";
        return 2;
    }
    
}