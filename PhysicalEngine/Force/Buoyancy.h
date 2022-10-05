#ifndef BUOYANCY_H
#define BUOYANCY_H

#include "ForceGenerator.h"

class Buoyancy : ForceGenerator {
private:
	float m_maxDepth;
	float m_volume;

	float m_waterHeight;
	float m_liquidDensity;

public:
	void addForce(Particule* particule, float duration);
};

#endif /* BUOYANCY_H */
