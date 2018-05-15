#include "TurnMarker.hpp"

TurnMarker::TurnMarker(){
    this->turnTracker = 0;
    this->totalTurns = 0;
}

TurnMarker::TurnMarker(int numberOfPlayers){
    this->turnTracker = 1;
    setTotalTurns(numberOfPlayers);
}

TurnMarker::~TurnMarker(){
    
}

void TurnMarker::setTotalTurns(int numberOfPlayers) {
    switch(numberOfPlayers)
    {
        case 2:
            this->totalTurns = 10;
            break;
        case 3:
            this->totalTurns = 10;
            break;
        case 4:
            this->totalTurns = 9;
            break;
        case 5:
            this->totalTurns = 8;
            break;
    }
}

void TurnMarker::updateTurnTracker(){
    turnTracker++;
    
    Notify();
}

int TurnMarker::getTurnTracker(){
    return this->turnTracker;
}

int TurnMarker::getTotalTurns(){
    return this->totalTurns;
}
