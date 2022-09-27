#ifndef FORCEHANDLER_H
#define FORCEHANDLER_H


class ForceHandler {
private:
//    std::list<Force *> m_forceList;

public:
    ForceHandler();

    ~ForceHandler();

    void addForce();

    void update();
    
};


#endif //FORCEHANDLER_H
