#include "Subject.hpp"

Subject::Subject() {
    this->observers = new list<Observer*>;
}

Subject::~Subject() {
    delete this->observers;
}

void Subject::Attach(Observer* o){
    this->observers->push_back(o);
}

void Subject::Detach(Observer* o){
    this->observers->remove(o);
}

void Subject::Notify(){
    list<Observer*>::iterator i = this->observers->begin();
    for(i=i;i!= observers->end();++i)
    {
        (*i)->update();
    }
    
}
