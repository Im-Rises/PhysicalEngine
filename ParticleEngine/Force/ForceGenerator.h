#ifndef FORCEGENERATOR_H
#define FORCEGENERATOR_H

#define GRAVITY_FORCE "Gravity"
#define DRAG_FORCE "Drag"
#define SPRING_FORCE "Spring"
#define ANCHORED_SPRING_FORCE "Anchored Spring"
#define BUOYANCY_FORCE "Buoyancy"

#include <string>

class Particle;

class ForceGenerator {
public:
    static const char *forcesNamesList[3];

private:
    static constexpr const char *FORCE_TYPE = "ForceGenerator";

public:
    virtual void addForce(Particle *particle, float duration) = 0;

    virtual void drawGui() = 0;

    virtual std::string getName() const = 0;

public:
    static ForceGenerator *createForceGenerator(const std::string &name);

};

#endif /* FORCEGENERATOR_H */
