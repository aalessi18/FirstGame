#ifndef PlayerHands_hpp
#define PlayerHands_hpp

#include "Player.hpp"
#include <vector>
#include "Subject.hpp"

/*
 Class which helps to print each player's hands every turn.
 This class is the subject to the playerHandsObserver
*/
class PlayerHands : public Subject {
private:
    vector<Player*>* players;
public:
    PlayerHands();
    PlayerHands(vector<Player*> &players);
    ~PlayerHands();
    void showHands(); 
    vector<Player*>* getPlayers();
};

#endif /* PlayerHand_hpp */
