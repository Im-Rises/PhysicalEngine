#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <list>

//class Rigidbody;

class PhysicHandler {

private:
//    std::list<Rigidbody *> m_integrableList;
//    int fixeFrameRate = 50;
    float fixedDeltaTime = 0;
    float timeToAdjustFrameRate = 0;

public:
    PhysicHandler();

    void updateAll(float time);

};


#endif // !INTEGRATOR_H
