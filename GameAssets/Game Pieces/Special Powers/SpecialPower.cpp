#include "SpecialPower.hpp"

using namespace std;

int SpecialPower::getTokenAmount() {
    return armyTokenAmount;
}

string SpecialPower::getName() {
    return name;
}

Alchemist::Alchemist(){
    this->armyTokenAmount = 4;
    this->name = "Alchemist";
}

Alchemist::~Alchemist(){
    
}

void Alchemist::specialAbility() {
    cout << "Collect 2 bonus Victory coins at the end of each turn your race hasn't yet gone into Decline." << endl;
}

Berzerk::Berzerk() {
    this->armyTokenAmount = 4;
    this->name = "Berzerk";
}

Berzerk::~Berzerk() {
    
}

void Berzerk::specialAbility() {
    cout << "You may use the Reinforcement die before each of your conquests, rather than just the last one of your turn. Roll the die first; select the Region you wish to conquer; then place the required number of Race tokens (minus the die results) there. If you do not have enough tokens left, this is your final conquest attempt for the turn. As usual, a minimum of 1 token is still required to attempt the conquest." << endl;
}

Bivouacking::Bivouacking() {
    this->armyTokenAmount = 5;
    this->name = "Bivouacking";
}

Bivouacking::~Bivouacking(){
    
}
void Bivouacking::specialAbility() {
    cout << "Deploy the 5 Encampment tokens in any of your Region(s), during your Troop Redeployment phase. Each Encampment counts as 1 Race token toward the defense of the Region in which it is placed (thereby protecting a single Race token with an Encampment from the Sorcerer's Racial Power). Multiple Encampments may be placed in the same Region to obtain a higher defense bonus. Each turn you may break camp and settle in any new Region you occupy. Encampments are never lost during an attack on the Region they are in: they are redeployed at the end of the current player's turn. When the Race they were associated with goes into Decline, they disappear." << endl;
}

Commando::Commando() {
    this->armyTokenAmount = 4;
    this->name = "Commando";
}

Commando::~Commando() {
    
}
    
void Commando::specialAbility() {
    cout << "You may conquer any Region with 1 less Race token than normal. A minimum of 1 token is still required." << endl;
}

Diplomat::Diplomat() {
    this->armyTokenAmount = 5;
    this->name = "Diplomat";
}

Diplomat::~Diplomat() {
    
}
    
void Diplomat::specialAbility() {
    cout << "At the end of your turn, you may select one opponent whose Active race you did not attack this turn as your ally. You are now at peace with him and he cannot attack your active race until your next turn. You may change allies each turn, or stay at peace with the same opponent. Tokens In Decline are not impacted (so Ghouls In Decline are immune to this power and may still attack you)." << endl;
}

DragonMaster::DragonMaster() {
    this->armyTokenAmount = 5;
    this->name = "DragonMaster";
}

DragonMaster::~DragonMaster() {
    
}
    
void DragonMaster::specialAbility() {
    cout << "Once per turn, you may conquer a Region using a single Race token, regardless of the number of enemy tokens defending it. Once conquered, place your Dragon there. The Region is now immune to enemy conquests as well as to their racial and special powers until your Dragon moves. During each new turn, you may move your Dragon to a different Region you wish to conquer. Your Dragon disappears when you go into Decline; remove it from the board and place it back in the storage tray at that time. " << endl;
}

Flying::Flying() {
    this->armyTokenAmount = 5;
    this->name = "Flying";
}

Flying::~Flying() {
    
}
    
void Flying::specialAbility() {
    cout << "You may conquer any Region of the map except Seas and Lakes. These Regions do not need to be adjacent or contiguous to ones you already occupy" << endl;
}

ForestPower::ForestPower() {
    this->armyTokenAmount = 4;
    this->name = "Forest";
}

ForestPower::~ForestPower() {
    
}
    
void ForestPower::specialAbility() {
    cout << "Collect 1 bonus Victory coin for each Forest Region you occupy at turn's end." << endl;
}

Fortified::Fortified() {
    this->armyTokenAmount = 3;
    this->name = "Fortified";
}

Fortified::~Fortified() {
    
}
    
void Fortified::specialAbility() {
    cout << "Once per turn, as long as your Fortified Race is active, you may place 1 Fortress in a Region you occupy. The Fortress is worth 1 bonus Victory coin at turn's end, unless you are In Decline. The Fortress also augments your Region's defense by 1 (just as if you had an additional Race token stationed there), even if you are In Decline. Remove the Fortress if you abandon the Region or when an enemy conquers it. There can only ever be a maximum of 1 Fortress per Region, and a maximum of 6 Fortresses on the map." << endl;
}

