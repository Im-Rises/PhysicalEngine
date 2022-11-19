#ifndef PHYSICALCOMPONENT_H
#define PHYSICALCOMPONENT_H

#include "../../../Utility/Vector3d.h"
#include "../Component.h"

class PhysicalComponent : public virtual Component {
protected:
    PhysicalComponent() = default;

    Vector3d m_forceAccum;
    float m_mass;

    // Velocity and acceleration
    Vector3d linearSpeed;
    Vector3d linearAcceleration;

private:
    static constexpr const char *COMPONENT_TYPE = "PhysicalComponent";

public:
    void update(float time) override = 0;

    float distance(const PhysicalComponent &p);

    Vector3d getPosition() const;

    void setPosition(const Vector3d &position);

    const Vector3d &getNetForce() const;

    void setNetForce(const Vector3d &force);

    float getMass() const;

    Vector3d getLinearSpeed() const;

    void setLinearSpeed(const Vector3d &linearSpeed);

    void drawGui() override = 0;

    std::string getName() const override = 0;


};


#endif //PHYSICALCOMPONENT_H
