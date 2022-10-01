#ifndef COLLIDER_H
#define COLLIDER_H

#include "../Component.h"

class Collider : public Component {
private:
    float mass;
    float friction;
    float restitution;

public:
    Collider();

    Collider(float mass, float friction, float restitution);

    void update() override;

    float getMass() const;

    float getFriction() const;

    float getRestitution() const;

    void setMass(float mass);

    void setFriction(float friction);

    void setRestitution(float restitution);

    void drawGui() override;
};


#endif //COLLIDER_H
