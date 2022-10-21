#ifndef FORCEGENERATOR_H
#define FORCEGENERATOR_H

#include "../Scene/Components/PhysicalComponent/Particle/Particle.h"

class ForceGenerator {
    virtual void addForce(Particle *particle, float duration) = 0;
};

#endif /* FORCEGENERATOR_H */
