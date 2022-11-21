#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <list>
#include "Components/PhysicalComponent/Rigidbody/Rigidbody.h"

class PhysicalComponent;

//class Particle;
//
//class Rigidbody;

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
    void move(GameObject *gameObject, PhysicalComponent *physicalComponent, float deltaTime);

    void angularMove(GameObject *gameObject, Rigidbody *rigidbody, float deltaTime);

};


#endif // !INTEGRATOR_H
