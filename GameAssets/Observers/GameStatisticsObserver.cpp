#include "GameStatisticsObserver.hpp"

GameStatisticsObserver::GameStatisticsObserver() {
    this->map = NULL;
    this->players = NULL;
}

GameStatisticsObserver::GameStatisticsObserver(Map &map, vector<Player*> &players) {
    this->map = &map;
    this->players = &players;
    for(int i=0;i<this->players->size();i++)
    {
        this->players->at(i)->Attach(this);
    }
}

GameStatisticsObserver::~GameStatisticsObserver() {
    
}

vector<Player*>* GameStatisticsObserver::getPlayers() {
    return this->players;
}

void GameStatisticsObserver::printStatistics(){
    double stats = 0;
    
    cout << "=========================Map control statistics=========================" << endl;
    for(int i=0; i<this->players->size();i++)
    {
        stats = (double)this->players->at(i)->getRegionsControlled().size() / (double)(boost::num_vertices(this->map->getGraph()));
        cout << this->players->at(i)->getName() << " controls: " << (stats*100) << "% of the map" << endl;
    }
    cout << endl;
}

// Method that is called once this observer is notified by its subject
void GameStatisticsObserver::update() {
    printStatistics();
}

// Need an empty method in order to engage in runtime polymorphism of this method with its derived classes
void GameStatisticsObserver::setDetailedDecorator(bool isDetailed) {
    
}
