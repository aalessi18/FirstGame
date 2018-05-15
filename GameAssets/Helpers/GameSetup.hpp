#ifndef GAMESETUP_HPP_
#define GAMESETUP_HPP_

#include "Map.hpp"
#include "Race.hpp"
#include "SpecialPower.hpp"
#include "Tokens.hpp"

using namespace std;

class GameSetup {
private:
    
public:
    GameSetup();
    ~GameSetup();
    Map setUpGame(Map map, int numberOfPlayers, vector<Race*> &races, vector<SpecialPower*> &specialPowers, vector<Token*> &tokens);
};

#endif
