#ifndef SPRING_H
#define SPRING_H

#include "ForceGenerator.h"

class Spring : public ForceGenerator {
private:
    static constexpr const char *FORCE_TYPE = SPRING_FORCE;

private:
    Particle *m_otherParticle;
    float m_k;
    float m_restLength;

public:
//	Spring();
    ~Spring();

    Spring(Particle *otherParticle, float k, float restLength);

    Spring(const Spring &spring);

    void addForce(Particle *particle, float duration) override;

    void drawGui() override;

public:
    std::string getName() const override;
};

#endif /* SPRING_H */
