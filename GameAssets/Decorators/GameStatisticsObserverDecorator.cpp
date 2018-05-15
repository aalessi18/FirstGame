#include "GameStatisticsObserverDecorator.hpp"

GameStatisticsObserverDecorator::GameStatisticsObserverDecorator() {
    this->decoratedObserver = NULL;
    this->isDetailed = true;
}

GameStatisticsObserverDecorator::GameStatisticsObserverDecorator(GameStatisticsObserver *decoratedObserver) {
    this->decoratedObserver = decoratedObserver;
    this->players = decoratedObserver->getPlayers();
    
    for(int i=0;i<this->players->size();i++)
    {
        // Detaching in order to attached the new derived decorator, orelse there will be two observers attached to the same subject
        this->players->at(i)->Detach(decoratedObserver);
        this->players->at(i)->Attach(this);
    }
    this->isDetailed = true;
}

GameStatisticsObserverDecorator::~GameStatisticsObserverDecorator() {
    
}

void GameStatisticsObserverDecorator::setDetailedDecorator(bool isDetailed) {
    this->isDetailed = isDetailed;
}

void GameStatisticsObserverDecorator::printStatistics() {
    this->decoratedObserver->printStatistics();
    
    // If conditions since we allow the user to choose whether they want the basic or decorated observers every turn
    if(isDetailed==true)
    {
        for(int i=0; i<this->players->size();i++)
        {
            cout << this->players->at(i)->getName() << " -> Graph Representation: ";
            cout << "|";
            for (int j=0; j<this->players->at(i)->getRegionsControlled().size(); j++)
            {
                cout << "-";
            }
            cout << "|" << endl;
        }
        cout << endl;
    }
}

// Method that is called once this observer is notified by its subject
void GameStatisticsObserverDecorator::update() {
    this->printStatistics();
}
