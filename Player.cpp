#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    /* data */
    friend void display_player(Player &p);
    string name {"12345"};
    int health;
    int xp;
    static int n_players;
public:
    /* Constructor */ 
    // Player();
    // Player(string s);
    Player(string s="None", 
           int h=0, 
           int xp_val=0);
    /* Copy constructor: always define a copy constructor
    when your class has raw pointer members
    provide the copy constructor with a const reference parameter
    General syntax
    Type::Type(const Type &src) {}
    */
    Player(const Player &src);
    /* destructor */ 
    ~Player() {
        cout << "Destructor called for " << name << endl;
        --n_players;
    };

    /* methods */
    void set_name(string s) { name = s; }

    string get_name() const { return name; }

    int get_health() { return health; }

    int get_xp() { return xp; }

    static int get_n_players();
};

int Player::n_players {0};

// delegating constructors
// with constructor initialization list
Player::Player(string s, int h, int xp_val)
    : name {s}, health {h}, xp {xp_val} {
        cout << "1-args constructor" << endl;
        ++n_players;
}

// copy constructor implementation
// Player::Player(const Player &src)
//     : name {src.name + "_copy"},
//     health {src.health + 100},
//     xp {src.xp + 10} {
//         cout << "copy constructor - made copy of: " << src.name << endl;
// }
//  implement with delegating constructors
Player::Player(const Player &src)
    : Player {src.name + "_copy", src.health + 100, src.xp + 10} {
        cout << "copy constructor - made copy of: " << src.name << endl;
}

int Player::get_n_players() { return n_players; }

void display_active_players() {
    cout << "There are " << Player::get_n_players() << 
    " active players." << endl;
}

void display_player(Player &p) {
    cout << "Name: " << p.name << endl;
    cout << "Health: " << p.health << endl;
    cout << "XP: " << p.xp << endl;
}

int main(int argc, char const *argv[])
{
    display_active_players();

    const Player p1 {"p1"};
    cout << p1.get_name() << endl;
    // display_player(p1);
    display_active_players();

    Player p2 {p1};
    // display_player(p2);
    display_active_players();

    {
        Player p3 {};
        display_active_players();
        Player p4 {};
        display_active_players();
    }

    display_active_players();

    Player *e = new Player {"enemy", 100, 100};
    display_active_players();

    delete e;
    display_active_players();
    // Player p2("p2", 50, 5);
    // cout << p2.get_name() << endl;

    // Player p3("p3", 10);
    // cout << p3.get_name() << endl;
    // return 0;
}
