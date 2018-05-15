#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <vector>
#include "Race.hpp"
#include "SpecialPower.hpp"
#include "ReinforcementDie.hpp"
#include "VictoryCoin.hpp"
#include "Subject.hpp"
#include "Strategy.hpp"
#include <algorithm> // for random device and mt19937
#include <random> // for random device and mt19937

/* This is the player class. It is a subject to the GameStatisticsObserver */

class Player : public Subject {
private:
    string name;
    Race* activeRace;
    vector<Race*> declinedRaces;
    SpecialPower* specialPower;
    int amountOfRaceTokens;
    int playerNumber;
    int amountOfRegionsControlled;
    bool firstTurn = true;
    vector<int> regionsControlled;
    vector<int> victoryCoins;    // TODO: Use in order to calculate the amount of victory coins the user has
    ReinforcementDie dice;
    Strategy* strategy;
    
public:
    //========Constructor=========//
    Player();
    Player(string name, Race* activeRace, SpecialPower* specialPower);
    
    //========Destructor=========//
    ~Player();
    
    //========Methods=========//
    void picks_race(Race* activeRace);
    Race* getActiveRace();
    void conquers(int regionToConquer, int amountOfRaceTokens); 
    int score();
    void setDeclinedRace();
    vector<Race*>& getDeclinedRace();
    void setSpecialPower(SpecialPower* specialPower);
    SpecialPower* getSpecialPower();
    void addVictoryCoins(int victoryPoints);
    vector<int>& getVictoryCoins();
    void troopRedeployment();
    void setName(string name);
    string getName();
    // Method to set amount of army tokens assigned on first turn
    void setAmountOfRaceTokens(int amountOfRaceTokens, int specialAbilityTokens);
    void addAmountOfRaceTokens(int amountOfRaceTokens);
    void removeAmountOfRaceTokens(int amountOfRaceTokens);
    int getAmountOfRaceTokens();
    //Method to set which player will start
    void setPlayerNumber(int playerNumber);
    int getPlayerNumber() const;
    void addAmountOfRegionsControlled(int amountOfRegionsControlled);
    void removeAmountOfRegionsControlled(int amountOfRegionsControlled);
    int getAmountOfRegionsControlled();
    bool isFirstTurn();
    void setFirstTurn(bool firstTurn);
    void setRegionsControlled(int region);
    vector<int>& getRegionsControlled();
    ReinforcementDie getDice();
    void printVictoryPoints();
    void setStrategy(Strategy* strategy);
    Strategy* getStrategy();
    void enterDecline();
    int getIndexOfRegionControlled(int regionControlled);
};

#endif /* Player_hpp */
