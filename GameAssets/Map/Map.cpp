/*
 Implementation of Map Class
 */

#include "Map.hpp"
#include "Tokens.hpp"
#include <boost/graph/named_function_params.hpp>

using namespace std;

Map::Map() {
    
}

Map::~Map() {
}

void Map::printContents() {
    for(int i=0;i<num_vertices(graphData);i++)
    {
        cout << "Vertex: " << graphData[i].getIndex() << endl;
        graphData[i].printAdjacentContents(false);
    }
    cout << endl;
}

void Map::printAdjacentRegions(vector<int> &controlledRegions, bool withSea) {
    cout << "Adjacent regions are: " << endl;
    for(int i=0; i<controlledRegions.size(); i++)
    {
        int temp1 = controlledRegions.at(i);
        for(int j=0;j<graphData[temp1].getAdjacentRegionsIndex().size(); j++)
        {
            int temp2 = graphData[temp1].getAdjacentRegionsIndex().at(j);
            if(withSea==false && graphData[temp2].getRegionName()!="Sea")
            {
                cout << "Region: " << graphData[temp2].getIndex() << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

UndirectedGraph& Map::getGraph(){
    return graphData;
}

void Map::findOutsideEdges() {
    for(int i=0;i<num_vertices(graphData);i++)
    {
        if(graphData[i].isOutsideEdge() == true && graphData[i].getRegionName()!= "Sea")
            outsideEdges.push_back(i);
    }
}

void Map::setOutsideEdges(int region){ // USE FIND OUTSIDE EDGES TO ADD IN HERE
    this->outsideEdges.push_back(region);
}

vector<int> Map::getOutsideEdges() {
    return outsideEdges;
}

void Map::printOutsideEdges() {
    for(int i=0;i<outsideEdges.size();i++)
    {
        cout << "Region: "<< outsideEdges.at(i) << " ";
    }
    cout << endl;
}
