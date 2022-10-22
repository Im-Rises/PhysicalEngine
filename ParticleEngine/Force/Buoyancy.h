#ifndef BUOYANCY_H
#define BUOYANCY_H

#include "ForceGenerator.h"

class Buoyancy : public ForceGenerator {
public:
    static constexpr const char *FORCE_TYPE = BUOYANCY_FORCE;

private:
    float m_maxDepth;
    float m_volume;
    float m_waterHeight;
    float m_liquidDensity;

public:
    Buoyancy();

    Buoyancy(float maxDepth, float volume, float waterHeight, float liquidDensity);

    Buoyancy(const Buoyancy &buoyancy);

    void addForce(Particle *particle, float duration) override;

    void drawGui() override;

public:
    std::string getName() const override;
};

#endif /* BUOYANCY_H */
