#include "PlayerHands.hpp"

PlayerHands::PlayerHands() {
    this->players = NULL;
}

PlayerHands::PlayerHands(vector<Player*> &players) {
    this->players = &players;
}

PlayerHands::~PlayerHands() {
    
}

// Method which notifies the observer to print the players's hands
void PlayerHands::showHands() {
    Notify();
}

// Method to return the players vector in order to help Observers
vector<Player*>* PlayerHands::getPlayers() {
    return this->players;
}
