#ifndef VICTORYCOINASSIST_HPP_
#define VICTORYCOINASSIST_HPP_

#include "Player.hpp"
#include "VictoryCoin.hpp"
#include "Subject.hpp"

using namespace std;

/*
 This class assists the player class in calculating the victoryCoins they hold and the amount they earn.
 This class is also the subject to the VictoryCoinObserver 
 */

class VictoryCoinAssist : public Subject{
private:
    Player *player;
    VictoryCoin *victoryCoins;
    int scoreToAdd;
public:
    VictoryCoinAssist();
    VictoryCoinAssist(Player &player, VictoryCoin &victoryCoin, int scoreToAdd);
    ~VictoryCoinAssist();
    void assistVictoryCoin();
    int amountScored();
};

#endif
