#include "Strategy.hpp"

Aggressive::Aggressive() {
    this->strategyType = "Aggressive";
}

Aggressive::~Aggressive() {
    
}

string Aggressive::suggestionForStrategy() {
    return "\n====================================================================\nAs an aggressive player, you want to use up all of your army tokens every turn in order to try to control as much of the map as possible.\nFor race and special power combinations, an example of an offensive combination would be Skeletons with Berzerker. The idea is, to choose a combination that focuses on expansive capabilities.\n====================================================================\n";
}

Defensive::Defensive() {
    this->strategyType = "Defensive";
}

Defensive::~Defensive() {
    
}

string Defensive::suggestionForStrategy() {
    return "\n====================================================================\nAs a Defensive player, you want to take control of only 1 or 2 areas per turn, this way the regions you control will have a bigger defense.\nFor race and special power combinations, an example of a defensive combination would be Halflings with Heroic. The idea is, to choose a combination that focuses on high defensive capabilities\n====================================================================\n";
}

Moderate::Moderate() {
    this->strategyType = "Moderate";
}

Moderate::~Moderate() {
    
}

string Moderate::suggestionForStrategy() {
    return "\n====================================================================\nAs a moderate player, you do not want to use up all of your army tokens every turn, but mix around between expanding and keeping more than just one token on each region you control.\nFor race and special power combinations, an example of a moderate combination would be Amazons with Diplomat. The idea is, to choose a combination that focuses on both some offensive and defensive capabilities.\n====================================================================\n";
}

