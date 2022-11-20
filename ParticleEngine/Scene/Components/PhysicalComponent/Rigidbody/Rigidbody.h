#ifndef INTEGRABLE_H
#define INTEGRABLE_H

#include <vector>
#include "../../../../Utility/Vector3d.h"
#include "../../Component.h"
#include "../PhysicalComponent.h"
#include "../../../../Force/Gravity.h"

class ForceGenerator;

struct ForcePoint {
    ForceGenerator *force;
    Vector3d point;
};

class Rigidbody : public PhysicalComponent {
private:
    static constexpr const char *COMPONENT_TYPE = RIGIDBODY_COMPONENT;

protected:
    float m_angularDamping;
    Vector3d m_torqueAccum;

    Vector3d angularSpeed;
    Vector3d angularAcceleration;

    std::vector<ForcePoint> pointForceGeneratorsList;

public:
    explicit Rigidbody(GameObject *gameObject);

private:
    void addForce(const Vector3d &force);

//    void addForceAtPoint(const Vector3d &force, Vector3d worldPoint);

    void addForceAtBodyPoint(const Vector3d &force, const Vector3d &LocalPoint);

    void calculateAcceleration();

    void calculateSpeed(float time);

    void clearAccumulator();

public:
    void update(float time) override;

    void drawGui() override;

    std::string getName() const override;

    Vector3d getAngularSpeed() const;

};

#endif // !INTEGRABLE_H
