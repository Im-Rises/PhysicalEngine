#ifndef SPRING_H
#define SPRING_H

#include "ForceGenerator.h"

class Spring : ForceGenerator {
private:
	Particule* m_otherParticule;
	float m_k;
	float m_restLength;

public:
	Spring();
	~Spring();
	Spring(Particule* otherParticule, float k, float restLength);
	Spring(const Spring& spring);
	void addForce(Particule* particule, float duration);
};

#endif /* SPRING_H */
