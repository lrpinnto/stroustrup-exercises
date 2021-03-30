#include "../stroustrup/std_lib_facilities.h"

//CAP 7 DRILL

/* TESTING DATA
 *
 * ran inputs below input from file testing_C7DRILL.txt using --->   "CHAPTER 7/"C7DRILL < "CHAPTER 7/"testing_C7DRILL.txt
 * 
 *
 * 1+2;
 * 5-4; 3+2; 6-10;
 * 1 / (3 + 8) * 10;
 * let x = 5;
 * let x2 = 16 / 4;
 * x * x2 * pi;
 *
 * 1**2;
 * 2+8
 * let f@tnum = 10;
 * x / y;
 * xx - 500;
 */


struct Token {  //Defines Data structure Token composed of char kind, double value and string name. Token Can be defined by Token(char), Token(char,double) or Token(char, string)
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string n) :kind(ch), name(n) { }   //Error 1: Missing Token definition for line 73.
};

class Token_stream {   //If the class is declared using the keyword class then its members are private by default
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }   //?????????????????????

	Token get();                //Declares get() so it can be defined below
	void unget(Token t) { buffer = t; full = true; }  //Declares unget() and defines it inside public???????

	void ignore(char);     //Declares ignore() so it can be defined below
};

const char let = '#';                 //avoids the use of "Magic constants"
const char quit = 'Q';                //avoids the use of "Magic constants"
const char print = ';';               //avoids the use of "Magic constants"
const char number = '8';              //avoids the use of "Magic constants"
const char name = 'a';                //avoids the use of "Magic constants"
const char square_root = '|';         //avoids the use of "Magic constants"
const char power = '^';               //avoids the use of "Magic constants"


Token Token_stream::get()
{
	if (full) { full = false; return buffer; }  //if unget() has been run beforehand, get() returns the buffer. That is, the "token" placed back by unget()
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':                //ERROR 8: code missing for modulo case
	case ';':
	case '=':
	case ',':
	case square_root:
		return Token(ch);
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
	{	cin.unget();   //Places the number back into the stream and attempts to get the same number but as a double?
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {   // if ch is alphanumeric
			string s;
			s += ch;  //It's probably a word. Attempt to create the word by adding the chars together
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;  //ERROR 2: Need to add char to string and not string = char
                                                                            //attempts to extract the leftover characters while these are alfanumeric or digits and there still characters in the stream. At which point cin.get(ch) will fail and throw false
			cin.unget();  //returns last char to the stream. Could that be because it reads ";"????
			if (s == "let") return Token(let);
			if (s == "exit") return Token(quit);     //ERROR 3: was returning const char name instead of const char quit.
			if (s == "pow") return Token(power);
			return Token(name, s);    //returns the name to be assigned as a variable in the calculator
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {    //????
		full = false;
		return;
	}
	full = false;   //sets buffer to empty?

	char ch;
	while (cin >> ch)
		if (ch == c) return;     //"burns" chars from stream until it finds the character c
}

struct Variable {  //Data structure for variable declaration in the calculator
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;  //Vector to store variables from calculator

double get_value(string s)   //gets value from calculator variable
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);   //Value not yet defined (in the calculator)
}

void set_value(string s, double d)    //Assigns value to variable in the calculator
{
	for (int i = 0; i <= names.size(); ++i)     //goes through the vector checking for the matching name that has been pushed back beforehand
		if (names[i].name == s) {
			names[i].value = d; //sets the token to the value
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)   //check if name is already declared
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

void define_var()  //list of variables to be defined at the start of the program
{
	names.push_back(Variable("pi", 3.14159));
	names.push_back(Variable("e", 2.718281828));
	names.push_back(Variable("k", 1000));
}

Token_stream ts;   

double expression();      //??

double powrr();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("')' expected");  //ERROR 6: ')' expected
	return d;    //ERROR 7: missing a return
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case square_root:
		{
			double d = primary();
			if (d < 0) error("Can't sqrt() Imaginary #");
			return sqrt(d);
		}
	case power:
		{
			return powrr();
		}

	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");  //ERROR 4: Magic constant
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);  //ERROR 5: Magic constant
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double powrr()
{
	Token t = ts.get();
	if (t.kind != '(') error("'(' expected in pow");  
	double d = primary();
	Token t2 = ts.get();
	if (t2.kind != ',') error("',' expected in pow");
	double d2 = primary();
	Token t3 = ts.get();
	if (t3.kind != ')') error("')' expected in pow");
	return pow(d,d2);
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	define_var();
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
