#ifndef GRAVITY_H
#define GRAVITY_H

#include "../ParticleForceGenerator.h"
#include "../../Utility/Vector3d.h"

class Gravity : public ParticleForceGenerator {
public:
    static constexpr const char *FORCE_TYPE = GRAVITY_FORCE;

private:
    Vector3d m_gravity;

public:
    explicit Gravity(const Vector3d &g = Vector3d(0.0f, -9.81f, 0.0f));

    Gravity(const Gravity &grav);

    void addForce(Particle *particle) override;

    void drawGui(Scene *scene) override;

public:
    std::string getName() const override;

    Vector3d &getGravityRef();
};

#endif /* GRAVITY_H */
