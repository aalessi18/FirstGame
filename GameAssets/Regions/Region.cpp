#include "Region.hpp"

Region::Region() {
    
}

Region::~Region() {
    
}

string Region::getName(){
    return this->name;
}

ForestRegion::ForestRegion() {
    this->name = "Forest";
}

ForestRegion::~ForestRegion() {
    
}

MountainRegion::MountainRegion() {
    this->name = "Mountain";
}

MountainRegion::~MountainRegion(){
    
}

SwampRegion::SwampRegion() {
    this->name = "Swamp";
}

SwampRegion::~SwampRegion() {
    
}

SeaRegion::SeaRegion() {
    this->name = "Sea";
}

SeaRegion::~SeaRegion() {
    
}

FarmRegion::FarmRegion() {
    this->name = "Farm";
}

FarmRegion::~FarmRegion() {
    
}

HillRegion::HillRegion() {
    this->name = "Hill";
}

HillRegion::~HillRegion() {
    
}

