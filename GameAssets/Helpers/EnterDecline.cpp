#include "EnterDecline.hpp"

EnterDecline::EnterDecline() {
    this->player = NULL;
    this->map = NULL;
}

EnterDecline::EnterDecline(Map &map, Player &player) {
    this->map = &map;
    this->player = &player;
}

EnterDecline::~EnterDecline() {
    
}

void EnterDecline::assistDecline() {
    this->player->enterDecline();
    
    for(int i=0; i<this->player->getRegionsControlled().size(); i++)
    {
        cout << "Previous race tokens on region: " << this->map->getGraph()[this->player->getRegionsControlled().at(i)].getAmountOfRaceTokens()<< endl;
        this->map->getGraph()[this->player->getRegionsControlled().at(i)].setAmountOfRaceTokens(1);
        cout << "New race tokens on region: " << this->map->getGraph()[this->player->getRegionsControlled().at(i)].getAmountOfRaceTokens()<< endl;
    }
}
