#ifndef SpecialPower_hpp
#define SpecialPower_hpp

#include <iostream>
#include "Tokens.hpp"
#include "Subject.hpp"

using namespace std;

// These are all the special powers available in the game

class SpecialPower {
protected:
    int armyTokenAmount;
    string name;
public:
    int getTokenAmount();
    string getName();
    virtual void specialAbility() = 0;
};

class Alchemist: public SpecialPower{
private:
    
public:
    Alchemist();
    ~Alchemist();
    void specialAbility();
};

class Berzerk: public SpecialPower{
private:
    
public:
    Berzerk();
    ~Berzerk();
    void specialAbility();
};

class Bivouacking: public SpecialPower{
private:
    Encampment* encampmentToken;
public:
    Bivouacking();
    ~Bivouacking();
    void specialAbility();
};

class Commando: public SpecialPower{
private:
    
public:
    Commando();
    ~Commando();
    void specialAbility();
};

class Diplomat: public SpecialPower{
private:
    
public:
    Diplomat();
    ~Diplomat();
    void specialAbility();
};

class DragonMaster: public SpecialPower{
private:
    Dragon* dragonToken;
public:
    DragonMaster();
    ~DragonMaster();
    void specialAbility();
};

class Flying: public SpecialPower{
private:
    
public:
    Flying();
    ~Flying();
    void specialAbility();
};

class ForestPower: public SpecialPower{
private:
    
public:
    ForestPower();
    ~ForestPower();
    void specialAbility();
};

class Fortified: public SpecialPower{
private:
    Fortress fortressToken;
public:
    Fortified();
    ~Fortified();
    void specialAbility();
};

class Heroic: public SpecialPower{
private:
    Heroic* heroicToken;
public:
    Heroic();
    ~Heroic();
    void specialAbility();
};

class HillPower: public SpecialPower{
private:
    
public:
    HillPower();
    ~HillPower();
    void specialAbility();
};

class Merchant: public SpecialPower {
private:
    
public:
    Merchant();
    ~Merchant();
    void specialAbility();
};

class Mounted: public SpecialPower{
private:
    
public:
    Mounted();
    ~Mounted();
    void specialAbility();
};

class Pillaging: public SpecialPower{
private:
    
public:
    Pillaging();
    ~Pillaging();
    void specialAbility();
};

class Seafaring: public SpecialPower{
private:
    
public:
    Seafaring();
    ~Seafaring();
    void specialAbility();
};

class Spirit: public SpecialPower{
private:
    
public:
    Spirit();
    ~Spirit();
    void specialAbility();
};

class Stout: public SpecialPower{
private:
    
public:
    Stout();
    ~Stout();
    void specialAbility();
};

class SwampPower: public SpecialPower{
private:
    
public:
    SwampPower();
    ~SwampPower();
    void specialAbility();
};

class Underworld: public SpecialPower{
private:
    
public:
    Underworld();
    ~Underworld();
    void specialAbility();
};

class Wealthy: public SpecialPower{
private:
    
public:
    Wealthy();
    ~Wealthy();
    void specialAbility();
};

class BlankAbility: public SpecialPower{
private:
public:
    BlankAbility();
    ~BlankAbility();
    void specialAbility();
};

#endif /* SpecialPower_h */
