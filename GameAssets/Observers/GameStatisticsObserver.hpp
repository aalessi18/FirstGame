#ifndef GameStatisticsObserver_hpp
#define GameStatisticsObserver_hpp

#include "Map.hpp"
#include <vector>

using namespace std;

// Observer class which shows basic statistics for each user. This observer also updates at every conquer a user engages in

class GameStatisticsObserver: public Observer {
protected:
    Map* map;
    vector<Player*>* players;
public:
    GameStatisticsObserver();
    GameStatisticsObserver(Map &map, vector<Player*> &players);
    virtual ~GameStatisticsObserver();
    vector<Player*>* getPlayers();
    virtual void printStatistics();
    virtual void update();
    virtual void setDetailedDecorator(bool isDetailed);
};

#endif /* GameStatisticsObserver_hpp */
