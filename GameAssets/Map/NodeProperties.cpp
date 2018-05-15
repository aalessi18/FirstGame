#include "NodeProperties.hpp"

NodeProperties::NodeProperties() {
    this->index = 0;
    this->amountOfRaceTokens = 0;
    this->player = NULL;
    this->race = NULL;
    this->specialTrait = "";
    this->outsideEdge = false;
}

NodeProperties::NodeProperties(int index, int amountOfRaceTokens, Region &region, Player &player, Race &race, string specialTrait, vector<Token*> specialTokens, bool outsideEdge)
{
    this->index = index;
    this->amountOfRaceTokens = amountOfRaceTokens;
    this->region = &region;
    this->player = &player;
    this->race = &race;
    this->specialTrait = specialTrait;
    this->specialTokens = specialTokens;
    this->outsideEdge = outsideEdge;
}

NodeProperties::~NodeProperties(){
}

void NodeProperties::setIndex(int index) {
    this->index = index;
}

int NodeProperties::getIndex(){
    return index;
}

void NodeProperties::setRegion(Region* region) {
    this->region = region;
}

Region* NodeProperties::getRegion() {
    return this->region;
}

string NodeProperties::getRegionName(){
    return region->getName();
}

void NodeProperties::setRace(Race* race){
    this->race = race;
}

Race* NodeProperties::getRace(){
    return this->race;
}

void NodeProperties::setAmountOfRaceTokens(int amountOfRaceTokens) {
    this->amountOfRaceTokens = amountOfRaceTokens;
}

int NodeProperties::getAmountOfRaceTokens() {
    return this->amountOfRaceTokens;
}

void NodeProperties::setPlayer(Player* player) {
    this->player = player;
}

Player* NodeProperties::getPlayer() {
    return player;
}

void NodeProperties::setSpecialTrait(string specialTrait) {
    this->specialTrait = specialTrait;
}

string NodeProperties::getSpecialTrait() {
    return specialTrait;
}

void NodeProperties::setSpecialToken(Token* specialToken) {
    this->specialTokens.push_back(specialToken);
}
vector<Token*> NodeProperties::getSpecialTokens() {
    return specialTokens;
}

bool NodeProperties::isOutsideEdge() {
    return outsideEdge;
}

void NodeProperties::setOutsideEdge(bool isOutsideEdge) {
    this->outsideEdge = isOutsideEdge;
}

void NodeProperties::setAdjacentRegionsIndex(int regionIndex){
    this->adjacentRegionsIndex.push_back(regionIndex);
}

vector<int> NodeProperties::getAdjacentRegionsIndex() {
    return adjacentRegionsIndex;
}

void NodeProperties::printContents(){ 
    
    if(player == NULL)
    {
        cout << "Vertex at index #" << index << " belongs to no player, is a " << region->getName()
        << " region with " << specialTrait << " and holds the following special tokens: " << endl;
        
        for(int i=0;i<specialTokens.size();i++)
        {
            cout << specialTokens.at(i)->getName() << endl;
        }
        if(isOutsideEdge()==true && getRegionName()!= "Sea")
            cout << "This region is an outside edge accessible for first turns." << endl;
    }
    else
    {
        cout << "Vertex at index #" << index << " belongs to " << player->getName() << ", is a " << region->getName()
        << " region with " << specialTrait << " and holds the following special tokens: " <<endl;
        for(int i=0;i<specialTokens.size();i++)
        {
            cout << specialTokens.at(i)->getName() << endl;
        }
        if(isOutsideEdge()==true && getRegionName()!= "Sea")
            cout << "This region is an outside edge accessible for first turns." << endl;
    }
    this->printAdjacentContents(true);
}

// If true, then we print with sea regions, else without
void NodeProperties::printAdjacentContents(bool withSea) {
    cout << "Adjacent regions: " << endl;
    for(int i=0;i<this->adjacentRegionsIndex.size();i++)
    {
        cout << "Region: " << this->adjacentRegionsIndex.at(i) << " ";
    }
    cout << endl;
}
