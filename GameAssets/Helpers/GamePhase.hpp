#ifndef GamePhase_hpp
#define GamePhase_hpp

#include <iostream>
#include "Player.hpp"

using namespace std;

/*
 This class states the phases in which the player is in.
 This class is the subject to the PhaseObserver
 */

class GamePhase : public Subject {
private:
    string currentPhase;
    Player *player;
public:
    GamePhase();
    GamePhase(Player &player);
    ~GamePhase();
    void setGamePhase(string currentPhase);
    string getGamePhase();
    void printGamePhase();
};

#endif /* GamePhase_hpp */
