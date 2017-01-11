#include <iostream>
#include "Types.h"
#include "Players.h"

using namespace std;

class Game : public Players {
public:
    static Types::power getUserPower() {
        return Players::UserP;
    }
    static void getUserPower(int *var) {
        *var = Players::UserP;
    }
    /*/ ============================================= /*/
    static Types::health getUserHealth() {
        return Players::UserH;
    }
    static void getUserHealth(int *var) {
        *var = Players::UserH;
    }
    /*/ ============================================= /*/
    static Types::damage hurtUser(Types::damage damage, Game *pointer, int num) {
        cout << "Player " << num << " got hurt! -" << damage << endl << endl;
        pointer->UserH -= damage;
    }
    static Types::damage hurtUser(Types::damage damage, Game obj) {
        cout << "All players got hurt! -" << damage << endl << endl;
        obj.UserH -= damage;
    }
    static void printStats(Game *point1, Game *point2){
        cout << "Power player 1: " << point1->getUserPower() << endl;
        cout << "Health player 1: " << point1->getUserHealth() << endl << endl;

        cout << "Power player 2: " << point2->getUserPower() << endl;
        cout << "Health player 2: " << point2->getUserHealth() << endl << endl;
    }
};

int main() {
    Game player;
    Game *player1 = new Game;
    Game *player2 = new Game;
    player1 = &player;
    player2 = &player;

    Game::printStats(player1, player2);

    player.hurtUser(10, player);

    Game::printStats(player1, player2);

    player1->hurtUser(20, player2, 1);

    player1->printStats(player1, player2);

    delete &player1;
    delete &player2;
    return 0;
}