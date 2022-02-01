#include "../stroustrup/std_lib_facilities.h"

//CAP 4 EX 4

/*
Ask about 50.

    If too high, then ask about 25.

    If too low, then ask about 75.

Continue, continually halving the search-space. This requires ⌈log2(n+1)⌉
maximum questions. For 100, that's 7. It is a binary search algorithm known to be O(log(n)) time. I'm fairly sure there isn't a faster way. Binary search is considered the best for this problem - unless you are allowed to ask other questions.
*/
int divi (int h, int ansvalue, char w)
{
    double number=100;
    for (int i = 0; i < h; i++)
    {
        number/=2;
        number=round(number);  
    }
    if (w=='y')
    {
        ansvalue+=number;
    }
    else if (w=='n')
    {
        ansvalue=ansvalue-number;
    }
    else  //First value : will always be 100/2=50 (it's the "true" definition of the var)
    {
        ansvalue=number;
    }
    return ansvalue;
}

int main()
{
    int guess=0;
    char rep=0;
    int num=0;  //Doesn't do anything besides declaring the var
    cout<<"Enter a number between 0 and 100:";
    cin>>guess;
    cout<<"\nGuessing game (answer y or n)\n";
    for (int i = 1; i < 8; i++)
    {
        num=divi(i,num,rep);
        cout<<"Is you number higher than "<<num<<"?\t";
        cin>>rep;
    }

    if (num==guess)
    {
        cout<<"\nIt's "<<num<<"!!";
    }
    else
    {
        cout<<"\nYou are lying";
    }
}