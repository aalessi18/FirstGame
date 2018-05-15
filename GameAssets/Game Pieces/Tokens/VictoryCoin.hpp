#ifndef VictoryCoins_hpp
#define VictoryCoins_hpp

#include <iostream>
#include <vector>
//#include "VictoryCoinAssist.hpp"

using namespace std;

// This class holds all the different denominations of victory points

class VictoryCoin {
private:
    const int ONE = 1;
    const int THREE = 3;
    const int FIVE = 5;
    const int TEN = 10;
    const int MAX_ONES = 35;
    const int MAX_THREES = 20;
    const int MAX_FIVES = 24;
    const int MAX_TENS = 30;
    vector<int> victoryCoinStack;
public:
    VictoryCoin();
    VictoryCoin(int numberOfPlayers);
    ~VictoryCoin();
    void addToVictoryCoins(int amountOfCoins, vector<int> &userVictoryCoins);
    void exchangeVictoryCoins(vector<int> &userVictoryCoins);
    void removeFromVictoryCoins(int amountOfCoins, vector<int> &userVictoryCoins);
    vector<int> calculateAmountOfCoins(int amountOfCoins);
};

#endif /* VictoryCoins_hpp */
