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
    istringstream iss;
    if(is.eof()) return is;
    while(streaming_string[0]=='#' || streaming_string.empty() && !is.eof()) //looks for commented lines and ignores them
        getline(is,streaming_string);
    iss.str(streaming_string);
    while(iss>>ch1 && ch1!=':'){
        curr=curr+ch1;
    }
    if(curr.size()>3 || curr.size()<2) error("wrong currency label on currency()");
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
    Text amount_text;
    Text result_text;
    Menu menu;
    Button menu_button;
    Button equals_button;
    Menu menu_r;
    Button menu_button_r;

    void hide_menu() {menu.hide(); menu_button.show();}
    void menu_pressed() {menu_button.hide(); menu.show();}
    void hide_menu_r() {menu_r.hide(); menu_button_r.show();}
    void menu_pressed_r() {menu_button_r.hide(); menu_r.show();}

    static void cb_equals(Address, Address);
	static void cb_menu(Address, Address);
	static void cb_curr_1(Address, Address);
    static void cb_curr_2(Address, Address);
    static void cb_curr_3(Address, Address);
    static void cb_curr_4(Address, Address);
    static void cb_curr_5(Address, Address);
    static void cb_curr_6(Address, Address);
    static void cb_curr_7(Address, Address);
    static void cb_curr_8(Address, Address);
    static void cb_curr_9(Address, Address);
    static void cb_curr_10(Address, Address);
    static void cb_curr_11(Address, Address);
    static void cb_curr_12(Address, Address);
    static void cb_curr_13(Address, Address);
    static void cb_curr_14(Address, Address);
    static void cb_curr_15(Address, Address);
    static void cb_curr_16(Address, Address);
    static void cb_menu_r(Address, Address);
    static void cb_curr_1_r(Address, Address);
    static void cb_curr_2_r(Address, Address);
    static void cb_curr_3_r(Address, Address);
    static void cb_curr_4_r(Address, Address);
    static void cb_curr_5_r(Address, Address);
    static void cb_curr_6_r(Address, Address);
    static void cb_curr_7_r(Address, Address);
    static void cb_curr_8_r(Address, Address);
    static void cb_curr_9_r(Address, Address);
    static void cb_curr_10_r(Address, Address);
    static void cb_curr_11_r(Address, Address);
    static void cb_curr_12_r(Address, Address);
    static void cb_curr_13_r(Address, Address);
    static void cb_curr_14_r(Address, Address);
    static void cb_curr_15_r(Address, Address);
    static void cb_curr_16_r(Address, Address);

    void equals();
	void curr_1();
    void curr_2();
    void curr_3();
    void curr_4();
    void curr_5();
    void curr_6();
    void curr_7();
    void curr_8();
    void curr_9();
    void curr_10();
    void curr_11();
    void curr_12();
    void curr_13();
    void curr_14();
    void curr_15();
    void curr_16();
    void curr_1_r();
    void curr_2_r();
    void curr_3_r();
    void curr_4_r();
    void curr_5_r();
    void curr_6_r();
    void curr_7_r();
    void curr_8_r();
    void curr_9_r();
    void curr_10_r();
    void curr_11_r();
    void curr_12_r();
    void curr_13_r();
    void curr_14_r();
    void curr_15_r();
    void curr_16_r();

    vector<currency> currencies;
    Vector_ref<Button> buttons; 
    Vector_ref<Button> buttons_r; 

    double you_have;
    double you_get;
};

