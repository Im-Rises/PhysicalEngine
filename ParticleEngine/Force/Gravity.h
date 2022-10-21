#ifndef GRAVITY_H
#define GRAVITY_H

#include "ForceGenerator.h"

class Gravity : ForceGenerator {
private:
    Vector3d m_gravity;

public:
    Gravity();

    explicit Gravity(Vector3d g);

    Gravity(const Gravity &grav);

    void addForce(Particle *particle, float duration) override;
};

#endif /* GRAVITY_H */
