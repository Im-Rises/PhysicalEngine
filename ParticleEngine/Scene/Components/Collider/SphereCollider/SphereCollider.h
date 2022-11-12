#ifndef SPHERECOLLIDER_H
#define SPHERECOLLIDER_H

#include "../Collider.h"

class SphereCollider : public Collider {
private:
    float m_radius;
    
public:
    SphereCollider(GameObject* gameObject, float radius);

    float getRadius() const;

    void setRadius(float radius);
};



#endif // SPHERECOLLIDER_H
