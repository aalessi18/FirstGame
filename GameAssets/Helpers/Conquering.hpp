#ifndef CONQUERING_HPP_
#define CONQUERING_HPP_

#include "Player.hpp"
#include "Map.hpp"
#include "TroopRedeployment.hpp"
#include <boost/algorithm/string/predicate.hpp>

// Class which assists player's conquer method in order to have access to the map content since the player object cannot see the map object

class Conquering { 
private:
    int raceTokensOnNode;
    int playerCurrentRaceTokens;
    int regionToConquer;
    int raceTokensRequired;
    Map *map;
    Player *player;
public:
    Conquering();
    Conquering(Map &map, Player &player);
    ~Conquering();
    int calculateAmountOfTokens();
    int getAmountOfAvailableTokens();
    void assistConquer();
};

#endif
