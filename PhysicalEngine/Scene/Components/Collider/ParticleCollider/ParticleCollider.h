#ifndef PARTICLE_COLLIDER_H
#define PARTICLE_COLLIDER_H

#include "../../Component.h"

class Particle;

#define PARTICLE_COLLIDER_COMPONENT "Particle_Collider"

class ParticleCollider : public Component {
private:
    static constexpr const char* COMPONENT_TYPE = PARTICLE_COLLIDER_COMPONENT;
    float m_radius;
    //    Particle* m_particle;

public:
    ParticleCollider(GameObject* gameObject, float radius = 1);

#pragma region Getter setter

    float getRadius() const;

    //    Particle* getParticle();

    std::string getName() const override;

    void update(float time) override;

    void drawGui() override;

#pragma endregion
};

#endif // !PARTICLE_COLLIDER_H
