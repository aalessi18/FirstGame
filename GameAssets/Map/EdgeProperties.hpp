#ifndef EdgeProperties_hpp
#define EdgeProperties_hpp

/* Class for edge properties if needed */

class EdgeProperties {
private:
    int vertex1;
    int vertex2;
public:
    EdgeProperties();
    EdgeProperties(int vertex1, int vertex2);
    ~EdgeProperties();
    void setVertex1(int vertex1);
    int getVertex1();
};

#endif /* EdgeProperties_hpp */
