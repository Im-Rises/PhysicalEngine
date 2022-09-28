#include "Gravity.h"

void Gravity::updateForce(Particule* particule, float duration) {
	Vector3d F = m_gravity*particule->getMass();
}