Currency_window::Currency_window(Point xy, int w, int h, const string& title )
    :My_window(xy,w,h,title),
    amount{Point{100,0},100,20,"Amount:"},
    result{Point{300,0},150,20,"Result:"},
    amount_text{Point{130,35},""},
    result_text{Point{330,35},""},
    menu{Point{100,50},70,20,Menu::vertical,"Currency"},
    menu_button{Point{100,50},70,20,"Currency",cb_menu},
    equals_button{Point{200,200},50,50,"=",cb_equals},
    menu_r{Point{300,50},70,20,Menu::vertical,"Currency"},
    menu_button_r{Point{300,50},70,20,"Currency",cb_menu_r},
    you_have{1},
    you_get{1}
{
    string iname {"currency.txt"};
    ifstream ifs {iname};
    if (!ifs) error("can't open input file ",iname);
    ifs.exceptions(ifs.exceptions()|ios_base::badbit);
    
    while(true){
        currency c;
        if(!(ifs>>c)) break;  
        currencies.push_back(c);
        if(ifs.eof()) break;
    }
    //check that data is correct (currency only 3 letters, conversion ratio correct...)
    //attach options to menu

    attach(amount);
    attach(result);
    attach(amount_text);
    attach(result_text);

    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_1});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_2});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_3});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_4});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_5});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_6});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_7});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_8});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_9});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_10});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_11});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_12});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_13});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_14});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_15});
    buttons.push_back(new Button{{0,0},0,0,"",cb_curr_16});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_1_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_2_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_3_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_4_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_5_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_6_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_7_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_8_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_9_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_10_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_11_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_12_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_13_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_14_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_15_r});
    buttons_r.push_back(new Button{{0,0},0,0,"",cb_curr_16_r});

    
    for(int i = 0; i<buttons.size() && i<currencies.size(); i++)
    {
        buttons[i].label=currencies[i].curr;
        buttons_r[i].label=currencies[i].curr;
        menu.attach(buttons[i]);
        menu_r.attach(buttons_r[i]);
    }
    attach(menu);
    menu.hide();
    attach(menu_button);
    attach(equals_button);
    attach(menu_r);
    menu_r.hide();
    attach(menu_button_r);
}

