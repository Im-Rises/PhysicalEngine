#ifndef FORCEGENERATOR_H
#define FORCEGENERATOR_H

class Particle;

class ForceGenerator {
    virtual void addForce(Particle *particle, float duration) = 0;
};

#endif /* FORCEGENERATOR_H */
