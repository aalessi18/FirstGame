#ifndef Map_hpp
#define Map_hpp

#include <iostream>
#include <utility>                   // for std::pair
#include <algorithm>                 // for std::for_each
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include "NodeProperties.hpp"
#include "EdgeProperties.hpp"

using namespace boost;

/*
 The following typedef's were used to simplify access to types needed for the map/graph properties.
 An undirected graph is used because in the case of thie game, the direction does not matter.
 */
typedef adjacency_list<vecS, vecS, undirectedS,NodeProperties, EdgeProperties> UndirectedGraph;

class Map {
private:
    int amountOfRegions;
    int amountOfEdges;
    UndirectedGraph graphData;
    vector<int> outsideEdges;
    
public:
    Map();
    ~Map();
    // Method to return the graph in order to better access it
    UndirectedGraph& getGraph();
    void printContents();
    void printAdjacentRegions(vector<int> &controlledRegions, bool withSea);
    void findOutsideEdges();
    void setOutsideEdges(int region);
    vector<int> getOutsideEdges();
    void printOutsideEdges();
};

#endif /* Map_hpp */
