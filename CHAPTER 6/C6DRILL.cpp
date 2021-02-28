
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
    This file is known as calculator02buggy.cpp

    I have inserted 5 errors that should cause this not to compile
    I have inserted 3 logic errors that should cause the program to give wrong results

    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)

    Happy hunting!

*/

#include "../stroustrup/std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token{  //ERROR 1. "class" missing
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()  //ERROR 2. MISSING CONTRUCTOR(?) TO Token_stream
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': case '%':  //LOGIC ERROR 2. MISSING %
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':   //MISSING 8
    case '5': case '6': case '7': case '9': case '8':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('H', val);   // let '8' represent "a number" //LOGIC ERROR. IF USING 8 CAUSES ERROR. USE H INSTEAD.
    }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");  //ERROR 3. MISSING "
            return d;
    }
    case 'H':            // we use '8' to represent a number
        return t.value;  // return the number's value
    case 'x':                        //LOGIC ERROR? ADD X functionality.
        return 6969696969669.9;  //really REALLY shitty fix.
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
        {
            double d = primary();
            left *= d;  //LOGIC ERROR 1. NO DECLARATION OF d as primary, wrong expression "left *= primary()". Also no break. Also no {}
            t = ts.get();
            break;
        }
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }

        case '%': //LOGIC ERROR 2. NO % FUNCTIONALITY
        {
            double d = primary();
            if (d==0) error("divide by zero");
            left = int(left) % int(d);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    cout<<"-->";
    double left = term();      // read and evaluate a Term  //ERROR 4. MISSING ")"
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract  //ANOTHER LOGIC ERRROR. += INSTEAD OF -=
            t = ts.get();
            break;
        case 'x':
            return 6969696969669.9; //REALLY SHITTY X FIX. SEE PRIMARY.
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try  //ERROR 5. MISSING DECLARATION OF VAL.
{

    cout<<"Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.\n\tPress x to quit.\n\tPress = at the end of an expression for operation.\n";
    double val = 0;
    while (cin) {
        cout<<"-->";
        Token t = ts.get();

        if (t.kind == 'x') break; // 'q' for quit
        if (t.kind == '=')        // ';' for "print now"
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = expression();
        if (val==6969696969669.9) break;
    }
    //keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    //keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    //keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------