#ifndef PhaseObserver_hpp
#define PhaseObserver_hpp

#include "Observer.hpp"
#include "GamePhase.hpp"

using namespace std;

// Observer class which shows the changes in the phases of each player

class PhaseObserver: public Observer {
private:
    GamePhase* gamePhase;
public:
    PhaseObserver();
    PhaseObserver(GamePhase &gamePhase);
    ~PhaseObserver();
    virtual void update();
};

#endif /* PhaseObserver_hpp */
