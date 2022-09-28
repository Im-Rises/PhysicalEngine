#ifndef DRAG_H
#define DRAG_H

#include "ForceGenerator.h"

class Drag : ForceGenerator {
private:
	float m_k1;
	float m_k2;

public:
	void updateForce(Particule* particule, float duration);
};

#endif /* DRAG_H */
