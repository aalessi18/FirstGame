#ifndef Region_hpp
#define Region_hpp

#include <iostream>
#include "Player.hpp"

using namespace std;

// Parent class with all the basic common attributes and methods which will be inherited by the derived Region classes

class Region{
protected:
    string specialTrait;
    string specialToken;
    string name;
public:
    Region();
    ~Region();
    string getName();
};

class ForestRegion : public Region{
private:
public:
    ForestRegion();
    ~ForestRegion();
};

class MountainRegion : public Region{
private:
    
public:
    MountainRegion();
    ~MountainRegion();
};

class SwampRegion : public Region{
private:
    
public:
    SwampRegion();
    ~SwampRegion();
};

class SeaRegion : public Region{
private:
    
public:
    SeaRegion();
    ~SeaRegion();
};

class FarmRegion : public Region{
private:
    
public:
    FarmRegion();
    ~FarmRegion();
};

class HillRegion : public Region{
private:
    
public:
    HillRegion();
    ~HillRegion();
};

#endif /* Region_hpp */
