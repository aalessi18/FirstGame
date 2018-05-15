#include "TurnMarkerObserver.hpp"

TurnMarkerObserver::TurnMarkerObserver() {
    this->turnMarker = NULL;
}

TurnMarkerObserver::TurnMarkerObserver(TurnMarker &turnMarker) {
    this->turnMarker = &turnMarker;
    this->turnMarker->Attach(this);
}

TurnMarkerObserver::~TurnMarkerObserver() {
    
}

// Method that is called once this observer is notified by its subject
void TurnMarkerObserver::update() {
    cout << "================================= Turn #" << this->turnMarker->getTurnTracker() << " =================================" << endl;
}
