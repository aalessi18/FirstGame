#ifndef SummarySheets_hpp
#define SummarySheets_hpp

#include <iostream>

// This class will hold all the brief information of every race, special power, region, as well as, what a player can do every turn

using namespace std;

class SummarySheets {
private:
    string rules;
    string name;
public:
    SummarySheets();
    ~SummarySheets();
    string getRules();
    string getName();
    //All the races
    //All the special abilities
};

#endif /* SummarySheets_hpp */
