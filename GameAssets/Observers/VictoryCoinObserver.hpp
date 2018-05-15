#ifndef VictoryCoinObserver_hpp
#define VictoryCoinObserver_hpp

#include "Observer.hpp"
#include "VictoryCoinAssist.hpp"

// Observer class which displays the victory coins the player earned on their turn

class VictoryCoinObserver : public Observer{
protected:
    VictoryCoinAssist* victoryCoinAssist;
public:
    VictoryCoinObserver();
    VictoryCoinObserver(VictoryCoinAssist &victoryCoinAssist);
    ~VictoryCoinObserver();
    virtual void update();
    virtual void printCoinsEarned();
    VictoryCoinAssist* getVictoryCoinAssist();
    virtual void setDetailedDecorator(bool isDetailed);
};

#endif /* VictoryCoinObserver_h */
