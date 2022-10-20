#ifndef INTEGRABLE_H
#define INTEGRABLE_H

#include "../../../Vector3d/Vector3d.h"
#include "../Component.h"

class Rigidbody : public Component {
private:
    static constexpr const char *COMPONENT_TYPE = "Rigidbody";

protected:
//    float m_mass;
//    float m_damping;
//    float m_inverseMass;
//    float m_inverseInertiaTensor;
//    float m_gravity;
//    float m_friction;
//    float m_restitution;
//    bool isKinematic = false;

public:
    Rigidbody(GameObject *gameObject, std::string name = "Rigidbody");

    void update(float time) override;

    void drawGui() override;

    std::string getName() const override;

};

#endif // !INTEGRABLE_H