void Currency_window::equals()
{
    //TO/FROM
    string s {amount.get_string()};
    if(amount_text.label().empty() || result_text.label().empty()) result.put("SELECT CURRENCY");
    else if(s.empty()) result.put("INSERT AMOUNT");
    else result.put(to_string(((you_get*1.0)/(you_have*1.0))*stod(s)));
}
void Currency_window::curr_1()
{
    amount_text.set_label(currencies[0].curr);
    you_have=currencies[0].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_2()
{
    amount_text.set_label(currencies[1].curr);
    you_have=currencies[1].ratio; 
    hide_menu();
    redraw();
}
void Currency_window::curr_3()
{
    amount_text.set_label(currencies[2].curr);
    you_have=currencies[2].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_4()
{
    amount_text.set_label(currencies[3].curr);
    you_have=currencies[3].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_5()
{
    amount_text.set_label(currencies[4].curr);
    you_have=currencies[4].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_6()
{
    amount_text.set_label(currencies[5].curr);
    you_have=currencies[5].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_7()
{
    amount_text.set_label(currencies[6].curr);
    you_have=currencies[6].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_8()
{
    amount_text.set_label(currencies[7].curr);
    you_have=currencies[7].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_9()
{
    amount_text.set_label(currencies[8].curr);
    you_have=currencies[8].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_10()
{
    amount_text.set_label(currencies[9].curr);
    you_have=currencies[9].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_11()
{
    amount_text.set_label(currencies[10].curr);
    you_have=currencies[10].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_12()
{
    amount_text.set_label(currencies[11].curr);
    you_have=currencies[11].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_13()
{
    amount_text.set_label(currencies[12].curr);
    you_have=currencies[12].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_14()
{
    amount_text.set_label(currencies[13].curr);
    you_have=currencies[13].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_15()
{
    amount_text.set_label(currencies[14].curr);
    you_have=currencies[14].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_16()
{
    amount_text.set_label(currencies[15].curr);
    you_have=currencies[15].ratio;
    hide_menu();
    redraw();
}
void Currency_window::curr_1_r()
{
    result_text.set_label(currencies[0].curr);
    you_get=currencies[0].ratio;
    hide_menu_r();
    redraw();
}
void Currency_window::curr_2_r()
{
    result_text.set_label(currencies[1].curr);
    you_get=currencies[1].ratio; 
    hide_menu_r();
    redraw();
}
void Currency_window::curr_3_r()
{
    result_text.set_label(currencies[2].curr);
    you_get=currencies[2].ratio; 
    hide_menu_r();
    redraw();
}
void Currency_window::curr_4_r()
{
    result_text.set_label(currencies[3].curr);
    you_get=currencies[3].ratio; 
    hide_menu_r();
    redraw();
}
void Currency_window::curr_5_r()
{
    result_text.set_label(currencies[4].curr);
    you_get=currencies[4].ratio; //atençao
    hide_menu_r();
    redraw();
}
void Currency_window::curr_6_r()
{
    result_text.set_label(currencies[5].curr);
    you_get=currencies[5].ratio; //atençao
    hide_menu_r();
    redraw();
}
void Currency_window::curr_7_r()
{
    result_text.set_label(currencies[6].curr);
    you_get=currencies[6].ratio; //atençao
    hide_menu_r();
    redraw();
}
void Currency_window::curr_8_r()
{
    result_text.set_label(currencies[7].curr);
    you_get=currencies[7].ratio; //atençao
    hide_menu_r();
    redraw();
}
void Currency_window::curr_9_r()
{
    result_text.set_label(currencies[8].curr);
    you_get=currencies[8].ratio; //atençao
    hide_menu_r();
    redraw();
}
void Currency_window::curr_10_r()
{
    result_text.set_label(currencies[9].curr);
    you_get=currencies[9].ratio; //atençao
    hide_menu_r();
    redraw();
}
void Currency_window::curr_11_r()
{
    result_text.set_label(currencies[10].curr);
    you_get=currencies[10].ratio; //atençao
    hide_menu_r();
    redraw();
}
void Currency_window::curr_12_r()
{
    result_text.set_label(currencies[11].curr);
    you_get=currencies[11].ratio; //atençao
    hide_menu_r();
    redraw();
}
void Currency_window::curr_13_r()
{
    result_text.set_label(currencies[12].curr);
    you_get=currencies[12].ratio; //atençao
    hide_menu_r();
    redraw();
}
void Currency_window::curr_14_r()
{
    result_text.set_label(currencies[13].curr);
    you_get=currencies[13].ratio; //atençao
    hide_menu_r();
    redraw();
}
void Currency_window::curr_15_r()
{
    result_text.set_label(currencies[14].curr);
    you_get=currencies[14].ratio; //atençao
    hide_menu_r();
    redraw();
}
void Currency_window::curr_16_r()
{
    result_text.set_label(currencies[15].curr);
    you_get=currencies[15].ratio; //atençao
    hide_menu_r();
    redraw();
}

void Currency_window::cb_equals(Address, Address pw)
{
    reference_to<Currency_window>(pw).equals();
}
void Currency_window::cb_menu(Address, Address pw)
{
    reference_to<Currency_window>(pw).menu_pressed();
}
void Currency_window::cb_curr_1(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_1();    
}
void Currency_window::cb_curr_2(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_2();    
}
void Currency_window::cb_curr_3(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_3();    
}
void Currency_window::cb_curr_4(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_4();    
}
void Currency_window::cb_curr_5(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_5();    
}
void Currency_window::cb_curr_6(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_6();    
}
void Currency_window::cb_curr_7(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_7();    
}
void Currency_window::cb_curr_8(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_8();    
}
void Currency_window::cb_curr_9(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_9();    
}
void Currency_window::cb_curr_10(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_10();    
}
void Currency_window::cb_curr_11(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_11();    
}
void Currency_window::cb_curr_12(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_12();    
}
void Currency_window::cb_curr_13(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_13();    
}
void Currency_window::cb_curr_14(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_14();    
}
void Currency_window::cb_curr_15(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_15();    
}
void Currency_window::cb_curr_16(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_16();    
}
void Currency_window::cb_menu_r(Address, Address pw)
{
    reference_to<Currency_window>(pw).menu_pressed_r();
}
void Currency_window::cb_curr_1_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_1_r();    
}
void Currency_window::cb_curr_2_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_2_r();    
}
void Currency_window::cb_curr_3_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_3_r();    
}
void Currency_window::cb_curr_4_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_4_r();    
}
void Currency_window::cb_curr_5_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_5_r();    
}
void Currency_window::cb_curr_6_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_6_r();    
}
void Currency_window::cb_curr_7_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_7_r();    
}
void Currency_window::cb_curr_8_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_8_r();    
}
void Currency_window::cb_curr_9_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_9_r();    
}
void Currency_window::cb_curr_10_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_10_r();    
}
void Currency_window::cb_curr_11_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_11_r();    
}
void Currency_window::cb_curr_12_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_12_r();    
}
void Currency_window::cb_curr_13_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_13_r();    
}
void Currency_window::cb_curr_14_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_14_r();    
}
void Currency_window::cb_curr_15_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_15_r();    
}
void Currency_window::cb_curr_16_r(Address, Address pw)
{  
    reference_to<Currency_window>(pw).curr_16_r();    
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
