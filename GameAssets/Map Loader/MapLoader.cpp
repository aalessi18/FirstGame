#include "MapLoader.hpp"
#include "Map.hpp"
#include <iostream>

using namespace std;

/* Method which takes a string and based on a delimiter will create an array of the smaller strings */
std::vector<std::string> explode(std::string const & s, char delim)
{
    std::vector<std::string> result;
    std::istringstream iss(s);
    
    for (std::string token; std::getline(iss, token, delim); )
    {
        result.push_back(std::move(token));
    }
    
    return result;
}

/* This is a helper method used in order to find the correct Region object to create*/
Region* findRegion(string regionName) {
    Region* temp;
    
    if(regionName=="Forest")
    {
        return new ForestRegion;
    }
    if(regionName=="Mountain")
    {
        return new MountainRegion;
    }
    if(regionName=="Swamp")
    {
        return new SwampRegion;
    }
    if(regionName=="Sea")
    {
        return new SeaRegion;
    }
    if(regionName=="Farm")
    {
        return new FarmRegion;
    }
    if(regionName=="Hill")
    {
        return new HillRegion;
    }
    return temp;
}

// This is a helper method used in order to find the correct Token object to create
Token* findToken(string token){
    if(token=="Troll Lair")
    {
        return new TrollLair();
    }
    else if(token=="Fortress")
    {
        return new Fortress();
    }
    else if(token=="Mountain")
    {
        return new MountainToken();
    }
    else if(token=="Encampment")
    {
        return new Encampment();
    }
    else if(token=="Holes In The Ground")
    {
        return new HolesInTheGround();
    }
    else if(token=="Hero")
    {
        return new Heroes();
    }
    else if(token=="Dragon")
    {
        return new Dragon();
    }
    else
        return new Token();
}

bool findBoolValue(string boolean){
    if(boolean == "true")
        return true;
    else
        return false;
}

MapLoader::MapLoader(){

}

MapLoader::~MapLoader(){

}

// Retrieve the correct map file and return the string of the file name
string MapLoader::getMapFile(int numberOfPlayers) {
    if(numberOfPlayers==2)
        return "2PlayerMap.txt";
    else if(numberOfPlayers==3)
        return "3PlayerMap.txt";
    else if(numberOfPlayers==4)
        return "4PlayerMap.txt";
    else
        return "5PlayerMap.txt";
}

// Method to establish a stream to read the contents of a map file
Map MapLoader::readContents(int numberOfPlayers, Map map) {
    ifstream input;
    string fileName;
    
    fileName = getMapFile(numberOfPlayers);
    
    input.open(fileName);
    
    if(input.fail())
    {
        cerr << "Error opening file." << endl;
        exit(1);
    }
    
    int index, count = 0;
    string region, trait, token, isOutsideEdge, adjacent;
    vector<string> arr;
    vector< vector<string> > array;
    
    // While not the end of the file, keep reading
    while(!input.eof())
    {
        input >> index >> region >> trait >> token >> isOutsideEdge >> adjacent;
        boost::add_vertex(map.getGraph());
        map.getGraph()[count].setIndex(index);
        map.getGraph()[count].setRegion(findRegion(region));
        map.getGraph()[count].setSpecialTrait(trait);
        map.getGraph()[count].setSpecialToken((findToken(token)));
        map.getGraph()[count].setOutsideEdge(findBoolValue(isOutsideEdge));
        
        arr = explode(adjacent, '_');
        array.push_back(arr);
        count++;
    }
    
    for(int i=0;i<array.size();i++)
    {
        for(int j=0;j<array[i].size();j++)
        {
            // Convert string number into integer
            int temp = stoi(array[i][j]);
            boost::add_edge(i, temp, map.getGraph());
            map.getGraph()[i].setAdjacentRegionsIndex(temp);
        }
    }
    map.findOutsideEdges();
    array.pop_back();
    input.close();
    return map;
}
