#ifndef Tokens_hpp
#define Tokens_hpp

#include <iostream>

using namespace std;

// Class for all the different tokens the game holds

class Token {
protected:
    int tokenAmount;
    string name;
public:
    Token();
    virtual ~Token();
    int getTokenAmount();
    void setTokenAmount(int tokenAmount);
    string getName();
};

class TrollLair : public Token {
private:
    
public:
    TrollLair();
    ~TrollLair();
};

class Fortress : public Token {
private:
    
public:
    Fortress();
    ~Fortress();
};

class MountainToken : public Token {
private:
public:
    MountainToken();
    ~MountainToken();
};

class Encampment : public Token {
private:
public:
    Encampment();
    ~Encampment();
};

class HolesInTheGround : public Token {
private:
public:
    HolesInTheGround();
    ~HolesInTheGround();
};

class Heroes : public Token {
private:
public:
    Heroes();
    ~Heroes();
};

class Dragon : public Token {
private:
public:
    Dragon();
    ~Dragon();
};

#endif /* Tokens_hpp */
