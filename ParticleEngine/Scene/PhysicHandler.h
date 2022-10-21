#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <list>

class Particle;

class Rigidbody;

class GameObject;

class PhysicHandler {

private:
    std::list<Particle *> particlesList;
    const int fixedUpdatePerSecond = 50;
    float fixedDeltaTime = 1.0f / fixedUpdatePerSecond;
    float timeToAdjustFrameRate = 0;

public:
    PhysicHandler();

//    void updateAll(float time);

    void update(float time);

    void addRigidbody(Rigidbody *rigidbody);

};


#endif // !INTEGRATOR_H
