#ifndef DRAG_H
#define DRAG_H

#include "ForceGenerator.h"

class Drag : public ForceGenerator {
private:
    float m_k1;
    float m_k2;

public:
    Drag();

    Drag(float k1, float k2);

    Drag(const Drag &drag);

    void addForce(Particle *particle, float duration) override;
};

#endif /* DRAG_H */
