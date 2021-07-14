#include "../stroustrup/std_lib_facilities.h"

//Using calculator from Chapter 8 Ex 01
//Chapter 10 ex 07

//-----ROMAN
const vector<string> roman_nums  {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
const vector<int> int_nums  {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

class Roman_int
{
private:
    int value;
    string roman;
public:
    int as_int() const {return value;}
    string as_string() const {return roman;}
	Roman_int squarert() const { if( sqrt(value) != floor(sqrt(value)) ) error("Roman numerals can only be natural numbers.");
		return sqrt(value);}
    Roman_int(string roman);
    Roman_int(int value);
	Roman_int(){value=0; roman="";}; //default construct hack that I needed to do due to undefined reference linker error
};

string int_to_roman(int n)
{
    string result;

    for (int i = 0; i < 13; ++i)
    {
        while(n - int_nums[i] >= 0)
        {
            result += roman_nums[i];
            n -= int_nums[i];
        }
    }
    return result;
}

int roman_to_int(string r)
{
    int n = int(r.length());
    if (0 == n) {
        return 0;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        switch (r[i]) {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default:
                error("String not a roman numeral.");
                break;
        }
    }

    for (int i = 1; i < n; i++) {
        if ((r[i] == 'V' || r[i] == 'X') && r[i - 1] == 'I') {
            result -= 1 + 1;
        }

        if ((r[i] == 'L' || r[i] == 'C') && r[i - 1] == 'X') {
            result -= 10 + 10;
        }

        if ((r[i] == 'D' || r[i] == 'M') && r[i - 1] == 'C') {
            result -= 100 + 100;
        }
    }
    return result;
}

Roman_int::Roman_int(string romann)
    :roman{romann}
{
    value = roman_to_int(romann);
    if(value==0) error("String not a roman numeral.");
}

Roman_int::Roman_int(int valuee)
    :value{valuee}
{
    roman=int_to_roman(valuee);
}

Roman_int Roman_power(const Roman_int& a, const Roman_int& b)
{
	return Roman_int{int(pow(a.as_int(),b.as_int()))};
}

ostream& operator<<(ostream& os, const Roman_int& r)
{
    return os << r.as_string();
}

istream& operator>>(istream& is, Roman_int& r)
{
	string s;
    char ch;
	bool dont_break_cycle {false};
    while(is>>ch)
	{
		dont_break_cycle=false;
		for(string ss : roman_nums) if(ch==ss[0]) {s+=ch; dont_break_cycle=true; break;}
		if(dont_break_cycle) continue;
		else {is.unget(); break;}
	}
    if(!is) return is;
    //if(isdigit(s)) { int h {stoi(s)}; int s {h}; };  attempt at auto converting int to roman
    r = Roman_int {s};
    return is;
}

Roman_int operator+(const Roman_int& a, const Roman_int& b)
{
    return Roman_int{a.as_int()+b.as_int()};
}
Roman_int operator-(const Roman_int& a, const Roman_int& b)
{
	int resul {a.as_int()-b.as_int()};
	if(resul<1) error("Roman numerals can only be natural numbers.");
    return Roman_int{resul};
}

Roman_int operator*(const Roman_int& a, const Roman_int& b)
{
    return Roman_int{a.as_int()*b.as_int()};
}

Roman_int operator/(const Roman_int& a, const Roman_int& b)
{
    int resul {a.as_int()/b.as_int()};
	if(resul<1) error("Roman numerals can only be natural numbers.");
	return Roman_int{resul};
}

bool operator==(const Roman_int& a, const Roman_int& b)  
{
    return (a.as_int()==b.as_int());
}

bool operator!=(const Roman_int& a, const Roman_int& b)  
{
    return !(a==b);
}

bool operator>(const Roman_int& a, const int& b)  
{
    return (a.as_int()>b);
}

bool operator<(const Roman_int& a, const int& b)  
{
    return (a.as_int()<b);
}

//-----ROMAN


struct Token {  //Defines Data structure Token composed of char kind, double value and string name. Token Can be defined by Token(char), Token(char,double) or Token(char, string)
	char kind;
	Roman_int value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, Roman_int val) :kind(ch), value(val) { }
    Token(char ch, string n) :kind(ch), name(n) { }   //Error 1: Missing Token definition for line 73.
};

class Token_stream {   //If the class is declared using the keyword class then its members are private by default
	bool full;
	Token buffer;
    istream& is;
public:
	Token_stream(istream& ii) :full(0), buffer(0), is(ii) { }   //?????????????????????

	Token get();                //Declares get() so it can be defined below
	void unget(Token t) { buffer = t; full = true; }  //Declares unget() and defines it inside public???????

	void ignore(char, char);     //Declares ignore() so it can be defined below
};

const char let = '#';                 //avoids the use of "Magic constants"
const char quit = 'Q';                //avoids the use of "Magic constants"
const char print = ';';               //avoids the use of "Magic constants"
const char number = '8';              //avoids the use of "Magic constants"
const char name = 'a';                //avoids the use of "Magic constants"
const char square_root = '|';         //avoids the use of "Magic constants"
const char power = '^';               //avoids the use of "Magic constants"
const char help = 'h';                //avoids the use of "Magic constants"


Token Token_stream::get()
{
	if (full) { full = false; return buffer; }  //if unget() has been run beforehand, get() returns the buffer. That is, the "token" placed back by unget()
	while(true)   //Needed to avoid space characters reaching end of non-void function without return (due to cin.get()). Will only repeat the loop if it's a space character which falls into a break instead of a return. Essentially ignores space characters besides '\n'
	{
		char ch;
		cin.get(ch);   //cin.get() does not skip whitespace
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
		case 'I':
		case 'V':
		case 'X':
		case 'L':
		case 'C':
		case 'D':
		case 'M':
		{	cin.unget();   //Places the number back into the stream and attempts to get the same number but as a double?
		Roman_int val;
		cin >> val;
		return Token(number, val);
		}
		default:
			if (isalpha(ch)) {   // if ch is alphanumeric
				string s;
				s += ch;  //It's probably a word. Attempt to create the word by adding the chars together
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s += ch;  //ERROR 2: Need to add char to string and not string = char
																				//attempts to extract the leftover characters while these are alfanumeric or digits and there still characters in the stream. At which point cin.get(ch) will fail and throw false
				cin.unget();  //returns last char to the stream. Could that be because it reads ";"????
				if (s == "let") return Token(let);
				if (s == "quit") return Token(quit);     //ERROR 3: was returning const char name instead of const char quit.
				if (s == "pow") return Token(power);
				if (s == "help") return Token(help); 
				return Token(name, s);    //returns the name to be assigned as a variable in the calculator
			}
			if (isspace(ch)) {  //checks for "whitespace"
				if (ch == '\n') return Token(print);
				break;
			}
			error("Bad token");
		}
	}
}

