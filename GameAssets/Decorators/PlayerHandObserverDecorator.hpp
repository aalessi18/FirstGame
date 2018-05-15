#ifndef PlayerHandsObserverDecorator_hpp
#define PlayerHandsObserverDecorator_hpp

#include "PlayerHandsObserver.hpp"

class PlayerHandsDecorator : public PlayerHandsObserver {
private:
    PlayerHandsObserver* decoratedObserver;
    bool isDetailed;
public:
    PlayerHandsDecorator();
    PlayerHandsDecorator(PlayerHandsObserver* decoratedObserver);
    ~PlayerHandsDecorator();
    virtual void update();
    virtual void printHands();
    virtual void setDetailedDecorator(bool isDetailed);
};

#endif /* PlayerHandObserverDecorator_hpp */
