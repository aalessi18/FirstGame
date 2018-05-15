#include "Race.hpp"

Race::Race() {
    this->tokenAmount = 0;
}

Race::~Race() {
    
}

void Race::racialAbility() {
    
}

string Race::getName() {
    return name;
}

void Race::addRaceTokens(int raceTokens) {
    this->raceTokens += raceTokens;
}

void Race::removeRaceTokens(int raceTokens) {
    this->raceTokens -= raceTokens;
}

int Race::getTokenAmount() {
    return tokenAmount;
}

int Race::getRaceTokens() {
    return raceTokens;
}

bool Race::raceDeclined() {
    return active;
}

void Race::setRaceDecline() {
    this->active = false;
}

LostTribes::LostTribes() {
    this->name = "Lost Tribes";
    this->raceTokens = 18;
}

LostTribes::~LostTribes(){
    
}

Amazons::Amazons() {
    this->tokenAmount = 6;
    this->name = "Amazons";
    this->raceTokens = 15;
}

Amazons::~Amazons() {
    
}

void Amazons::racialAbility() {
    cout << "Four of your Amazon tokens may only be used for conquest, not for defense, as indicated by the +4 on the banner itself. So you start your initial turn with 10 Amazon tokens (plus any additional ones that may be granted to you by the Special Power associated with the Amazons, depending on your combo). At the end of each of your Troop Redeployments (see Troop Redeployment, p. 5), remove four tokens from the map, making sure to leave at least one Amazon token in each of your Regions if possible, and only take these four tokens back in hand to redeploy on the map once you Ready your Troops (see Ready your Troops, p. 6) at the start of your next turn." << endl;
}

Dwarves::Dwarves() {
    this->tokenAmount = 3;
    this->name = "Dwarves";
    this->raceTokens = 8;
}

Dwarves::~Dwarves() {
    
}

void Dwarves::racialAbility() {
    cout << "Each Mine Region your Dwarves occupy is worth 1 bonus Victory coin, at the end of your turn. This power is kept even when the Dwarves are In Decline." << endl;
}

Elves::Elves() {
    this->tokenAmount = 6;
    this->name = "Elves";
    this->raceTokens = 11;
}

Elves::~Elves() {
    
}

void Elves::racialAbility() {
    cout << "When the enemy conquers one of your Regions, keep all your Elf tokens in hand for redeployment at the end of the current player's turn, rather than discarding 1 Elf token back into the storage tray (see Enemy Losses & Withdrawals, p. 4)." << endl;
}

Ghouls::Ghouls() {
    this->tokenAmount = 5;
    this->name = "Ghouls";
    this->raceTokens = 10;
}

Ghouls::~Ghouls() {
    
}

void Ghouls::racialAbility() {
    cout << "Your Ghoul tokens all stay on the map when going into Decline, instead of the usual 1 token per Region. In addition, unlike other Races, once In Decline, your Ghouls can continue to conquer new Regions in the following turns, playing exactly as if they were still Active tokens. However these conquests must be done at the start of your turn, before any conquest by your Active race. You may even attack your own currently Active race with your In Decline Ghouls, if you wish." << endl;
}

Giants::Giants() {
    this->tokenAmount = 6;
    this->name = "Giants";
    this->raceTokens = 11;
}

Giants::~Giants() {
    
}

void Giants::racialAbility() {
    cout << "Your Giants may conquer any Region adjacent to a Mountain Region they occupy at a cost of 1 less Giant token than normal. A minimum of 1 Giant token is still required." << endl;
}

Halflings::Halflings() {
    this->tokenAmount = 6;
    this->name = "Halflings";
    this->raceTokens = 11;
}

Halflings::~Halflings() {
    
}

void Halflings::racialAbility() {
    cout << "Your Halfling tokens may enter the map through any Region of the map, not just border ones. Place a Hole-in-the-Ground in each of the first 2 Regions you conquer, to make them immune to enemy conquests as well as racial and special powers. You remove your Holes-in-the-Ground (and lose the protection they confer in these Regions) when your Halflings go into Decline, or if you choose to abandon a Region containing a Hole-in-the-Ground." << endl;
}

