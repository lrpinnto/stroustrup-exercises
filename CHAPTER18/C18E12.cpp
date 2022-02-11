//CHAPTER 18 EX 12
/* This implementation of the game "Hunt the Wumpus" follows the rules described on https://en.wikipedia.org/wiki/Hunt_the_Wumpus */
#include <iostream>
#include <vector>
#include <limits>

constexpr int MAX_ROOM_SIZE {20};
constexpr int BAT_AMOUNT {2};
constexpr int PIT_AMOUNT {2};

constexpr bool END_GAME {false};
constexpr bool CONTINUE_GAME {true};
constexpr bool DEBUG {true};

constexpr int MAP_SIZE_MULTIPLIER {1}; //TO BE IMPLEMENTED

struct room
{
    bool wumpus;
    bool bats;
    bool hole;
    bool player;
    room(int n)
        :number{n},wumpus{false},bats{false},hole{false},player{false}
    {}
    room(const room& r)
        :number{r.get_number()},adjacent_rooms{r.adjacent_rooms},wumpus{r.wumpus},bats{r.bats},hole{r.hole},player{r.player}
    {}
    void add_adjacent(room*);
    std::vector<room*> get_adjacent(){return adjacent_rooms;}
    int get_number() const {return number;}
private:
    int number;
    std::vector<room*> adjacent_rooms;
};

void room::add_adjacent(room* r)
{
    if(adjacent_rooms.size()>=3) throw std::runtime_error("too many rooms on "+std::to_string(number));
    adjacent_rooms.push_back(r);
}

struct player
{
    player()
        :location{nullptr},crooked_arrows{5}{} //all players start with 5 arrows? perhaps check if this should be initialized by game struct instead?
    void set_location(room* r){location=r;}
    room* get_location() {return location;}
    int& set_arrows(){return crooked_arrows;}
    int get_arrows() const {return crooked_arrows;}
private:
    int crooked_arrows;
    room* location; 
};

struct game
{
    std::vector<room>rooms;
    std::vector<bool>room_status;  //false for empty, true for not empty
    std::vector<int>arrow_rooms;
    void setupgame();
    player p;
    game();

    bool movePlayer(int); 
    bool shoot(int);
    void batEncounter();

    void addPlayer();
    void addWump();
    void addBats();
    void addPits();

    bool movewumpus();
    bool movearrows();

    void reportState();

    void debug();
};

game::game()
    :room_status(MAX_ROOM_SIZE)
{}

void game::setupgame() //TODO: ALLOW THE CREATION OF BIGGER MAPS
{
/*
Additionally, two of the caves contain bottomless pits, while two others contain "super bats" which will pick up the player and move them to a random cave. The game is turn-based; each cave is given a number by the game, and each turn begins with the player being told which cave they are in and which caves are connected to it by tunnels. The player then elects to either move to one of those connected caves or shoot one of their five "crooked arrows", named for their ability to change direction while in flight. Each cave is connected to three others, and the system as a whole is equivalent to a dodecahedron.[1]
*/
    int n {1};
    int m {n+5};//6
    int l {m+10};//16
    for (int i = 1; i <= MAX_ROOM_SIZE; i++) //construct base rooms according to MAX_ROOM_SIZE
    {
        room temp_room{i};
        rooms.push_back(temp_room);
    }
    //generate the dodecahedral cave
    for (int i = n; i < m-1; i++) //core ring
    {
        rooms[i-1].add_adjacent(&rooms[m+i*2-1]); //1->8(...)
        rooms[m+i*2-1].add_adjacent(&rooms[i-1]); //8->1(...)
        rooms[i-1].add_adjacent(&rooms[i]); //1->2 (...)
        rooms[i].add_adjacent(&rooms[i-1]); //2->1 (...)
    }
    rooms[n+3].add_adjacent(&rooms[n-1]); //5->1
    rooms[n-1].add_adjacent(&rooms[n+3]); //1->5
    rooms[m-1].add_adjacent(&rooms[n+3]); //6->5
    rooms[n+3].add_adjacent(&rooms[m-1]); //5->6
    for (int i = m; i < l-1; i++) //inner ring
    {
        rooms[i-1].add_adjacent(&rooms[i]); //6->7 (...)
        rooms[i].add_adjacent(&rooms[i-1]); //7->6 (...)
    }
    rooms[l-1].add_adjacent(&rooms[m+9-1]); //16->15
    rooms[m+9-1].add_adjacent(&rooms[l-1]); //15->16
    rooms[m+9-1].add_adjacent(&rooms[m-1]); //15->6
    rooms[m-1].add_adjacent(&rooms[m+9-1]); //6->15

    for (int i = l; i < l+4; i++) //outer ring
    {
        rooms[m+(i-l)*2].add_adjacent(&rooms[i]); //7->17(...)
        rooms[i].add_adjacent(&rooms[m+(i-l)*2]); //17->7(...)
        rooms[i-1].add_adjacent(&rooms[i]); //16->17(...)
        rooms[i].add_adjacent(&rooms[i-1]); //17->16(...)
    }
    rooms[l-1].add_adjacent(&rooms[l+4-1]); //16->20
    rooms[l+4-1].add_adjacent(&rooms[l-1]); //20->16

    //distribute game entities
    addPlayer();
    addWump();
    addBats();
    addPits();

    //restore vacant rooms adjacent to player
    for(room* r : p.get_location()->get_adjacent())
        room_status[r->get_number()-1]=false;
}

