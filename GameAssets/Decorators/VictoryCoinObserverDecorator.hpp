#ifndef VictoryCoinObserverDecorator_hpp
#define VictoryCoinObserverDecorator_hpp

#include "VictoryCoinObserver.hpp"

class VictoryCoinObserverDecorator : public VictoryCoinObserver {
private:
    VictoryCoinObserver* decoratedObserver;
    bool isDetailed;
public:
    VictoryCoinObserverDecorator();
    VictoryCoinObserverDecorator(VictoryCoinObserver* decoratedObserver);
    ~VictoryCoinObserverDecorator();
    virtual void update();
    virtual void printCoinsEarned();
    virtual void setDetailedDecorator(bool isDetailed);
};

#endif /* VictoryCoinObserverDecorator_hpp */
