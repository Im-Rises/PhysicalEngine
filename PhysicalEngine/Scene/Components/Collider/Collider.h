/*
#ifndef COLLIDER_H
#define COLLIDER_H

#include "../Component.h"

class Collider : public Component {
private:
    static constexpr const char *COMPONENT_TYPE = COLLIDER_COMPONENT;
    float m_mass;
    float m_friction;
    float m_restitution;

public:
    explicit Collider(GameObject *gameObject);

    Collider(GameObject *gameObject, float mass, float friction, float restitution);

    void update(float time) override;

    float getMass() const;

    float getFriction() const;

    float getRestitution() const;

    void setMass(float mass);

    void setFriction(float friction);

    void setRestitution(float restitution);

    void drawGui() override;

    std::string getName() const override;
};


#endif //COLLIDER_H
*/
