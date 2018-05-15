#include "PlayerHandsObserver.hpp"

PlayerHandsObserver::PlayerHandsObserver() {
    this->playerHands = NULL;
}

PlayerHandsObserver::PlayerHandsObserver(PlayerHands &playerHands) {
    this->playerHands = &playerHands;
    this->playerHands->Attach(this);
}

PlayerHandsObserver::~PlayerHandsObserver() {
    
}

// Method that is called once this observer is notified by its subject
void PlayerHandsObserver::update() {
    printHands();
}

void PlayerHandsObserver::printHands() {
    for(int i=0;i<playerHands->getPlayers()->size();i++)
    {
        cout << playerHands->getPlayers()->at(i)->getName() << "'s hand is: " << endl;
        if(this->playerHands->getPlayers()->at(i)->getActiveRace()!=NULL)
        {
            cout << "Active Race: " << playerHands->getPlayers()->at(i)->getActiveRace()->getName() << endl;
        }
        if(this->playerHands->getPlayers()->at(i)->getDeclinedRace().size()>0)
        {
            cout << "Declined Race(s): " << endl;
            for(int j=0;j<playerHands->getPlayers()->at(i)->getDeclinedRace().size();j++)
            {
                cout << this->playerHands->getPlayers()->at(i)->getDeclinedRace().at(j)->getName() << endl;
            }
        }
        if(this->playerHands->getPlayers()->at(i)->getSpecialPower()!=NULL)
        {
            cout << "Special Ability: " << this->playerHands->getPlayers()->at(i)->getSpecialPower()->getName();
        }
        cout << endl;
    }
}

PlayerHands* PlayerHandsObserver::getPlayerHands() {
    return playerHands;
}

// Need an empty method in order to engage in runtime polymorphism of this method with its derived classes
void PlayerHandsObserver::setDetailedDecorator(bool isDetailed) {
    
}


