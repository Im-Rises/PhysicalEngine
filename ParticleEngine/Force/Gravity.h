#ifndef GRAVITY_H
#define GRAVITY_H

#include "ForceGenerator.h"
#include "../Utility/Vector3d.h"

class Gravity : public ForceGenerator {
private:
    Vector3d m_gravity;

public:
    explicit Gravity(const Vector3d &g = Vector3d(0.0f, -9.81f, 0.0f));

//    Gravity(const Gravity &grav);

    void addForce(Particle *particle, float duration) override;

    Vector3d &getGravityRef();
};

#endif /* GRAVITY_H */
