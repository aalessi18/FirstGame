#ifndef Abandoning_hpp
#define Abandoning_hpp

#include "Player.hpp"
#include "Map.hpp"
#include <boost/algorithm/string/predicate.hpp>

class Abandoning {
private:
    Map* map;
    Player* player;
public:
    Abandoning();
    Abandoning(Map &map, Player &player);
    ~Abandoning();
    void assistAbandoning();
};

#endif /* Abandoning_hpp */
