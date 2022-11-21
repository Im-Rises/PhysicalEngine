#ifndef SPRING_H
#define SPRING_H

#include "ForceGenerator.h"

class GameObject;

class Spring : public ForceGenerator {
private:
    static constexpr const char* FORCE_TYPE = SPRING_FORCE;

private:
    float m_k;
    float m_restLength;
    //    Particle *m_otherParticle = nullptr;
    GameObject* m_otherGameObject = nullptr;

public:
    explicit Spring(GameObject* gameObject);

    Spring(GameObject* gameObject, float k, float restLength);

    //    Spring(const Spring &spring);

    ~Spring();

    Vector3d getForceValue(PhysicalComponent *physicalComponent) override;

    void addForce(PhysicalComponent* physicalComponent) override;

    void calculateForce(PhysicalComponent* physicalComponent, PhysicalComponent* otherPhysicalComponent);

    void drawGui(Scene* scene) override;

    void setOtherGameObject(GameObject* otherGameObject);

public:
    std::string getName() const override;
};

#endif /* SPRING_H */
