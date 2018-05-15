#ifndef NodeProperties_hpp
#define NodeProperties_hpp

#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Race.hpp"
#include "Tokens.hpp"
#include "Region.hpp"
#include "EdgeProperties.hpp"

using namespace std;

/* This class holds all the information that can be store within a vertex of the map for the game */

class NodeProperties {
private:
    int index, amountOfRaceTokens;
    Region* region;
    Player* player;
    Race* race;
    string specialTrait;
    // There can be several specialTokens on the node
    vector<Token*> specialTokens;
    // In order to know if the vector is an outside edge for "first turn" purposes
    bool outsideEdge;
    vector<int> adjacentRegionsIndex;
public:
    NodeProperties();
    NodeProperties(int index, int amountOfRaceTokens, Region &region, Player &player, Race &race, string specialTrait, vector<Token*> specialTokens, bool outsideEdge);
    ~NodeProperties();
    void setIndex(int index);
    int getIndex();
    void setRegion(Region* region);
    Region* getRegion();
    string getRegionName();
    void setRace(Race* race);
    Race* getRace();
    void setAmountOfRaceTokens(int amountOfRaceTokens);
    int getAmountOfRaceTokens();
    void setPlayer(Player* player);
    Player* getPlayer();
    void setSpecialTrait(string specialTrait);
    string getSpecialTrait();
    void setSpecialToken(Token* specialToken);
    vector<Token*> getSpecialTokens();
    bool isOutsideEdge();
    void setOutsideEdge(bool isOutsideEdge);
    void setAdjacentRegionsIndex(int regionIndex);
    vector<int> getAdjacentRegionsIndex();
    void printContents();
    void printAdjacentContents(bool withSea);
};

#endif /* NodeProperties_hpp */
