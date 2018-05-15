#ifndef Strategy_hpp
#define Strategy_hpp

#include <iostream>
#include <string>

using namespace std;

// Class for Strategies using the strategy pattern. This is simply the abstract base class to derive from

class Strategy {
protected:
    string strategyType; // To hold the strategy type name
public:
    // Abstract method in which derived claases will defined in order to print their respective suggestions
    virtual string suggestionForStrategy()=0;
};

// Class for the aggressive strategy. This class will print to the player what they should be looking for as an aggressive player

class Aggressive : public Strategy {
private:
public:
    Aggressive();
    ~Aggressive();
    virtual string suggestionForStrategy();
};

// Class for the defensive strategy

class Defensive : public Strategy {
private:
public:
    Defensive();
    ~Defensive();
    virtual string suggestionForStrategy();
};

// Class for the moderate strategy (in between of aggressive and defensive)

class Moderate : public Strategy {
private:
public:
    Moderate();
    ~Moderate();
    virtual string suggestionForStrategy();
};

 
#endif /* Strategy_hpp */
