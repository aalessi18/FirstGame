#ifndef TurnMarkerObserver_hpp
#define TurnMarkerObserver_hpp

#include "Observer.hpp"
#include "TurnMarker.hpp"

// Observer class which will change the turn marker token as the game progresses

class TurnMarkerObserver : public Observer {
private:
    TurnMarker *turnMarker;
public:
    TurnMarkerObserver();
    TurnMarkerObserver(TurnMarker &turnMarker);
    ~TurnMarkerObserver();
    virtual void update();
};

#endif /* TurnMarkerObserver_hpp */
