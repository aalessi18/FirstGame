#ifndef ReinforcementDie_hpp
#define ReinforcementDie_hpp

#include <iostream>
#include <cstdlib>

using namespace std;

// Class for the reinforcement die used in the game

class ReinforcementDie {
private:
    //Array to hold the percentages of each die side
    int countValues[4] = {0,0,0,0};
    int countTotal;
    void setCountValues(int diceAmount);
public:
    ReinforcementDie();
    ~ReinforcementDie();
    // Method to roll the dice and get a value between 0,1,2,3
    int rollDice();
    // Method which shows the percentage of how many of each number has come out throughout the game
    void computePercentage();
};

#endif /* ReinforcementDie_hpp */

/*
 If the sum of the die rolled, combined with the Race token(s)
 left in his possession, is high enough to conquer the Region, the
 player deploys his remaining Race token(s) there. Otherwise, he
 deploys his remaining token(s) in one of the Regions he already
 occupied prior. Either way, his conquests for the turn end
 immediately thereafter.
 
 Can only be used as the last conquest of your turn (unless you have a special ability)
 */
