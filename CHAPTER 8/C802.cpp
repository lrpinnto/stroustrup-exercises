#include "../stroustrup/std_lib_facilities.h"

//CAP 8 EXERCISE 2

void print(string label, const vector<int>& numbers)
{
    cout << label << ": ";

    for (int i : numbers) cout << i << ' ';

    cout << '\n';
}