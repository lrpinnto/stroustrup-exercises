//CHAPTER 19 EX 06

#include <iostream>
#include "./Number.h"

using namespace std;

int main()
try {
    Number<int> copy_const {10};
    cout<<"Copy constructor(Number): "<<copy_const<<'\n';
    copy_const=11;
    cout<<"Operator=(Number) "<<copy_const<<'\n';

    Number<int> copy_constt {Number<int>(20)};
    cout<<"Copy constructor: "<<copy_constt<<'\n';
    copy_constt=Number<int>(21);
    cout<<"Operator= "<<copy_constt<<'\n';

    Number<int> abc;
    cin>>abc;
    cout<<copy_const+(copy_constt)*abc<<'\n';

    Number<double> h1{2};
    Number<int> h2{2};
    //cout<<h1%h1; //error: invalid operands of types ‘double’ and ‘double’ to binary ‘operator%’
    //cout<<h1%h2<<'\n'; //error: invalid operands of types ‘double’ and ‘int’ to binary ‘operator%’
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}