void game::batEncounter()
{
    int empty_room_index;
    empty_room_index=rand()%room_status.size();
    while(room_status[empty_room_index]) //check if random index is in fact, empty
        empty_room_index=rand()%room_status.size();

    rooms[p.get_location()->get_number()-1].player = false;
    room_status[p.get_location()->get_number()-1] = false;

    rooms[empty_room_index].player = true;
    p.set_location(&rooms[empty_room_index]);
    room_status[empty_room_index] = true;
}

bool game::movePlayer(int position)
{
    //check if input is valid
    if(position != p.get_location()->get_adjacent()[0]->get_number() && position != p.get_location()->get_adjacent()[1]->get_number() 
    && position != p.get_location()->get_adjacent()[2]->get_number()){
        std::cout << "Invalid choice. Please move to an ADJACENT room." << std::endl;
        return CONTINUE_GAME;
    }

    //change position flags
    rooms[p.get_location()->get_number()-1].player = false;
    rooms[position-1].player = true;
    room_status[p.get_location()->get_number()-1] = false;
    p.set_location(&rooms[position-1]);

    if(rooms[p.get_location()->get_number()-1].wumpus){
        std::cout << "The Wumpus got you! YOU LOSE." << std::endl;
        return END_GAME;
    }
    if(rooms[p.get_location()->get_number()-1].hole){
        std::cout << "You fell into a bottomless pit! YOU LOSE." << std::endl;
        return END_GAME;
    }
    if(rooms[p.get_location()->get_number()-1].bats){
        std::cout << "A giant bat takes you to another room!" << std::endl;
        batEncounter();
        return CONTINUE_GAME;
    }
    return movearrows();
}

bool game::movewumpus()
{
    return CONTINUE_GAME;
}

bool game::movearrows()
{
    if(p.get_arrows()<1 && arrow_rooms.empty()) 
    {
        std::cout << "You ran out of ammo! YOU LOSE!" << std::endl;
        return END_GAME;
    }
    if(arrow_rooms.empty()) return CONTINUE_GAME;
    std::cout << "Your arrow moves to another room!" << std::endl;
    
    if(rooms[arrow_rooms[0]-1].wumpus)
    {
        std::cout << "You got the wumpus!" << std::endl;
        return END_GAME;
    }
    else if(rooms[arrow_rooms[0]-1].player)
    {
        std::cout << "You got hit by your own arrow! YOU LOSE." << std::endl;
        return END_GAME;
    }
    else
    {
        arrow_rooms.erase(arrow_rooms.begin());
        return CONTINUE_GAME;
    }  
}

