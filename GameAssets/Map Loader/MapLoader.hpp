#ifndef MapLoader_hpp
#define MapLoader_hpp

#include "Map.hpp"
#include <fstream>
#include <iostream>

using namespace std;

// This is the Class which loads the contents of the map file
class MapLoader {
private:
    string getMapFile(int numberOfPlayers);
public:
    MapLoader();
    ~MapLoader();
    Map readContents(int numberOfPlayers, Map map);
};

#endif /* MapLoader_hpp */
