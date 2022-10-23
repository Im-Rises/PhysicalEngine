#ifndef SPRING_H
#define SPRING_H

#include "ForceGenerator.h"

class GameObject;

class Spring : public ForceGenerator {
private:
    static constexpr const char *FORCE_TYPE = SPRING_FORCE;

private:
    float m_k;
    float m_restLength;
//    Particle *m_otherParticle = nullptr;
    GameObject *m_otherGameObject = nullptr;

public:
    Spring();

//    Spring(Particle *otherParticle, float k, float restLength);
//
//    Spring(const Spring &spring);

    ~Spring();

    void addForce(Particle *particle) override;

    void calculateForce(Particle *particle, Particle *otherParticle);

    void drawGui(Scene *scene) override;

public:
    std::string getName() const override;
};

#endif /* SPRING_H */