bool game::shoot(int intial_room)
{
    if(!arrow_rooms.empty()) 
    {
        std::cout << "You may only have 1 active arrow at the time." << std::endl;
        return false;
    }
    room current_arrow_room {*p.get_location()}; //set arrow room as the players position before the arrow gets shot
    int target {intial_room};
    char c {0};
    //BUILD arrow_rooms list
    if(target != current_arrow_room.get_adjacent()[0]->get_number() && target != current_arrow_room.get_adjacent()[1]->get_number() && target != current_arrow_room.get_adjacent()[2]->get_number()){
            std::cout << "Invalid choice. Please target an ADJACENT room." << std::endl;
            //If the player enters a cave number that is not connected to where the arrow is, the game picks a valid option at random. 
            std::cout << "Shooting at random..." << std::endl;
            arrow_rooms.push_back(current_arrow_room.get_adjacent()[rand()%current_arrow_room.get_adjacent().size()]->get_number());
    }
    else if(p.get_arrows()>0) arrow_rooms.push_back(target);
    std::cout << "##Type the room where the arrow should move through sX or c to end. (Max: 5 rooms)##" << std::endl;
    while(arrow_rooms.size()<5 && p.get_arrows()>0){
        while(true){
            std::cout << "Your arrow is currently targetting room " << std::to_string(rooms[arrow_rooms.back()-1].get_number()) << std::endl;
            std::cout << "Adjacent rooms are " << std::to_string(rooms[arrow_rooms.back()-1].get_adjacent()[0]->get_number()) <<", "<<std::to_string(rooms[arrow_rooms.back()-1].get_adjacent()[1]->get_number())
                <<", "<<std::to_string(rooms[arrow_rooms.back()-1].get_adjacent()[2]->get_number())<<std::endl;
            std::cout << 5-arrow_rooms.size() << " rooms left." << std::endl;
            std::cout << "Enter command: ";
            std::cin >> c;
            if(c != 'c')
            {
                std::cin.putback(c);
                std::cin >> c >> target;
            }
            if(std::cin.fail() || (c != 'c' && c != 's')){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(),'\n');
                std::cout << "Invalid input. Type a room number or c." << std::endl;
            }
            else break;
        }
        if(c == 'c')
        {
            break;
        }
        if(target != rooms[arrow_rooms.back()-1].get_adjacent()[0]->get_number() && target != rooms[arrow_rooms.back()-1].get_adjacent()[1]->get_number() && target != rooms[arrow_rooms.back()-1].get_adjacent()[2]->get_number()){
            std::cout << "Invalid choice. Please target an ADJACENT room." << std::endl;
            //If the player enters a cave number that is not connected to where the arrow is, the game picks a valid option at random. 
            std::cout << "Shooting at random..." << std::endl;
            arrow_rooms.push_back(rooms[arrow_rooms.back()-1].get_adjacent()[rand()%rooms[arrow_rooms.back()-1].get_adjacent().size()]->get_number());
        }
        else arrow_rooms.push_back(target);
    }
    /*else if(p.get_location()->get_adjacent()[0]->wumpus || p.get_location()->get_adjacent()[1]->wumpus || p.get_location()->get_adjacent()[2]->wumpus)
        return movewumpus();*/

    p.set_arrows()--; //decrease players ammo after a sucessfull shot
    std::cout << "You shot an arrow towards room " << rooms[arrow_rooms.back()-1].get_number() << std::endl;
    return true;
}

void game::addPlayer()
{
    int empty_room_index;
    empty_room_index=rand()%room_status.size();
    while(room_status[empty_room_index]) //check if random index is in fact, empty
        empty_room_index=rand()%room_status.size();
    rooms[empty_room_index].player = true;
    p.set_location(&rooms[empty_room_index]);

    room_status[empty_room_index]=true;

    //no enemies should spawn adjacent to player

    for(room* r : p.get_location()->get_adjacent())
    {
        room_status[r->get_number()-1]=true; //check if index number=room number
    }
}

void game::addWump()
//spawns the wumpus in a random room
{
    int empty_room_index;
    empty_room_index=rand()%room_status.size();
    while(room_status[empty_room_index]) //check if random index is in fact, empty
        empty_room_index=rand()%room_status.size();

    rooms[empty_room_index].wumpus = true;
    //std::cout<<"Wumpus in room "<<vacant[r]<<std::endl;
    room_status[empty_room_index] = true; //remove vacancy
}

void game::addBats()
//spawns bats
{
    int empty_room_index;
    for(int i = 0; i < BAT_AMOUNT; ++i){
        empty_room_index=rand()%room_status.size();
        while(room_status[empty_room_index]) //check if random index is in fact, empty
            empty_room_index=rand()%room_status.size();
        
        rooms[empty_room_index].bats = true;
        room_status[empty_room_index] = true;
    }
}

