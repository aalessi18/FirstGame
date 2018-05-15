#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player() {
    this->victoryCoins.reserve(4);
    this->victoryCoins.push_back(0);
    this->victoryCoins.push_back(0);
    this->victoryCoins.push_back(0);
    this->victoryCoins.push_back(5); // location 3, is for the value of 1
    this->amountOfRaceTokens = 0;
    this->firstTurn = true;
    this->name = "";
    this->activeRace = NULL;
    this->specialPower = NULL;
    this->amountOfRaceTokens = 0;
}

Player::Player(string name, Race* activeRace, SpecialPower* specialPower){
    this->victoryCoins.reserve(4);
    this->victoryCoins.push_back(0);
    this->victoryCoins.push_back(0);
    this->victoryCoins.push_back(0);
    this->victoryCoins.push_back(5); // location 3, is for the value of 1
    this->firstTurn = true;
    this->name = name;
    this->activeRace = activeRace;
    this->specialPower = specialPower;
    this->amountOfRaceTokens = (activeRace->getTokenAmount() + specialPower->getTokenAmount());
}

Player::~Player(){
}

void Player::picks_race(Race* activeRace){
    this->activeRace = activeRace;
}

Race* Player::getActiveRace() {
    return activeRace;
}


void Player::conquers(int regionToConquer, int amountOfRaceTokens){
    cout << "Conquering index " << regionToConquer << " with " << amountOfRaceTokens << " army tokens." << endl;
    removeAmountOfRaceTokens(amountOfRaceTokens);
    setRegionsControlled(regionToConquer);
}

int Player::score(){
    regionsControlled.shrink_to_fit();
    int temp = 0;
    
    temp += victoryCoins.at(0)*10;
    temp += victoryCoins.at(1)*5;
    temp += victoryCoins.at(2)*3;
    temp += victoryCoins.at(3)*1;
    
    return regionsControlled.size(); // This will have to change as the game integrates the other aspects as well
}

void Player::setDeclinedRace(){ // Possibly change, not sure if this will work properly
    this->declinedRaces.push_back(activeRace);
}

vector<Race*>& Player::getDeclinedRace() {
    return declinedRaces;
}

void Player::setSpecialPower(SpecialPower* specialPower){
    this->specialPower = specialPower;
    
}

SpecialPower* Player::getSpecialPower(){
    return specialPower;
}

vector<int> &Player::getVictoryCoins() {
    return this->victoryCoins;
}

void Player::troopRedeployment() {
    
}

void Player::setName(string name) {
    this->name = name;
}

string Player::getName() {
    return name;
}

void Player::setAmountOfRaceTokens(int amountOfRaceTokens, int specialAbilityTokens){
    this->amountOfRaceTokens = amountOfRaceTokens + specialAbilityTokens;
}

void Player::addAmountOfRaceTokens(int amountOfRaceTokens) {
    this->amountOfRaceTokens += amountOfRaceTokens;
}

void Player::removeAmountOfRaceTokens(int amountOfRaceTokens) {
    this->amountOfRaceTokens -= amountOfRaceTokens;
}

int Player::getAmountOfRaceTokens() {
    return amountOfRaceTokens;
}

void Player::setPlayerNumber(int playerNumber){
    this->playerNumber = playerNumber;
}

int Player::getPlayerNumber() const{
    return playerNumber;
}

bool Player::isFirstTurn() {
    return firstTurn;
}

void Player::setFirstTurn(bool firstTurn) {
    this->firstTurn = firstTurn;
}
void Player::addAmountOfRegionsControlled(int amountOfRegionsControlled){
    this->amountOfRegionsControlled += amountOfRegionsControlled;
}

void Player::removeAmountOfRegionsControlled(int amountOfRegionsControlled){
    this->amountOfRegionsControlled -= amountOfRegionsControlled;
}

int Player::getAmountOfRegionsControlled(){
    return this->amountOfRegionsControlled;
}

void Player::setRegionsControlled(int region) {
    this->regionsControlled.push_back(region);

    Notify(); // After losing or gaining
}

vector<int>& Player::getRegionsControlled(){
    return this->regionsControlled;
}

void Player::printVictoryPoints() {
    int temp = 0;
    temp += (this->getVictoryCoins().at(0)*10);
    temp += (this->getVictoryCoins().at(1)*5);
    temp += (this->getVictoryCoins().at(2)*3);
    temp += (this->getVictoryCoins().at(3)*1);
    cout << this->getName() << " has " << temp << " victory points" << endl;
}

ReinforcementDie Player::getDice(){
    cout << "Rolling dice: " << endl;
    return dice;
}

void Player::setStrategy(Strategy* strategy) {
    this->strategy = strategy;
}

Strategy* Player::getStrategy() {
    return strategy;
}

void Player::enterDecline() {
    // Will need condition with if the user has spirit or not, and when user goes into decline again (test if not empty basically)
    Race* temp = this->activeRace;
    this->activeRace = NULL;
    this->specialPower = NULL;
    if(declinedRaces.size()==0)
    {
        this->declinedRaces.push_back(temp);
        this->declinedRaces.at(0)->raceDeclined();
    }
    else
    {
        this->declinedRaces.at(0) = temp;
        this->declinedRaces.at(0)->raceDeclined();
    }
}

int Player::getIndexOfRegionControlled(int regionControlled) {
    for(int i=0;i<regionsControlled.size();i++)
    {
        if(regionControlled == this->regionsControlled.at(i))
        {
            return i;
        }
    }
    cout << "Value not found" << endl;
    return -1;
}
