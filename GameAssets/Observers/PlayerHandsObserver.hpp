#ifndef PlayerHandsObserver_hpp
#define PlayerHandsObserver_hpp

#include "Observer.hpp"
#include "PlayerHands.hpp"
#include <vector>

class PlayerHandsObserver : public Observer {
protected:
    PlayerHands* playerHands;
public:
    PlayerHandsObserver();
    PlayerHandsObserver(PlayerHands &playerHands);
    ~PlayerHandsObserver();
    virtual void update();
    virtual void printHands();
    PlayerHands* getPlayerHands();
    virtual void setDetailedDecorator(bool isDetailed);
};

#endif /* PlayerHandObserver_hpp */
