#include "PlayerHands.hpp"

PlayerHands::PlayerHands() {
    
}

PlayerHands::PlayerHands(vector<Player*> &players){
    this->players = players;
}

PlayerHands::~PlayerHands() {
    
}

void PlayerHands::showHands() {
    //Notify
}

void PlayerHands::changeCombo(Race* race, SpecialPower* specialPower) {
    
}

vector<Player*>& PlayerHands::getPlayers() {
    return players;
}