Heroic::Heroic() {
    this->armyTokenAmount = 5;
    this->name = "Heroic";
}

Heroic::~Heroic() {
    
}

void Heroic::specialAbility() {
    cout << "At the end of your turn, place each of your 2 Heroes in 2 different Regions you occupy. These 2 Regions are immune to enemy conquests as well as to their racial and special powers until your Heroes move. Your Heroes disappear when you go into Decline." << endl;
}
    
HillPower::HillPower() {
    this->armyTokenAmount = 4;
    this->name = "Hill";
}

HillPower::~HillPower() {
    
}
    
void HillPower::specialAbility() {
    cout << "Collect 1 bonus Victory coin for each Hill Region you occupy at turn's end." << endl;
}

Merchant::Merchant() {
    this->armyTokenAmount = 2;
    this->name = "Merchant";
}

Merchant::~Merchant() {
    
}

void Merchant::specialAbility() {
    cout << "Collect 1 bonus Victory coin for any Region you occupy at turn's end." << endl;
}
    
Mounted::Mounted() {
    this->armyTokenAmount = 5;
    this->name = "Mounted";
}

Mounted::~Mounted() {
    
}
    
void Mounted::specialAbility() {
    cout << "You may conquer any Hill or Farmland Region with 1 less Race token than normal. A minimum of 1 token is still required." << endl;
}

Pillaging::Pillaging() {
    this->armyTokenAmount = 5;
    this->name = "Pillaging";
}

Pillaging::~Pillaging() {
    
}
    
void Pillaging::specialAbility() {
    cout << "Each non-empty Region you conquer this turn is worth 1 bonus Victory coin at turn's end." << endl;
}

Seafaring::Seafaring() {
    this->armyTokenAmount = 5;
    this->name = "Seafaring";
}

Seafaring::~Seafaring() {
    
}
    
void Seafaring::specialAbility() {
    cout << "As long as your Seafaring race is active, you may conquer the Seas and the Lake, considering them as 3 empty Regions. You keep these Regions even once you go into Decline, and continue scoring for them for as long as you have tokens there. Only Seafaring races may occupy the Seas and the Lake." << endl;
}

Spirit::Spirit() {
    this->armyTokenAmount = 5;
    this->name = "Spirit";
}

Spirit::~Spirit() {
    
}
    
void Spirit::specialAbility() {
    cout << "When the Race tokens associated with your Spirit Special Power go into Decline, they never count toward the limit stated in Entering In Decline (p. 6) regarding having a single In Decline race on the map at any given time. You may thus end up with two different races In Decline on the map at the same time and score for them both. If a third race you control goes into Decline, your Spirits remain on the board, although the other race already In Decline disappears, as normal. In other words, your In Decline Spirits never leave the map (except when taking losses from opponents' conquests), though other races sent In Decline may go away when a new race goes into decline." << endl;
}

Stout::Stout() {
    this->armyTokenAmount = 4;
    this->name = "Stout";
}

Stout::~Stout() {
    
}
    
void Stout::specialAbility() {
    cout << "You may go In Decline at the end of a regular turn of conquests, after scoring, instead of spending an entire turn going into Decline." << endl;
}

SwampPower::SwampPower() {
    this->armyTokenAmount = 4;
    this->name = "Swamp";
}

SwampPower::~SwampPower() {
    
}
    
void SwampPower::specialAbility() {
    cout << "Collect 1 bonus Victory coin for each Swamp Region you occupy at turn's end." << endl;
}

Underworld::Underworld() {
    this->armyTokenAmount = 5;
    this->name = "Underworld";
}

Underworld::~Underworld() {
    
}
    
void Underworld::specialAbility() {
    cout << "You may conquer any Region with a Cavern with 1 less Race token than normal. A minimum of 1 token is still required. All Regions with a Cavern are also considered adjacent to each other for your conquest purposes." << endl;
}

Wealthy::Wealthy() {
    this->armyTokenAmount = 4;
    this->name = "Wealthy";
}

Wealthy::~Wealthy() {
    
}
    
void Wealthy::specialAbility() {
    cout << "Collect 7 bonus Victory coins, once only, at the end of your first turn." << endl;
}

BlankAbility::BlankAbility() {
    this->name = "Blank Ability";
}

BlankAbility::~BlankAbility() {
    
}

void BlankAbility::specialAbility() {
    cout << "No ability" << endl;
}
