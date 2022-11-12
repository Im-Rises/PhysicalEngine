#ifndef CUBOIDCOLLIDER_H
#define CUBOIDCOLLIDER_H

#include "../Collider.h"

class CuboidCollider : Collider {
private:
    float m_width;
    float m_height;
    float m_depth;

public:
    CuboidCollider(GameObject* gameObject, float width=1.0f, float height=1.0f, float depth=1.0f);

    float getWidth() const;

    float getHeight() const;

    float getDepth() const;

    void setWidth(float width);

    void setHeight(float height);

    void setDepth(float depth);
};



#endif // CUBOIDCOLLIDER_H
