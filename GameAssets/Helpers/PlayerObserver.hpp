#ifndef PlayerObserver_hpp
#define PlayerObserver_hpp

class Observer {
private:
public:
    Observer();
    ~Observer();
    virtual void update()=0;
}

#endif /* PlayerObserver_hpp */
