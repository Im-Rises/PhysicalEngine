#ifndef GRAVITY_H
#define GRAVITY_H

#include "ForceGenerator.h"

class Gravity : ForceGenerator {
private:
	Vector3d m_gravity;
public:
	void updateForce(Particule* particule, float duration);
};

#endif /* GRAVITY_H */
