#include "GamePhase.hpp"

GamePhase::GamePhase() {
    this->currentPhase = "";
    this->player = NULL;
}

GamePhase::GamePhase(Player &player) {
    this->currentPhase = "";
    this->player = &player;
}

GamePhase::~GamePhase() {
    
}

void GamePhase::setGamePhase(string currentPhase) {
    this->currentPhase = currentPhase;
    this->Notify();
}

string GamePhase::getGamePhase() {
    return currentPhase;
}

void GamePhase::printGamePhase() {
    cout << "======================" << this->player->getName() << ": " << currentPhase << "======================" << endl;
}
