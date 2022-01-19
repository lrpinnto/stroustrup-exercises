//CHAPTER 18 EX 12

#include <iostream>
#include <algorithm>
using namespace std;

class Link
{
public:
    string value;
    Link(const string& v, Link* s = nullptr)
        : value{v}, succ{s} {
            if(!succ) succ=this;  //single linked list have to be circular otherwise we reach a deadend at the last entry
        }

    Link* add(Link* n);
    //Link* insert(Link* n);
    Link* find(const string& s);
    const Link* find(const string& s) const;
    Link* erase();
    Link* advance(int n) const;

    Link* next() const { return succ;}
private:
    Link* succ;
};

Link* Link::add(Link* n)
{
    if(n==nullptr) return this;
    if(this==nullptr) 
    {
        n->succ=n;
        return n;
    }
    n->succ=this->succ;
    this->succ=n;
    return n;
}

Link* Link::erase()
{
    if(this==nullptr) return nullptr;
    Link* p {succ};
    this->value=succ->value;
    this->succ=succ->succ;
    p->succ=nullptr;
    return this;
}

Link* Link::find(const string& s)
{
    Link* p = this;
    Link* p_copy {p};
    while(p)
    {
        if(p->value==s) return p;
        p=p->succ;
        if(p==p_copy) break; //full loop
    }
    return nullptr;
}

Link* Link::advance(int n) const
{
    Link* p {nullptr};
    bool first_pass {true};
    if(this==nullptr) return nullptr;
    if (0<n)
    {
        while(n--)
        {
            if(succ==nullptr) return nullptr;

            if(first_pass) {p=succ;first_pass=false;}
            else p=p->succ;
        }
    }
    return p;
}
constexpr int max_room_size {20};


struct room
{
    bool wumpus;
    bool bats;
    bool hole;
    room(int n)
        :number{n}
    {};
    void add_adjacent(room* r){if(adjacent_rooms.size()>=3) cout<<"too many rooms on "<<number;}
    vector<room*> get_adjacent(){return adjacent_rooms;}
    int get_number(){return number;}
private:
    int number;
    vector<room*> adjacent_rooms;
};

struct game
{
    vector<room>rooms;
    void setupgame();
};

void game::setupgame()
{
/*
Additionally, two of the caves contain bottomless pits, while two others contain "super bats" which will pick up the player and move them to a random cave. The game is turn-based; each cave is given a number by the game, and each turn begins with the player being told which cave they are in and which caves are connected to it by tunnels. The player then elects to either move to one of those connected caves or shoot one of their five "crooked arrows", named for their ability to change direction while in flight. Each cave is connected to three others, and the system as a whole is equivalent to a dodecahedron.[1]
*/
    int n {1};
    int m {n+5};//6
    int l {m+10};//16
    for (int i = 1; i <= max_room_size; i++)
    {
        room temp_room{i};
        rooms.push_back(temp_room);
    }
    for (int i = n; i < m-1; i++) //core ring
    {
        cout<<rooms[m+i*2-1].get_number();
        rooms[i-1].add_adjacent(&rooms[m+i*2-1]); //1->8(...)
        rooms[m+i*2-1].add_adjacent(&rooms[i-1]); //8->1(...)
        rooms[i-1].add_adjacent(&rooms[i]); //1->2 (...)
        rooms[i].add_adjacent(&rooms[i-1]); //2->1 (...)
    }
    rooms[m-1].add_adjacent(&rooms[n+3]); //6->5
    rooms[n+3].add_adjacent(&rooms[m-1]); //5->6
    for (int i = m; i < l-1; i++) //inner ring
    {
        rooms[i-1].add_adjacent(&rooms[i]); //6->7 (...)
        rooms[i].add_adjacent(&rooms[i-1]); //7->6 (...)
    }
//---
    rooms[l-1].add_adjacent(&rooms[m+9-1]); //16->15
    rooms[n+4-1].add_adjacent(&rooms[n-1]); //15->16

    for (int i = l-1; i < l+4; i++) //outer ring
    {/*
        rooms[m].add_adjacent(&rooms[l]); //inner to outer
        rooms[l].add_adjacent(&rooms[m]); //outer to inner*/
        rooms[i-1].add_adjacent(&rooms[i+1]); //16->17(...)
        rooms[i+1].add_adjacent(&rooms[i-1]); //17->16(...)
    }
    rooms[l-1].add_adjacent(&rooms[l+4-1]); //16->20
    rooms[l+4-1].add_adjacent(&rooms[l-1]); //20->16
    
    
}
void gameloop()
{/*
    while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		if (t.kind == help) {help_text(); continue;}
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}*/
}

int main()
{
    game abc;
    abc.setupgame();
    //abc.rooms[0].get_adjacent()[0]->get_number();
    gameloop();
}