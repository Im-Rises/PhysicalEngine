#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <list>

class Particle;

class Rigidbody;

class GameObject;

class PhysicHandler {

private:
//    const int fixedUpdatePerSecond = 50;
//    float fixedDeltaTime = 1.0f / fixedUpdatePerSecond;
//    float timeToAdjustFrameRate = 0;

public:
    PhysicHandler();

    void update(GameObject *gameObject, float deltaTime);

private:
    void move(GameObject *gameObject, Particle *particle, float deltaTime);

};


#endif // !INTEGRATOR_H
