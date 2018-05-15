#ifndef GameStatisticsObserverDecorator_hpp
#define GameStatisticsObserverDecorator_hpp

#include "GameStatisticsObserver.hpp"

// Class which decorates the game statistics observer by printing out a small graph for the statistical representation

class GameStatisticsObserverDecorator : public GameStatisticsObserver {
private:
    GameStatisticsObserver* decoratedObserver;
    bool isDetailed;
public:
    GameStatisticsObserverDecorator();
    GameStatisticsObserverDecorator(GameStatisticsObserver *decoratedObserver);
    ~GameStatisticsObserverDecorator();
    virtual void setDetailedDecorator(bool isDetailed);
    virtual void printStatistics();
    virtual void update();
};

#endif /* GameStatisticsObserverDecorator_hpp */
