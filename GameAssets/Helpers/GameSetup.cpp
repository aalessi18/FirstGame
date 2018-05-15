#include "GameSetup.hpp"

GameSetup::GameSetup(){
    
}

GameSetup::~GameSetup(){
    
}

Map GameSetup::setUpGame(Map map, int numberOfPlayers, vector<Race*>& races, vector<SpecialPower*>& specialPowers, vector<Token*>& tokens){
    Player* temp = new Player; // Delete within the node whenever we take over LostTribes, BUT WILL IT DELETE ALL OF THEM??
    LostTribes lostTribes;
    temp->setName(lostTribes.getName());
 
    
    switch(numberOfPlayers)
    {
        case 2:
            map.getGraph()[3].setPlayer(temp);
            map.getGraph()[3].setAmountOfRaceTokens(1);
            map.getGraph()[6].setPlayer(temp);
            map.getGraph()[6].setAmountOfRaceTokens(1);
            map.getGraph()[10].setPlayer(temp);
            map.getGraph()[10].setAmountOfRaceTokens(1);
            map.getGraph()[11].setPlayer(temp);
            map.getGraph()[11].setAmountOfRaceTokens(1);
            map.getGraph()[12].setPlayer(temp);
            map.getGraph()[12].setAmountOfRaceTokens(1);
            map.getGraph()[13].setPlayer(temp);
            map.getGraph()[13].setAmountOfRaceTokens(1);
            map.getGraph()[14].setPlayer(temp);
            map.getGraph()[14].setAmountOfRaceTokens(1);
            map.getGraph()[16].setPlayer(temp);
            map.getGraph()[16].setAmountOfRaceTokens(1);
            map.getGraph()[18].setPlayer(temp);
            map.getGraph()[18].setAmountOfRaceTokens(1);
            break;
        case 3:
            map.getGraph()[5].setPlayer(temp);
            map.getGraph()[5].setAmountOfRaceTokens(1);
            map.getGraph()[6].setPlayer(temp);
            map.getGraph()[6].setAmountOfRaceTokens(1);
            map.getGraph()[8].setPlayer(temp);
            map.getGraph()[8].setAmountOfRaceTokens(1);
            map.getGraph()[10].setPlayer(temp);
            map.getGraph()[10].setAmountOfRaceTokens(1);
            map.getGraph()[13].setPlayer(temp);
            map.getGraph()[13].setAmountOfRaceTokens(1);
            map.getGraph()[19].setPlayer(temp);
            map.getGraph()[19].setAmountOfRaceTokens(1);
            map.getGraph()[21].setPlayer(temp);
            map.getGraph()[21].setAmountOfRaceTokens(1);
            map.getGraph()[22].setPlayer(temp);
            map.getGraph()[22].setAmountOfRaceTokens(1);
            map.getGraph()[23].setPlayer(temp);
            map.getGraph()[23].setAmountOfRaceTokens(1);
            map.getGraph()[28].setPlayer(temp);
            map.getGraph()[28].setAmountOfRaceTokens(1);
            break;
        case 4:
            map.getGraph()[2].setPlayer(temp);
            map.getGraph()[2].setAmountOfRaceTokens(1);
            map.getGraph()[3].setPlayer(temp);
            map.getGraph()[3].setAmountOfRaceTokens(1);
            map.getGraph()[4].setPlayer(temp);
            map.getGraph()[4].setAmountOfRaceTokens(1);
            map.getGraph()[6].setPlayer(temp);
            map.getGraph()[6].setAmountOfRaceTokens(1);
            map.getGraph()[7].setPlayer(temp);
            map.getGraph()[7].setAmountOfRaceTokens(1);
            map.getGraph()[12].setPlayer(temp);
            map.getGraph()[12].setAmountOfRaceTokens(1);
            map.getGraph()[15].setPlayer(temp);
            map.getGraph()[15].setAmountOfRaceTokens(1);
            map.getGraph()[22].setPlayer(temp);
            map.getGraph()[22].setAmountOfRaceTokens(1);
            map.getGraph()[23].setPlayer(temp);
            map.getGraph()[23].setAmountOfRaceTokens(1);
            map.getGraph()[25].setPlayer(temp);
            map.getGraph()[25].setAmountOfRaceTokens(1);
            map.getGraph()[26].setPlayer(temp);
            map.getGraph()[26].setAmountOfRaceTokens(1);
            map.getGraph()[27].setPlayer(temp);
            map.getGraph()[27].setAmountOfRaceTokens(1);
            map.getGraph()[31].setPlayer(temp);
            map.getGraph()[31].setAmountOfRaceTokens(1);
            map.getGraph()[33].setPlayer(temp);
            map.getGraph()[33].setAmountOfRaceTokens(1);
            break;
         case 5:
            map.getGraph()[5].setPlayer(temp);
            map.getGraph()[5].setAmountOfRaceTokens(1);
            map.getGraph()[7].setPlayer(temp);
            map.getGraph()[7].setAmountOfRaceTokens(1);
            map.getGraph()[11].setPlayer(temp);
            map.getGraph()[11].setAmountOfRaceTokens(1);
            map.getGraph()[12].setPlayer(temp);
            map.getGraph()[12].setAmountOfRaceTokens(1);
            map.getGraph()[14].setPlayer(temp);
            map.getGraph()[14].setAmountOfRaceTokens(1);
            map.getGraph()[16].setPlayer(temp);
            map.getGraph()[16].setAmountOfRaceTokens(1);
            map.getGraph()[18].setPlayer(temp);
            map.getGraph()[18].setAmountOfRaceTokens(1);
            map.getGraph()[23].setPlayer(temp);
            map.getGraph()[23].setAmountOfRaceTokens(1);
            map.getGraph()[25].setPlayer(temp);
            map.getGraph()[25].setAmountOfRaceTokens(1);
            map.getGraph()[29].setPlayer(temp);
            map.getGraph()[29].setAmountOfRaceTokens(1);
            map.getGraph()[31].setPlayer(temp);
            map.getGraph()[31].setAmountOfRaceTokens(1);
            map.getGraph()[34].setPlayer(temp);
            map.getGraph()[34].setAmountOfRaceTokens(1);
            map.getGraph()[35].setPlayer(temp);
            map.getGraph()[35].setAmountOfRaceTokens(1);
            map.getGraph()[36].setPlayer(temp);
            map.getGraph()[36].setAmountOfRaceTokens(1);
            map.getGraph()[37].setPlayer(temp);
            map.getGraph()[37].setAmountOfRaceTokens(1);
            map.getGraph()[38].setPlayer(temp);
            map.getGraph()[38].setAmountOfRaceTokens(1);
            map.getGraph()[39].setPlayer(temp);
            map.getGraph()[39].setAmountOfRaceTokens(1);
            map.getGraph()[42].setPlayer(temp);
            map.getGraph()[42].setAmountOfRaceTokens(1);
            break;
    }
    races.push_back(new Amazons);
    races.push_back(new Dwarves);
    races.push_back(new Elves);
    races.push_back(new Ghouls);
    races.push_back(new Giants);
    races.push_back(new Halflings);
    races.push_back(new Humans);
    races.push_back(new Orcs);
    races.push_back(new Ratmen);
    races.push_back(new Skeletons);
    races.push_back(new Sorcerers);
    races.push_back(new Tritons);
    races.push_back(new Trolls);
    races.push_back(new Wizards);
     
    specialPowers.push_back(new Alchemist);
    specialPowers.push_back(new Berzerk);
    specialPowers.push_back(new Bivouacking);
    specialPowers.push_back(new Commando);
    specialPowers.push_back(new Diplomat);
    specialPowers.push_back(new DragonMaster);
    specialPowers.push_back(new Flying);
    specialPowers.push_back(new ForestPower);
    specialPowers.push_back(new Fortified);
    specialPowers.push_back(new Heroic);
    specialPowers.push_back(new HillPower);
    specialPowers.push_back(new Merchant);
    specialPowers.push_back(new Mounted);
    specialPowers.push_back(new Pillaging);
    specialPowers.push_back(new Seafaring);
    specialPowers.push_back(new Spirit);
    specialPowers.push_back(new Stout);
    specialPowers.push_back(new SwampPower);
    specialPowers.push_back(new Underworld);
    specialPowers.push_back(new SwampPower);
     
    tokens.push_back(new TrollLair);
    tokens.push_back(new Fortress);
    tokens.push_back(new MountainToken); // DO we need this or do we simply delete them within the nodes at the end
    tokens.push_back(new Encampment);
    tokens.push_back(new HolesInTheGround);
    tokens.push_back(new Heroes);
    tokens.push_back(new Dragon);
    
    return map;
}
