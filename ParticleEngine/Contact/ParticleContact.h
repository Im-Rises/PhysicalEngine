#ifndef PARTICLE_CONTACT_H
#define PARTICLE_CONTACT_H

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"

class ParticleContact {
private:
    Particle *m_particules[2];

    float m_collision_elasticity = 0;

    float m_penetration = 0;

    Vector3d m_contactNormal;

    void updateAttributes();

    void resolveSpeed();

    void resolveInterpenetration();


public:

    ParticleContact();

    void setPenetration(float penetration);

    void setElasticity(float elasticity);

    void setContactNormal(Vector3d normalContact);

    Particle **GetParticles();

    void SetParticles(Particle *particles[2]);

    void SetParticles(Particle *particle1, Particle *particle2);

    void resolve(float time);

    float CalculateSeparatingVelocity();


};


#endif // !PARTICLE_CONTACT_H
