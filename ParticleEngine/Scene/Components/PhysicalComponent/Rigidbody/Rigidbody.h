#ifndef INTEGRABLE_H
#define INTEGRABLE_H

#include "../../../../Utility/Vector3d.h"
#include "../../Component.h"
#include "../PhysicalComponent.h"

class Rigidbody : public PhysicalComponent {
private:
    static constexpr const char *COMPONENT_TYPE = RIGIDBODY_COMPONENT;

protected:
    float m_mass;
    float m_angularDamping;
    Vector3d m_forceAccum;
    Vector3d m_torqueAccum;
//    float m_damping;
//    float m_inverseMass;
//    float m_inverseInertiaTensor;
//    float m_gravity;
//    float m_friction;
//    float m_restitution;
//    bool isKinematic = false;

public:
    explicit Rigidbody(GameObject *gameObject);

    void AddForce(const Vector3d& force);

    void AddForceAtPoint(const Vector3d& force, const Vector3d worldPoint);

    void AddForceAtBodyPoint(const Vector3d& force, const Vector3d& LocalPoint);

    void ClearAccumulator();

    void update(float time) override;

    void drawGui() override;

    std::string getName() const override;

};

#endif // !INTEGRABLE_H
