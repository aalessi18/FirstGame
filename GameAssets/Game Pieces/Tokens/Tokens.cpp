#include "Tokens.hpp"

Token::Token() {
    this->tokenAmount = 0;
    this->name = "no_token";
}

Token::~Token() {
    
}

string Token::getName() {
    return name;
}

int Token::getTokenAmount() {
    return tokenAmount;
}

void Token::setTokenAmount(int tokenAmount) {
    this->tokenAmount = tokenAmount;
}

TrollLair::TrollLair(){
    this->tokenAmount = 10;
    this->name = "Troll Lair";
}

TrollLair::~TrollLair(){
    
}

Fortress::Fortress(){
    this->tokenAmount = 6;
    this->name = "Fortress";
}

Fortress::~Fortress(){
    
}

MountainToken::MountainToken(){
    this->tokenAmount = 9;
    this->name = "Mountain";
}

MountainToken::~MountainToken(){
    
}

Encampment::Encampment(){
    this->tokenAmount = 5;
    this->name = "Encampment";
}

Encampment::~Encampment(){
    
}

HolesInTheGround::HolesInTheGround(){
    this->tokenAmount = 2;
    this->name = "Holes In The Ground";
}

HolesInTheGround::~HolesInTheGround(){
    
}

Heroes::Heroes(){
    this->tokenAmount = 2;
    this->name = "Hero";
}

Heroes::~Heroes(){
    
}

Dragon::Dragon(){
    this->tokenAmount = 1;
    this->name = "Dragon";
}

Dragon::~Dragon(){
    
}