void Token_stream::ignore(char c, char c2)
{
	if (full && c == buffer.kind) {    //????
		full = false;
		return;
	}
	full = false;   //sets buffer to empty?

	cin.putback('@');            //adds @ as a "placeholder" to the end of the stream
	char left_over_chars[]={0};  //vector of chars

	if (cin.peek()=='@') {cin.get(); return;}   //if the expression is true, it means that the stream is empty. There is nothing else to read so me read the placeholder char and return
	/*else 
	{
		while(cin.peek())
		cin.read(left_over_chars, 99);
	}*/
	else
	{
		string s;
		char ch;
		while (cin.get(ch))   //reads cin until it finds '@' and deletes it
		{
			if(ch=='@') 
			{
				for (char c: s)
				{
					cin.putback(c);
				} 
				break;
			}
			else s += ch;
		}
		while (cin >> ch)
			if (ch == c || ch == c2) return;     //"burns" chars from stream until it finds the character c
	}
}

struct Variable {  //Data structure for variable declaration in the calculator
	string name;
	Roman_int value;
	bool constant;
	Variable(string n, Roman_int v, bool h) :name(n), value(v), constant(h) { }
};

class Symbol_table
{
private:
	vector<Variable>var_table;  //old vector<Variable> var_table
public:
	double get_value(string s);
	void set_value(string s, Roman_int d);
	bool is_declared(string s);
	void define_var();
	void declare_var(string s, Roman_int d, bool is_const);
};

void Symbol_table::declare_var(string s, Roman_int d, bool is_const)  //declares var. All other checks (is_declared, etc) are done on declaration()
{
	var_table.push_back(Variable(s, d, is_const));
}

double Symbol_table::get_value(string s)   //gets value from calculator variable
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value.as_int();
	error("get: undefined name ", s);   //Value not yet defined (in the calculator)
}

void Symbol_table::set_value(string s, Roman_int d)    //Assigns value to variable in the calculator
{
	for (int i = 0; i <= var_table.size(); ++i)     //goes through the vector checking for the matching name that has been pushed back beforehand
		if (var_table[i].name == s && var_table[i].constant == false) {
			var_table[i].value = d; //sets the token to the value
			return;
		}
		else if (var_table[i].name == s && var_table[i].constant == true) error("set: constant variable ");
	error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s)   //check if name is already declared
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return true;
	return false;
}

