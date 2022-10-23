#ifndef PARTICLE_COLLIDER_H
#define PARTICLE_COLLIDER_H

#include "../../Scene/Components/PhysicalComponent/Particle/Particle.h"

class ParticleCollider {


private:
    float m_radius;
    Particle *m_particule;

public:

    ParticleCollider(Particle *particule, float radius);

#pragma region Getter setter

    float getRadius();

    Particle *getParticule();

#pragma endregion
};

#endif // !PARTICLE_COLLIDER_H
