#ifndef Observer_hpp
#define Observer_hpp

#include <iostream>

using namespace std;

// Observers update class in order to use the update method once the Subject changes

class Observer {
private:
protected:
    Observer();
public:
    virtual ~Observer();
    virtual void update()=0;
};

#endif /* Observer_hpp */