void Symbol_table::define_var()  //list of variables to be defined at the start of the program
{
	var_table.push_back(Variable("pi", 3.14159, true));
	var_table.push_back(Variable("e", 2.718281828, true));
	var_table.push_back(Variable("k", 1000, true));
}

Symbol_table sym; //Declares var as "global" (I believe) so I don't need to declare a variable as Symbol_table everything I want to run the functions

Roman_int expression(Token_stream&);      //??

Roman_int powrr(Token_stream&);

Roman_int primary(Token_stream& ts)
{
	Token t = ts.get();
	Token t2 = Token('?');     //trying to avoid error: "crosses initialization of ‘Token t2’" by declaring the token outside of the switch with a default random token
	switch (t.kind) {
	case '(':
	{	Roman_int d = expression(ts);
	t = ts.get();
	if (t.kind != ')') error("')' expected");  //ERROR 6: ')' expected
	return d;    //ERROR 7: missing a return
	}
	case '-':
		error("Roman numerals can only be natural numbers.");
		//return -primary(ts);
	case number:
		return t.value;
	case name:
		t2 = ts.get();
		if (t2.kind == '=') {
			Roman_int h = expression(ts);
			sym.set_value(t.name, h);
			return h;
		} 
		else {
			ts.unget(t2);
			return sym.get_value(t.name);
		}
	case square_root:
		{
			Roman_int d = primary(ts);
			if (d < 0) error("Can't sqrt() Imaginary #");
			return d.squarert();
		}
	case power:
		{
			return powrr(ts);
		}

	default:
		error("primary expected");
	}
}

Roman_int term(Token_stream& ts)
{
	Roman_int left = primary(ts);
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left = left * primary(ts);
			break;
		case '/':
		{	Roman_int d = primary(ts);
		if (d == 0) error("divide by zero");
		left = left / d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

Roman_int expression(Token_stream& ts)
{
	Roman_int left = term(ts);
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left = left + term(ts);
			break;
		case '-':
			left = left - term(ts);
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

Roman_int declaration(Token_stream& ts)
{
	bool is_const = false;
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");  //ERROR 4: Magic constant
	if (t.name == "const") 
	{
		is_const = true;
		t=ts.get();
	}
	string name = t.name;
	if (sym.is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);  //ERROR 5: Magic constant
	Roman_int d = expression(ts);
	sym.declare_var(name, d, is_const);
	return d;
}

Roman_int powrr(Token_stream& ts)
{
	Token t = ts.get();
	if (t.kind != '(') error("'(' expected in pow");  
	Roman_int d = primary(ts);
	Token t2 = ts.get();
	if (t2.kind != ',') error("',' expected in pow");
	Roman_int d2 = primary(ts);
	Token t3 = ts.get();
	if (t3.kind != ')') error("')' expected in pow");
	return Roman_power(d,d2);
}

Roman_int statement(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(ts);
	default:
		ts.unget(t);
		return expression(ts);
	}
}

void clean_up_mess(Token_stream& ts)
{
	ts.ignore(print, '\n');
}

void help_text()
{
	cout<<"Simple Calculator\n\n"
		<<"\tThis Calculator has been modified to use Roman numerals on all usual operations + - / *.\n"
		<<"\tIt also supports parentheses () and other more complex operations like power: pow(x) and square root |x or |(x).\n"
		<<"\tIt does not support non-natural numbers like 0, -1, 1.5,... And only supports roman numerals like I,II,XI,...\n"
		<<"\tWrite any expression after the '>' char. To finish your input either press enter or type ; at the end of the expression or expressions.\n"
		<<"\tThis program also supports variable assignment and declaration. To declare a variable simlpy type \"let const var = x\".\n"
		<<"\tWhere \"var\" is the alphanumeric variable and x the expression. To assign another value to the var simply type \"var=y\". Where y is the new value.\n"
		<<"\t\"const\" is an optional statement and simply sets the variable as unassignable.\n"
		<<"\n\tTo quit, type quit.\n\n";
}

void intro_text()
{
	cout<<"Welcome to the Simple Calculator - Roman Numerals Edition!\nFor help simply type \"help\" followed by enter.\n"
		<<"Remember to user Roman Numerals XVI(...) instead of Arabic ones 123(...)!"
		<<"\n\n";
}

const string prompt = "> ";
const string result = "= ";

void calculate(Token_stream& ts)
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		if (t.kind == help) {help_text(); continue;}
		ts.unget(t);
		cout << result << statement(ts) << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess(ts);
	}
}

int main()

try {
    Token_stream ts (cin);
	sym.define_var();
	intro_text();
	calculate(ts);
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
