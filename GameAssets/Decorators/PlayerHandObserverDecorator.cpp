#include "PlayerHandObserverDecorator.hpp"

PlayerHandsDecorator::PlayerHandsDecorator() {
    this->decoratedObserver = NULL;
    this->isDetailed = true;
}

PlayerHandsDecorator::PlayerHandsDecorator(PlayerHandsObserver* decoratedObserver) {
    this->decoratedObserver = decoratedObserver;
    this->playerHands = this->decoratedObserver->getPlayerHands();
    
    // Detaching in order to attached the new derived decorator, orelse there will be two observers attached to the same subject
    this->playerHands->Detach(decoratedObserver);
    this->playerHands->Attach(this);
    this->isDetailed = true;
}

PlayerHandsDecorator::~PlayerHandsDecorator() {
    
}

// Method that is called once this observer is notified by its subject
void PlayerHandsDecorator::update() {
    this->printHands();
}

void PlayerHandsDecorator::printHands() {
    
    // If conditions since we allow the user to choose whether they want the basic or decorated observers every turn
    if(isDetailed==true)
    {
        cout << "===================== Players's Hands =====================" << endl;
    }
    this->decoratedObserver->printHands();
    if(isDetailed==true)
    {
        cout << "===========================================================" <<endl;
    }
}

void PlayerHandsDecorator::setDetailedDecorator(bool isDetailed) {
    this->isDetailed = isDetailed;
}
