#ifndef INTEGRABLE_H
#define INTEGRABLE_H

#include <vector>
#include "../../../../Utility/Vector3d.h"
#include "../../Component.h"
#include "../PhysicalComponent.h"
#include "../../../../Force/Gravity.h"

class ForceGenerator;


class Rigidbody : public PhysicalComponent {
private:
    static constexpr const char *COMPONENT_TYPE = RIGIDBODY_COMPONENT;

protected:
    bool isKinematic = true;
    float m_mass;

    float m_angularDamping;
    Vector3d m_forceAccum;
    Vector3d m_torqueAccum;

    // Velocity and acceleration
    Vector3d linearSpeed;
    Vector3d linearAcceleration;
    Vector3d angularSpeed;
    Vector3d angularAcceleration;

    // Forces
    Gravity gravity;
    std::vector<ForceGenerator *> forceGeneratorsList;


public:
    explicit Rigidbody(GameObject *gameObject);

    void AddForce(const Vector3d &force);

    void AddForceAtPoint(const Vector3d &force, const Vector3d worldPoint);

    void AddForceAtBodyPoint(const Vector3d &force, const Vector3d &LocalPoint);

    void clearAccumulator();

    void update(float time) override;

    void drawGui() override;

    std::string getName() const override;

};

#endif // !INTEGRABLE_H
