#ifndef TurnMarker_hpp
#define TurnMarker_hpp

#include "Subject.hpp"

/*
 Class to hold the turnmarker as an object in order to gauge at which turn we are at and if
 we have reached the end of our game based on the amount of players we have.
 
 This object is the subject to the TurnMarkerObserver
 */

class TurnMarker : public Subject{
private:
    int totalTurns;
    int turnTracker;
public:
    TurnMarker();
    TurnMarker(int numberOfPlayers);
    ~TurnMarker();
    void updateTurnTracker();
    void setTotalTurns(int numberOfPlayers);
    int getTurnTracker();
    int getTotalTurns();
};


#endif /* TurnMarker_hpp */
