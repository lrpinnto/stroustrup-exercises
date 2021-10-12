//CHAPTER 16 EX 08

#include "./sources.h" 

struct currency
{
    string curr;
    double ratio;
};

istream& operator>>(istream& is, currency& r)
{
    string curr;
    char ch1;
    double ratio;
    string streaming_string;
    is.getline(streaming_string);
    istringstream iss;
    iss.str(streaming_string);
    while(iss>>ch1 && ch1!=':'){
        curr=curr+ch1;
    }
    if(curr.size()>3 || currr.size()<2) error("wrong currency label on currency()");
    iss>>ratio;
    r.curr=curr;
    r.ratio=ratio;
    return is;
}

struct Currency_window : My_window {
	Currency_window(Point xy, int w, int h, const string& title ); 
private:
    In_box amount;
    Out_box result;
    Menu menu;
    Button menu_button;
	
	static void cb_click(Address, Address);
	void click();

    vector<currency> currencies;
    vector<Callback> call_backs; //just a test
};

Currency_window::Currency_window(Point xy, int w, int h, const string& title )
    :My_window(xy,w,h,title),
    amount{Point{70,0},50,20,"Amount:"},
    result{Point{70,0},100,20,"Result:"},
    menu{Point{0,0},70,20,Menu::vertical,"Currency"},
    menu_button{Point{0,0},70,20,"Currency",cb_menu}
{
    string iname {"currency.txt"};
    ifstream ifs {iname};
    if (!ifs) error("can't open input file",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);
    
    while(true){
        currency c;
        if(!(ifs>>c)) break;  
        currencies.push_back(c);
    }
    //check that data is correct (currency only 3 letters, conversion ratio correct...)
    //attach options to menu

    for(currency cu : currencies)
    {
        menu.attach(new Button{0,0},0,0,cu.curr,cb_circle})
        //need to figure out how to dynamically generate callbacks
    }
}

int main()
try
{
    Currency_window win {Point{100,100},600,400,"EX 08"};
    win.wait_for_button();
}
catch(exception& e)
{
    std::cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr<<"Some exception\n";
    return 2;
}
