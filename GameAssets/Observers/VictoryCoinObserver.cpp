#include "VictoryCoinObserver.hpp"

VictoryCoinObserver::VictoryCoinObserver() {
    
}

VictoryCoinObserver::VictoryCoinObserver(VictoryCoinAssist &victoryCoinAssist) {
    this->victoryCoinAssist = &victoryCoinAssist;
    this->victoryCoinAssist->Attach(this);
}

VictoryCoinObserver::~VictoryCoinObserver() {
    
}

// Method that is called once this observer is notified by its subject
void VictoryCoinObserver::VictoryCoinObserver::update() {
    this->printCoinsEarned();
}

void VictoryCoinObserver::printCoinsEarned() {
    cout << "Amount earned: " << this->victoryCoinAssist->amountScored() << endl;
}

VictoryCoinAssist* VictoryCoinObserver::getVictoryCoinAssist() {
    return this->victoryCoinAssist;
}

// Need an empty method in order to engage in runtime polymorphism of this method with its derived classes
void VictoryCoinObserver::setDetailedDecorator(bool isDetailed) {
    
}
