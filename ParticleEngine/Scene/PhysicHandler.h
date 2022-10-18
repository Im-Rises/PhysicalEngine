#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <list>

class Rigidbody;

class GameObject;

class PhysicHandler {

private:
    std::list<Rigidbody *> m_integrableList;
    int fixeFrameRate = 50;
    float fixedDeltaTime = 0;
    float timeToAdjustFrameRate = 0;

public:
    PhysicHandler();

    void updateAll(float time);

    void update(float time, GameObject *gameObject);

    void addRigidbody(Rigidbody *rigidbody);

};


#endif // !INTEGRATOR_H
