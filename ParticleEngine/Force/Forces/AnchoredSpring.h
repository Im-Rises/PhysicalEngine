#ifndef ANCHOREDSPRING_H
#define ANCHOREDSPRING_H

#include "../ParticleForceGenerator.h"
#include "../../Utility/Vector3d.h"

class AnchoredSpring : public ParticleForceGenerator {
private:
    static constexpr const char *FORCE_TYPE = ANCHORED_SPRING_FORCE;

    Vector3d m_anchor;
    float m_k;
    float m_restLength;

public:
    AnchoredSpring();

    ~AnchoredSpring();

    AnchoredSpring(const Vector3d &anchor, float k, float restLength);

    AnchoredSpring(const AnchoredSpring &aSpring);

    void addForce(Particle *particle) override;

    void drawGui(Scene *scene) override;

    void translate(const Vector3d &translation);

    std::string getName() const override;
};

#endif /* ANCHOREDSPRING_H */
