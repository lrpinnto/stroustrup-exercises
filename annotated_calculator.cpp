//Working version of calculator from Chapter 6 of stroustrup
//Contains way too many print statements so you can track what is going on.
//Each grammatical rule, and main, is annotated with attempt to explain what is happening.
//Note I prefer to use '#' instead of '8' to represent numbers because I'm not a monster (see: Stroop effect).

#include "/home/pinto/stroustrup/std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {  
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


// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer; how does this take in 0?
{}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer
void Token_stream::putback(Token t)
{
    if (full)
      error("Attempted to putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()  
{
    if (full)
    {   //Is there a token already in the stream?
        full=false;
        return buffer; //note: buffer is just the previous Token instance
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':  
    case '9':
        {
            cin.putback(ch);    // put digit back into the input stream to recast as double
            double val;
            cin >> val;              // read a floating-point number
            return Token('#',val);   // let '8' represent "a number"
        }
    default:
        error("TOKEN STREAM ERROR: Bad token");
        return Token('z'); //dummy return just to avoid reaching end w/o return
  }  //switch
} //token_stream::get()

//------------------------------------------------------------------------------
//Global because all the parsers use it
Token_stream ts;        // provides get() and putback()

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
//Logic of primary (this is always a number or an expression in parens)
//1. Get token from stream. Primary will either start with # or (.
//2. If it is a paren
//    a Get the doulbe value of the expression inside
//    b Return value of expression (after checking for closing paren)
//3. If it is a number, return its value
//4. If it is not a number or paren, throw an error.
double primary()
{
    cout << "      primary() get()\n";
    Token t = ts.get();
    switch (t.kind)
    {
      case '(':    // handle '(' expression ')'
          {
              double d = expression();
              t = ts.get();
              if (t.kind != ')')
                error("PRIMARY: ')' expected after expression to end parens.");
              return d;
          }
      case '#':            
          cout << "      primary() returning value " << t.value << "\n";
          return t.value;  // return the number's value
      default: //not a number or paren, so throw error
          cout << "Primary error kind/value: "
               << t.kind << " | " << t.value << "\n";
          error("PRIMARY ERROR: no primary provided.");
          return -9.9;
    } //switch
}

//------------------------------------------------------------------------------

// deal with *, /:  return the product/quotient
//In what follows, ? denotes * or / .
//Logic of term ()
//1 Leftmost entity is a primary, which you pull using primary().
//2 Get the next token t, which will be a ? or something else.
//3 If t is a ?, then it is ? followed by a primary (that is how ? works).
//  a Carry out the operation on left [left ?= primary()]  yielding a double
//  b Go to step 2 (i.e., get next token and see what's up)
//4 If t is not a ?, then you have nothing to do here. Put that token back in the stream so the next
//    function can see what it is, and return the value of the number you have calculated.
double term()
{
    cout << "    term() calling primary()\n";
    double left = primary();  //left-hand side of ? is always a double
    cout << "    term() calling get()\n";
    Token t = ts.get();      // get the next token from token stream

    //If next token is a * or //, then carry out that operation. Otherwise, return the double
    //and put that token back in the token stream
    while(true)
    {
        switch (t.kind)
        {
          case '*':
              cout << "    term() *case primary()\n";
              left *= primary();
              cout << "    term() *case get()\n";
              t = ts.get();
              break;  //FIXESD this was not here so multiplication was not working
          case '/':
              {
                  cout << "    term() /case primary()\n";
                  double d = primary();
                  if (d == 0) error("divide by zero");
                  left /= d;
                  cout << "    term() /case get()\n";
                  t = ts.get();
                  break;
              }
          default:
              cout << "    In term(): no */ so putting current token back in token stream: "
                << t.kind << " | " <<  t.value << "\n";
              ts.putback(t);     // put t back into the token stream
              return left;
        } //switch
    } //while
}

//------------------------------------------------------------------------------

//Expression logic:
//1 Get the leftmost numerical value (it will be a term)
//2 Get the next token t. It will be a ?, or won't be (? here stands for + or -)
//3 If it is a ?, it will be followed by a term (that is how ? works)
//  a. Carry out operation ? between left and term (e.g., left += term())
//  b. Go to step 2.
//4 If it is not a ?, then put that token back in the stream for someone else to use, and
//  return the left double value you have calculated so far.
double expression()
{
    cout << "  expression() term()\n";
    double left = term();      // Get value of first entity
    cout << "  expression() get()\n";
    Token t = ts.get();        // get the next token from token stream

    while(true)
    {
        switch(t.kind)
        {
          case '+':
              cout << "  expression() +case term()\n";
              left += term();    // evaluate Term and add
              cout << "  expression() +case get()\n";
              t = ts.get();
              cout << "  expression() got " << t.kind << " | " << t.value << "\n";
              break;
          case '-':
              left -= term();   
              t = ts.get();
              break;
          default:
              cout << "  expression() putback()  "  << t.kind << " | " <<  t.value << "\n";
              ts.putback(t);   // put t back into the token stream
              cout << "  expression() returning " << left << "\n";
              return left;     // no more + or -: return the answer
        }  //switch
    }  //while
}


//The logic of main
//Get the first token
//If it is an x, then exit.
//If it is an '=', then print the value of the expression.
//  (if no expression has been entered then all bets are off)
//Otherwise, put back token, and run expression() to get the value.
//  Expression is the top-level grammatical category, and returns a double. See expression().
int main()
try
{
    cout << "Welcome to Calculator\n"
         << "Enter expressions followed by equals sign.\n"
         << "Enter an 'x' to exit.\n\n";

    double val = 0;
    while (cin)
    {
        cout << "main(): calling get()\n";
        Token t = ts.get();
        //quit case
        if (t.kind == 'x')
          break;

        //if user is done entering data, print value
        //If they dont' want to quit or print, put the token back
        //into the stream and get the expression
        if (t.kind == '=')
        {
            cout << "Result: " << val << '\n';
            cout << "Reset value.\n";
            val = 0;
        }
        else
        {
          cout << "main(): putback() "
                << t.kind << " | " <<  t.value << "\n";
          ts.putback(t);
          cout << "no x or = in main(), so call expression()\n";
          val = expression();
        }

        cout << "main() reached end of while. Let's start again....\n\n";
    } //while

  cout << "You are finished with Calculator. Thank you.\n";
	return 0;
} //main

catch (exception& e) {
    cerr << "MAIN: Exception caught. e.what == " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}
