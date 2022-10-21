#ifndef FORCEGENERATOR_H
#define FORCEGENERATOR_H

#define GRAVITY_FORCE "Gravity"
#define DRAG_FORCE "Drag"
#define SPRING_FORCE "Spring"
#define ANCHORED_SPRING_FORCE "AnchoredSpring"
#define BUOYANCY_FORCE "Buoyancy"
#define ANCHORED_BOIDANCY_FORCE "AnchoredBuoyancy"

#include <string>

class Particle;

class ForceGenerator {
public:
    static constexpr const char *forcesNamesList[] = {GRAVITY_FORCE, DRAG_FORCE, SPRING_FORCE, ANCHORED_SPRING_FORCE,
                                                      BUOYANCY_FORCE, ANCHORED_BOIDANCY_FORCE};

private:
    static constexpr const char *FORCE_TYPE = "ForceGenerator";

public:
    virtual void addForce(Particle *particle, float duration) = 0;

    virtual void drawGui();

    virtual std::string getName() const = 0;

};

#endif /* FORCEGENERATOR_H */
