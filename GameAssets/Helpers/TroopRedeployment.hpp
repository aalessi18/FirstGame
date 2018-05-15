#ifndef TroopRedeployment_hpp
#define TroopRedeployment_hpp

#include "Map.hpp"
#include "Player.hpp"

using namespace std;

// Class to assist with reployment. Player needs to see the map in order to be able to redeploy

class TroopRedeployment {
private:
    Player* player;
    Map* map;
public:
    TroopRedeployment();
    TroopRedeployment(Map &map, Player &player);
    ~TroopRedeployment();
    void assistTroopRedeployment();
};

#endif /* TroopRedeployment_hpp */
