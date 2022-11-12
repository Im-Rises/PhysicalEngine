#ifndef CUBOIDCOLLIDER_H
#define CUBOIDCOLLIDER_H

#include "../Collider.h"

class CuboidCollider : Collider {
private:
    static constexpr const char* COMPONENT_TYPE = CUBOID_COLLIDER_COMPONENT;
    float m_width;
    float m_height;
    float m_depth;

public:
    explicit CuboidCollider(GameObject* gameObject, float width = 1.0F, float height = 1.0F, float depth = 1.0F);

    void update(float time) override;

    void drawGui() override;

    std::string getName() const override;

    float getWidth() const;

    float getHeight() const;

    float getDepth() const;

    void setWidth(float width);

    void setHeight(float height);

    void setDepth(float depth);
};



#endif // CUBOIDCOLLIDER_H
