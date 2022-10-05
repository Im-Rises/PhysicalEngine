#ifndef SPRING_H
#define SPRING_H

#include "ForceGenerator.h"

class Spring : ForceGenerator {
private:
	Particule* otherIntegrable;
	float m_k;
	float m_restLength;

public:
	void addForce(Particule* particule, float duration);
};

#endif /* SPRING_H */
