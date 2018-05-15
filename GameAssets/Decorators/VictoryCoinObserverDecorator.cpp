#include "VictoryCoinObserverDecorator.hpp"

VictoryCoinObserverDecorator::VictoryCoinObserverDecorator() {
    this->decoratedObserver = NULL;
}

VictoryCoinObserverDecorator::VictoryCoinObserverDecorator(VictoryCoinObserver* decoratedObserver) {
    this->decoratedObserver = decoratedObserver;
    this->victoryCoinAssist = this->decoratedObserver->getVictoryCoinAssist();
    
    // Detaching in order to attached the new derived decorator, orelse there will be two observers attached to the same subject
    this->victoryCoinAssist->Detach(decoratedObserver);
    this->victoryCoinAssist->Attach(this);
}

VictoryCoinObserverDecorator::~VictoryCoinObserverDecorator() {
    
}

// Method that is called once this observer is notified by its subject
void VictoryCoinObserverDecorator::update() {
    this->printCoinsEarned();
}

void VictoryCoinObserverDecorator::printCoinsEarned() {
    
    // If conditions since we allow the user to choose whether they want the basic or decorated observers every turn
    if(isDetailed==true)
    {
        cout << "==================== Victory Coins This Turn ====================" << endl;
    }
    this->decoratedObserver->printCoinsEarned();
    if(isDetailed==true)
    {
        cout << "=================================================================" << endl;
    }
}

void VictoryCoinObserverDecorator::setDetailedDecorator(bool isDetailed) {
    this->isDetailed = isDetailed;
}
