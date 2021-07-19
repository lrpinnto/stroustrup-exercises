#include "../stroustrup/std_lib_facilities.h"

//CHAPTER 11 EX 04
//used Chrinkus solution

int main()
{
    cout << "Please input integers: (Prefix 0x for hexadecimal, 0 for octal, nothing for decimal)\n";

    while (cin) {
        string input;
        cin >> input;
        stringstream ss {input};
        ss.unsetf(ios::dec);

        int value;
        ss >> value;

        cout << setw(12) << showbase;

        if (input[0] == '0') {
            if (input[1] == 'x' || input[1] == 'X') {
                cout << hex << value << " hexadecimal\t";
            } else {
                cout << oct << value << " octal\t\t";
            }
        } else {
            cout << dec << value << " decimal\t\t";
        }

        cout << "converts to\t"
             << dec << value << " decimal\n";
    }
}
