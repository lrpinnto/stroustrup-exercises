#include "../stroustrup/std_lib_facilities.h"

//Using calculator from Chapter 8 Ex 01
//Chapter 10 EX 10
//Still need to do test cases

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
const char from = 'f';
const char to = 'T';
const char file = 'F';

void reset_stream();

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }  //if unget() has been run beforehand, get() returns the buffer. That is, the "token" placed back by unget()
	while(true)   //Needed to avoid space characters reaching end of non-void function without return (due to cin.get()). Will only repeat the loop if it's a space character which falls into a break instead of a return. Essentially ignores space characters besides '\n'
	{
		char ch;
		is.get(ch);   //cin.get() does not skip whitespace
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
		{	is.unget();   //Places the number back into the stream and attempts to get the same number but as a double?
		double val;
		is >> val;
		return Token(number, val);
		}
		default:
			if (isalpha(ch)) {   // if ch is alphanumeric
				string s;
				s += ch;  //It's probably a word. Attempt to create the word by adding the chars together
				while (is.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s += ch;  //ERROR 2: Need to add char to string and not string = char
																				//attempts to extract the leftover characters while these are alfanumeric or digits and there still characters in the stream. At which point cin.get(ch) will fail and throw false
				is.unget();  //returns last char to the stream. Could that be because it reads ";"????
				if (s == "let") return Token(let);
				if (s == "quit") return Token(quit);     //ERROR 3: was returning const char name instead of const char quit.
				if (s == "pow") return Token(power);
				if (s == "help") return Token(help); 
                if (s == "from") return Token(from);
				if (s == "to") return Token(to);
				return Token(name, s);    //returns the name to be assigned as a variable in the calculator
			}
            if (ch=='"')
            {
                string s;
				s += ch;  //It's probably a word. Attempt to create the word by adding the chars together
				while (is.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_' || ch==' ' || ch=='/' || ch=='-' || ch=='.')) s += ch;  //ERROR 2: Need to add char to string and not string = char
                is.unget();
                if (ch == '"') 
                {
                    s.erase(s.begin(),s.begin()+1); //deletes first "
                    //No need to delete last " as this is dropped on the while loop
                    return Token(file, s); //check if last char is the end of the file path input
                }
            }
			if (isspace(ch)) {  //checks for "whitespace"
				if (ch == '\n') return Token(print);
				break;
			}
			if(is.eof()) reset_stream();  //keeps ifstream from getting stuck on bad token loop. resets to cin stream
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
	double value;
	bool constant;
	Variable(string n, double v, bool h) :name(n), value(v), constant(h) { }
};

class Symbol_table
{
private:
	vector<Variable>var_table;  //old vector<Variable> var_table
public:
	double get_value(string s);
	void set_value(string s, double d);
	bool is_declared(string s);
	void define_var();
	void declare_var(string s, double d, bool is_const);
};

void Symbol_table::declare_var(string s, double d, bool is_const)  //declares var. All other checks (is_declared, etc) are done on declaration()
{
	var_table.push_back(Variable(s, d, is_const));
}

double Symbol_table::get_value(string s)   //gets value from calculator variable
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined name ", s);   //Value not yet defined (in the calculator)
}

void Symbol_table::set_value(string s, double d)    //Assigns value to variable in the calculator
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

double expression(Token_stream&);      //??

double powrr(Token_stream&);

double primary(Token_stream& ts)
{
	Token t = ts.get();
	Token t2 = Token('?');     //trying to avoid error: "crosses initialization of ‘Token t2’" by declaring the token outside of the switch with a default random token
	switch (t.kind) {
	case '(':
	{	double d = expression(ts);
	t = ts.get();
	if (t.kind != ')') error("')' expected");  //ERROR 6: ')' expected
	return d;    //ERROR 7: missing a return
	}
	case '-':
		return -primary(ts);
	case number:
		return t.value;
	case name:
		t2 = ts.get();
		if (t2.kind == '=') {
			double h = expression(ts);
			sym.set_value(t.name, h);
			return h;
		} 
		else {
			ts.unget(t2);
			return sym.get_value(t.name);
		}
	case square_root:
		{
			double d = primary(ts);
			if (d < 0) error("Can't sqrt() Imaginary #");
			return sqrt(d);
		}
	case power:
		{
			return powrr(ts);
		}

	default:
		error("primary expected");
	}
}

double term(Token_stream& ts)
{
	double left = primary(ts);
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary(ts);
			break;
		case '/':
		{	double d = primary(ts);
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

double expression(Token_stream& ts)
{
	double left = term(ts);
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term(ts);
			break;
		case '-':
			left -= term(ts);
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration(Token_stream& ts)
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
	double d = expression(ts);
	sym.declare_var(name, d, is_const);
	return d;
}

double powrr(Token_stream& ts)
{
	Token t = ts.get();
	if (t.kind != '(') error("'(' expected in pow");  
	double d = primary(ts);
	Token t2 = ts.get();
	if (t2.kind != ',') error("',' expected in pow");
	double d2 = primary(ts);
	Token t3 = ts.get();
	if (t3.kind != ')') error("')' expected in pow");
	return pow(d,d2);
}

double statement(Token_stream& ts)
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

void calculate(Token_stream&);

void reset_stream()
{
	Token_stream ts {cin};
	clean_up_mess(ts);
	calculate(ts);
}

void help_text()
{
	cout<<"Simple Calculator\n\n"
		<<"\tThis Calculator can do all standard calculator operations using the common operands + - / *.\n"
		<<"\tIt also supports parentheses () and other more complex operations like power: pow(x) and square root |x or |(x).\n"
		<<"\tWrite any expression after the '>' char. To finish your input either press enter or type ; at the end of the expression or expressions.\n"
		<<"\tThis program also supports variable assignment and declaration. To declare a variable simlpy type \"let const var = x\".\n"
		<<"\tWhere \"var\" is the alphanumeric variable and x the expression. To assign another value to the var simply type \"var=y\". Where y is the new value.\n"
		<<"\t\"const\" is an optional statement and simply sets the variable as unassignable.\n"
		<<"\tTo use file I/O, type: from \"pathtofile\" for input and: to \"pathtofile\" for output.\n"
		<<"\n\tTo quit, type quit.\n\n";
}

void intro_text()
{
	cout<<"Welcome to the Simple Calculator!\nFor help simply type \"help\" followed by enter.\n\n";
}

const string prompt = "> ";
const string result = "= ";


bool to_y_var {false}; //global scope so it can be used by several functions (needs alternative)
string outputfile;  //global scope so it can be used by several functions  (need alternative)
void to_y(Token_stream& ts)  //BUG: Returns primary expected after initialization
{
	Token t = ts.get();
	if(t.kind==file && outputfile.empty()) {outputfile=t.name;ts.get(); }  //gets extra character thats either ; or \n. Only defines outputfile if empty
	else ts.unget(t);   //its not a filepath so we place token back into stream
	ofstream ofs;
	ostringstream oss;
	oss << result << statement(ts) << endl;
	cout << oss.str();
	ofs.open(outputfile,ios_base::app);
	if (!ofs) error("can't open output file ",outputfile);
	ofs << oss.str();
	ofs.close();
}

void from_x(Token_stream& ts)
{
    Token t = ts.get();
	cin.clear(); //flushes cin state and cin buffer
    cin.ignore();
	ifstream ifs {t.name};
    if (!ifs) error("can't open input file ",t.name);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);
	Token_stream tfs (ifs);
	calculate(tfs);
}

void calculate(Token_stream& ts)
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
        if (t.kind == to) {to_y_var=true; continue;} //sets flag to output all output to a file
        if (t.kind == from) {from_x(ts); continue;} //reads from file until the end
		if (t.kind == help) {help_text(); continue;}
		ts.unget(t);
        if(to_y_var) to_y(ts);
		else cout << result << statement(ts) << endl;
	}
	catch (runtime_error& e) {
		if(to_y_var)
		{
			ofstream ofs;
			ostringstream oss;
			oss << e.what() << endl;
			cerr << oss.str();
			ofs.open(outputfile,ios_base::app);
			if (!ofs) error("can't open output file ",outputfile);
			ofs << oss.str();
			ofs.close();
		}
		else cerr << e.what() << endl;
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