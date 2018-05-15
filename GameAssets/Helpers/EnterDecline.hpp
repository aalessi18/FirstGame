#ifndef EnterDecline_hpp
#define EnterDecline_hpp

#include "Map.hpp"
#include "Player.hpp"

class EnterDecline {
private:
    Map* map;
    Player* player;
public:
    EnterDecline();
    EnterDecline(Map &map, Player &player);
    ~EnterDecline();
    void assistDecline();
};

#endif /* EnterDecline_hpp */
