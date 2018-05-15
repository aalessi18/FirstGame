#ifndef Subject_hpp
#define Subject_hpp

#include "Observer.hpp"
#include <list>

using namespace std;

// Interface to add, delete and update observers

class Subject {
private:
    list<Observer*> *observers;
public:
    Subject();
    virtual ~Subject();
    virtual void Attach(Observer* o);
    virtual void Detach(Observer* o);
    virtual void Notify();
};

#endif /* Subject_hpp */
