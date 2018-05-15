#include "VictoryCoin.hpp"

VictoryCoin::VictoryCoin(){
    this->victoryCoinStack.reserve(4);
    this->victoryCoinStack.push_back(30); // Amount of tens
    this->victoryCoinStack.push_back(24); // Amount of fives
    this->victoryCoinStack.push_back(20); // Amount of threes
    this->victoryCoinStack.push_back(35); // Amount of ones
}

VictoryCoin::VictoryCoin(int numberOfPlayers) {
    this->victoryCoinStack.reserve(4);
    this->victoryCoinStack.push_back(30); // Amount of tens
    this->victoryCoinStack.push_back(24); // Amount of fives
    this->victoryCoinStack.push_back(20); // Amount of threes
    this->victoryCoinStack.push_back(35); // Amount of ones
    this->victoryCoinStack.at(3) = (this->victoryCoinStack.at(3)-(numberOfPlayers*5));
}

VictoryCoin::~VictoryCoin(){
    
}

void VictoryCoin::addToVictoryCoins(int amountOfCoins, vector<int> &userVictoryCoins) {
    vector<int> temp = calculateAmountOfCoins(amountOfCoins);
    // Add to the stack of coins
    this->victoryCoinStack.at(0) += temp.at(0);
    this->victoryCoinStack.at(1) += temp.at(1);
    this->victoryCoinStack.at(2) += temp.at(2);
    this->victoryCoinStack.at(3) += temp.at(3);
    // Remove from the stack of the user
    userVictoryCoins.at(0) -= temp.at(0);
    userVictoryCoins.at(1) -= temp.at(1);
    userVictoryCoins.at(2) -= temp.at(2);
    userVictoryCoins.at(3) -= temp.at(3);
}

void VictoryCoin::exchangeVictoryCoins(vector<int> &userVictoryCoins) {
    vector<int> temp;
    temp.reserve(4);
    
    // Converting 1, 3, and 5 from user to as high of a denomination as possible
    for(int i=3;i>0;i--)
    {
        if(userVictoryCoins.at(i)>=TEN && this->victoryCoinStack.at(0)>0)
        {
            userVictoryCoins.at(i) -= TEN; // Removes ones in increments of ten
            userVictoryCoins.at(0) += 1; // Adds a ten to user stack
            this->victoryCoinStack.at(0) -= 1; // Remove a ten from the game stack
            this->victoryCoinStack.at(i) += TEN;
        }
        if(i!=1 && userVictoryCoins.at(i)>=FIVE && userVictoryCoins.at(i)>5 && victoryCoinStack.at(1)>0)
        {
            userVictoryCoins.at(i) -= FIVE;
            userVictoryCoins.at(1) += 1;
            this->victoryCoinStack.at(1) -= 1;
            this->victoryCoinStack.at(i) += FIVE;
        }
        if(i!=2 && userVictoryCoins.at(i)>=THREE && victoryCoinStack.at(2)>0)
        {
            userVictoryCoins.at(i) -= THREE;
            userVictoryCoins.at(2) += 1;
            this->victoryCoinStack.at(2) -= 1;
            this->victoryCoinStack.at(i) += THREE;
        }
    }
}

void VictoryCoin::removeFromVictoryCoins(int amountOfCoins, vector<int> &userVictoryCoins) {
    vector<int> temp = calculateAmountOfCoins(amountOfCoins);
    
    // Remove from the stack of coins
    this->victoryCoinStack.at(0) -= temp.at(0);
    this->victoryCoinStack.at(1) -= temp.at(1);
    this->victoryCoinStack.at(2) -= temp.at(2);
    this->victoryCoinStack.at(3) -= temp.at(3);
    // Add to the stack of the user
    userVictoryCoins.at(0) += temp.at(0);
    userVictoryCoins.at(1) += temp.at(1);
    userVictoryCoins.at(2) += temp.at(2);
    userVictoryCoins.at(3) += temp.at(3);
}

vector<int> VictoryCoin::calculateAmountOfCoins(int amountOfCoins){ // TODO: Calculate the amount of tokens the user needs
    vector<int> temp;
    temp.reserve(4);
    // Initialize temporary vector in case there are zeros in certain index values
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    
    while(amountOfCoins>0)
    {
        /* Possible conditions in each if in order to ensure we do not go beyond the maximum amount of each coins
            This area tests for the amount of each coin we will need to add/remove
         */
        if((amountOfCoins>=TEN)==1 && this->victoryCoinStack.at(0)>0)
        {
            temp.at(0) += amountOfCoins/TEN;
            amountOfCoins = amountOfCoins - ((amountOfCoins/TEN)*TEN);
        }
    
        if((amountOfCoins>=FIVE)==1 && this->victoryCoinStack.at(1)>0)
        {
            temp.at(1) += amountOfCoins/FIVE;
            amountOfCoins = amountOfCoins - ((amountOfCoins/FIVE)*FIVE);
        }
    
        if((amountOfCoins>=THREE)==1 && this->victoryCoinStack.at(2)>0)
        {
            temp.at(2) += amountOfCoins/THREE;
            amountOfCoins = amountOfCoins - ((amountOfCoins/THREE)*THREE);
        }
        
        if((amountOfCoins>=ONE)==1 && this->victoryCoinStack.at(3)>0)
        {
            temp.at(3) += amountOfCoins/ONE;
            amountOfCoins = amountOfCoins - ((amountOfCoins/ONE)*ONE);
        }
    }
    return temp;
}