Humans::Humans() {
    this->tokenAmount = 5;
    this->name = "Humans";
    this->raceTokens = 10;
}

Humans::~Humans() {
    
}

void Humans::racialAbility() {
    cout << "Each Farmland Region your Humans occupy is worth 1 bonus Victory coin, at the end of your turn." << endl;
}

Orcs::Orcs() {
    this->tokenAmount = 5;
    this->name = "Orcs";
    this->raceTokens = 10;
}

Orcs::~Orcs() {
    
}

void Orcs::racialAbility() {
    cout << "Each not empty Region your Orcs conquered this turn is worth 1 bonus Victory coin, at the end of your turn." << endl;
}



Ratmen::Ratmen () {
    this->tokenAmount = 8;
    this->name = "Ratmen";
    this->raceTokens = 13;
}

Ratmen::~Ratmen() {
    
}

void Ratmen::racialAbility() {
    cout << "No Race benefit; their sheer number of tokens is enough!" << endl;
}

Skeletons::Skeletons() {
    this->tokenAmount = 6;
    this->name = "Skeletons";
    this->raceTokens = 20;
}

Skeletons::~Skeletons() {
    
}

void Skeletons::racialAbility() {
    cout << "During your Troop Redeployment (p. 5), take 1 new Skeleton token from the storage tray for every 2 non-empty Regions you conquered this turn, and add it to the troops you redeploy at the end of your turn. If there are no more tokens in the storage tray, you do not receive any additional tokens" << endl;
}

Sorcerers::Sorcerers() {
    this->tokenAmount = 5;
    this->name = "Sorcerers";
    this->raceTokens = 18;
}

Sorcerers::~Sorcerers() {
    
}

void Sorcerers::racialAbility() {
    cout << "Once per turn per opponent, your Sorcerers can conquer a Region by substituting one of your opponent's Active tokens with one of your own taken from the storage tray. If there are no more tokens in the storage tray, then you cannot conquer a new Region in this way. The token your Sorcerers replaces must be the only race token in its Region (A single Troll token with its Troll's Lair is considered alone for this purpose; likewise for a Race token in a Fortress or on a Mountain, these markers provide no protection to a lone Race token) and that Region must be adjacent to one of your Sorcerers'. Place the substituted opponent's Race token back into the storage tray. If an Elf is converted by a Sorcerer, the Elf does lose his token." << endl;
}

Tritons::Tritons() {
    this->tokenAmount = 6;
    this->name = "Tritons";
    this->raceTokens = 11;
}

Tritons::~Tritons() {
    
}

void Tritons::racialAbility() {
    cout << "Your Tritons may conquer all Coastal Regions (those bordering a Sea or Lake) at a cost of 1 less Triton token than normal. A minimum of 1 Triton token is still required." << endl;
}

Trolls::Trolls() {
    this->tokenAmount = 5;
    this->name = "Trolls";
    this->raceTokens = 10;
}

Trolls::~Trolls() {
    
}

void Trolls::racialAbility() {
    cout << "Place a Troll's Lair in each Region your Trolls occupy. The Troll's Lair augments your region's defense by 1 (just as if you had an additional Troll token stationed there), and stays in the Region even after your Trolls go into Decline. Remove the Troll's Lair if you abandon the Region or when an enemy conquers it." << endl;
}

Wizards::Wizards() {
    this->tokenAmount = 5;
    this->name = "Wizards";
    this->raceTokens = 10;
}

Wizards::~Wizards() {
    
}

void Wizards::racialAbility() {
    cout << "Each Magic Region your Wizards occupy is worth 1 bonus Victory coin, at the end of your turn." << endl;
}

BlankRace::BlankRace() {
    this->name = "Blank Race";
}

BlankRace::~BlankRace() {
    
}

void BlankRace::racialAbility() {
    cout << "No ability" << endl;
}

