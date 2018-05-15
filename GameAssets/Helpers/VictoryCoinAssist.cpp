#include "VictoryCoinAssist.hpp"

VictoryCoinAssist::VictoryCoinAssist() {
    this->scoreToAdd = 0;
}


VictoryCoinAssist::VictoryCoinAssist(Player &player, VictoryCoin &victoryCoin, int scoreToAdd) {
    this->player = &player;
    this->victoryCoins = &victoryCoin;
    this->scoreToAdd = scoreToAdd;
}

VictoryCoinAssist::~VictoryCoinAssist() {
    
}

void VictoryCoinAssist::assistVictoryCoin() {
    this->victoryCoins->exchangeVictoryCoins(player->getVictoryCoins());
    this->victoryCoins->removeFromVictoryCoins(scoreToAdd, player->getVictoryCoins());
    this->player->printVictoryPoints();
    Notify();
}

int VictoryCoinAssist::amountScored() {
    return scoreToAdd;
}
