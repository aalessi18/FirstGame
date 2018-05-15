#ifndef Race_hpp
#define Race_hpp

#include <iostream>
#include "Tokens.hpp"
#include "Subject.hpp"

using namespace std;

// These are all the races available in the game

class Race {
protected:
    string name;
    int tokenAmount;
    int raceTokens;
    bool active; 
public:
    Race();
    virtual ~Race();
    string getName();
    int getTokenAmount();
    virtual void racialAbility();
    void addRaceTokens(int raceTokens);
    void removeRaceTokens(int raceTokens);
    int getRaceTokens();
    bool raceDeclined();
    void setRaceDecline();
};

class LostTribes : public Race{
private:
public:
    LostTribes();
    ~LostTribes();
};

class Amazons: public Race{
private:
    
public:
    Amazons();
    ~Amazons();
    void racialAbility();
};

class Dwarves: public Race{
private:
    
public:
    Dwarves();
    ~Dwarves();
    void racialAbility();
};

class Elves: public Race{
private:
    
public:
    Elves();
    ~Elves();
    void racialAbility();
};

class Ghouls: public Race{
private:
    
public:
    Ghouls();
    ~Ghouls();
    void racialAbility();
};

class Giants: public Race{
private:
    
public:
    Giants();
    ~Giants();
    void racialAbility();
};

class Halflings: public Race{
private:
    HolesInTheGround* holesInTheGroundToken;
public:
    Halflings();
    ~Halflings();
    void racialAbility();
};

class Humans: public Race{
private:
    
public:
    Humans();
    ~Humans();
    void racialAbility();
};

class Orcs : public Race{
private:
    
public:
    Orcs();
    ~Orcs();
    void racialAbility();
};

class Ratmen: public Race{
private:
    
public:
    Ratmen();
    ~Ratmen();
    void racialAbility();
};

class Skeletons: public Race{
private:
    
public:
    Skeletons();
    ~Skeletons();
    void racialAbility();
};

class Sorcerers: public Race{
private:
    
public:
    Sorcerers();
    ~Sorcerers();
    void racialAbility();
};

class Tritons: public Race{
private:
    
public:
    Tritons();
    ~Tritons();
    void racialAbility();
};

class Trolls: public Race{
private:
    TrollLair* trollLairTokens;
public:
    Trolls();
    ~Trolls();
    void racialAbility();
};

class Wizards: public Race{
private:
    
public:
    Wizards();
    ~Wizards();
    void racialAbility();
};

class BlankRace: public Race {
private:
public:
    BlankRace();
    ~BlankRace();
    void racialAbility();
};

#endif /* Race_h */