void game::addPits()
//place pits
{
    int empty_room_index;
    for(int i = 0; i < PIT_AMOUNT; ++i){
        empty_room_index=rand()%room_status.size();
        while(room_status[empty_room_index]) //check if random index is in fact, empty
            empty_room_index=rand()%room_status.size();
        
        rooms[empty_room_index].hole = true;
        room_status[empty_room_index] = true;
    }
}

void game::reportState()
{
    std::cout << "You are in room " << std::to_string(p.get_location()->get_number()) << std::endl;
    std::cout << "Adjacent rooms are " << std::to_string(p.get_location()->get_adjacent()[0]->get_number()) <<", "<<std::to_string(p.get_location()->get_adjacent()[1]->get_number())
              <<", "<<std::to_string(p.get_location()->get_adjacent()[2]->get_number())<<std::endl;

    if(p.get_location()->get_adjacent()[0]->bats || p.get_location()->get_adjacent()[1]->bats || p.get_location()->get_adjacent()[2]->bats)
        std::cout << "I hear a bat." << std::endl;

    if(p.get_location()->get_adjacent()[0]->hole || p.get_location()->get_adjacent()[1]->hole || p.get_location()->get_adjacent()[2]->hole)
        std::cout << "I feel a draft." << std::endl;

    if(p.get_location()->get_adjacent()[0]->wumpus || p.get_location()->get_adjacent()[1]->wumpus || p.get_location()->get_adjacent()[2]->wumpus)
        std::cout << "I smell the wumpus." << std::endl;
}

void game::debug()
{
    std::string wumpus;
    std::string bat;
    std::string pit;
    std::string player_loc;
    std::string arrows_loc;
    for(room r: rooms){
        if (r.wumpus)
        {
            wumpus+=(std::to_string(r.get_number()));
            wumpus.push_back(',');
        }
        if (r.bats)
        {
            bat+=(std::to_string(r.get_number()));
            bat.push_back(',');
            }
        if (r.hole)
        {
            pit+=(std::to_string(r.get_number()));
            pit.push_back(',');
        }
        if (r.player)
        {
            player_loc+=(std::to_string(r.get_number()));
            player_loc.push_back(',');
        }
    }
    for (int i : arrow_rooms)
    {
        arrows_loc.push_back('->');
        arrows_loc+=std::to_string(i);
    }
        
    std::cout << std::endl;
    std::cout << "#############DEBUGGING#############" << std::endl;
    std::cout << "\tWumpus -> " << wumpus << std::endl;
    std::cout << "\tBat -> " << bat << std::endl;
    std::cout << "\tPit -> " << pit << std::endl;
    std::cout << "\tPlayer -> " << player_loc << std::endl;
    std::cout << "\tArrows -> " << arrows_loc << std::endl;
    std::cout << "###################################" << std::endl;
    std::cout << std::endl;
    
}

void gameloop(game& game_entity)
{
    bool game_state {true};
    while (game_state)
    {
        if(DEBUG) game_entity.debug();
        game_entity.reportState();
        char c = 0;
        int r = -1;
        std::cout << "Type mXX(sXX) to move(shoot) to(at) room XX." << std::endl;
        while(1){
            std::cout << "Enter command: ";
            std::cin >> c >> r;
            if(std::cin.fail() || (c != 'm' && c != 's')){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(),'\n');
                std::cout << "Invalid input. Type mXX(sXX) to move(shoot) to(at) room XX." << std::endl;
            }
            else break;
        }
        if(c == 'm')
        { 
            game_state=game_entity.movePlayer(r);
        }
        else if(game_entity.shoot(r)) //Only allow 1 arrow travelling at the same time
        {
            game_state=game_entity.movearrows(); 
        }
    }
}

int main()
try{
    time_t seed_time {time(0)};
    int seed_num {unsigned(seed_time)};
    std::cout << "Hunt the Wumpus! Shoot an arrow at the Wumpus to win the game." << '\n' << "Your unique seed is " << seed_num << '.' <<std::endl;
    srand(unsigned(time(0)));
    game abc;
    abc.setupgame();
    gameloop(abc);
}
catch(std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}