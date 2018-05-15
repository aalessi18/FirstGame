#include "PhaseObserver.hpp"

PhaseObserver::PhaseObserver() {
    this->gamePhase = NULL;
}

PhaseObserver::PhaseObserver(GamePhase &gamePhase) {
    this->gamePhase = &gamePhase;
    this->gamePhase->Attach(this);
}

PhaseObserver::~PhaseObserver() {
    
}

void PhaseObserver::update() {
    cout << endl;
    this->gamePhase->printGamePhase();
}
