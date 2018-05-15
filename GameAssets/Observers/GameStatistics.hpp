#ifndef GameStatistics_hpp
#define GameStatistics_hpp

#include "Map.hpp"

using namespace std;

class GameStatisticsObserver {
private:
    Map* map;
public:
    GameStatisticsObserver();
    ~GameStatisticsObserver();
};

#endif /* GameStatistics_hpp */
