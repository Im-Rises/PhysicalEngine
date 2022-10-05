#ifndef FORCEGENERATOR_H
#define FORCEGENERATOR_H

#include "../Scene/Components/Particule/Particule.h"

class ForceGenerator {
	virtual void addForce(Particule *particule, float duration)=0;
};

#endif /* FORCEGENERATOR_H */
