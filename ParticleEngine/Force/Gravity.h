#ifndef GRAVITY_H
#define GRAVITY_H

#include "ForceGenerator.h"

class Gravity : ForceGenerator {
private:
    Vector3d m_gravity;
public:
    Gravity();

    Gravity(Vector3d g);

    Gravity(const Gravity &grav);

    void addForce(Particle *particule, float duration);
};

#endif /* GRAVITY_H */
