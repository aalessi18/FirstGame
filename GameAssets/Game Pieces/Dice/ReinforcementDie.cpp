#include "ReinforcementDie.hpp"
#include <iostream>

using namespace std;

ReinforcementDie::ReinforcementDie() {
    this->countTotal = 0;
}
ReinforcementDie::~ReinforcementDie(){
}

void ReinforcementDie::setCountValues(int diceAmount) {
    switch(diceAmount)
    {
        case 0:
            countValues[0]+= 1;
            break;
        case 1:
            countValues[1]+= 1;
            break;
        case 2:
            countValues[2]+= 1;
            break;
        case 3:
            countValues[3]+= 1;
            break;
    }
}

int ReinforcementDie::rollDice(){
    int diceRoll;
    diceRoll = rand()%6;
    
    if(diceRoll==4 || diceRoll==5 || diceRoll==6)
    {
        diceRoll = 0;
        cout << "Dice Roll: " << diceRoll << endl;
        setCountValues(diceRoll);
        countTotal+= 1;
    }
    else
    {
        cout << "Dice Roll: " << diceRoll << endl;
        setCountValues(diceRoll);
        countTotal+= 1;
    }
    return diceRoll;
}

void ReinforcementDie::computePercentage() {
    double zero,one,two,three;
    zero = (double)countValues[0]/(double)countTotal;
    one = (double)countValues[1]/(double)countTotal;
    two = (double)countValues[2]/(double)countTotal;
    three = (double)countValues[3]/(double)countTotal;
    
    printf("0 appeared = %.2f %s of the time.\n", (zero*100),"%");
    printf("1 appeared = %.2f %s of the time.\n", (one*100),"%");
    printf("2 appeared = %.2f %s of the time.\n", (two*100),"%");
    printf("3 appeared = %.2f %s of the time.\n", (three*100),"%");
    cout << "A total of " << countTotal << " dice rolls have been performed. " << endl;
}
