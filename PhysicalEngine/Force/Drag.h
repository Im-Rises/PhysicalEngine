#ifndef DRAG_H
#define DRAG_H

#include "ForceGenerator.h"

class Drag : public ForceGenerator {
public:
    static constexpr const char *FORCE_TYPE = DRAG_FORCE;

private:
    float m_k1;
    float m_k2;

public:
    Drag();

    Drag(float k1, float k2);

    Drag(const Drag &drag);

    void addForce(PhysicalComponent *physicalComponent) override;

    void drawGui(Scene *scene) override;

public:
    std::string getName() const override;
};

#endif /* DRAG_H */
