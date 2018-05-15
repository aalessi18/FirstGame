#include "EdgeProperties.hpp"
#include <iostream>

using namespace std;

EdgeProperties::EdgeProperties(){
    this->vertex1 = 0;
    this->vertex2 = 0;
}

EdgeProperties::EdgeProperties(int vertex1, int vertex2){
    this->vertex1 = vertex1;
    this->vertex2 = vertex2;
}

EdgeProperties::~EdgeProperties(){
    
}

void EdgeProperties::setVertex1(int vertex1){
    this->vertex1 = vertex1;
}

int EdgeProperties::getVertex1() {
    return this->vertex1;
}

