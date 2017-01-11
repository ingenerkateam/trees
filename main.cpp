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
    static Types::damage hurtUser(Types::damage damage, int num) {
        cout << "Player " << num << " got hurt! -" << damage << endl << endl;
        Players::UserH -= damage;
    }
    static Types::damage hurtUser(Types::damage damage) {
        cout << "All players got hurt! -" << damage << endl << endl;
        Players::UserH -= damage;
    }
    static void printStats(Game *point1, Game *point2){
        cout << "Health player 1: " << point1->getUserPower() << endl;
        cout << "Health player 1: " << point1->getUserHealth() << endl << endl;

        cout << "Health player 2: " << point2->getUserPower() << endl;
        cout << "Health player 2: " << point2->getUserHealth() << endl << endl;
    }
};

int main() {
    Game player;
    Game *player1, *player2 = new Game;
    player1 = &player;
    player2 = &player;

    Game::printStats(player1, player2);

    player.hurtUser(10);

    Game::printStats(player1, player2);

    player1->hurtUser(19,1);

    delete player1;
    delete player2;
    return 0;
}