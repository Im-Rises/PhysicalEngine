#ifndef FORCEGENERATOR_H
#define FORCEGENERATOR_H

#include <string>

class Particle;

class ForceGenerator {
private:
    static constexpr const char *FORCE_TYPE = "ForceGenerator";

public:
    virtual void addForce(Particle *particle, float duration) = 0;

    virtual void drawGui();

    virtual std::string getName() const = 0;

};

#endif /* FORCEGENERATOR_H */
