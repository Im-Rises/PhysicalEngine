#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "../Particule/Particule.h"
#include <iostream>
#include <iterator>
#include <list>
#include <chrono>
class Integrator {

private:
	std::list<Particule> m_integrableList;
	bool m_StopPhysics=false;

public:

	Integrator();

	void AddIntegrable(Particule & integrable);
	void UpdateAll(double time);
	void boucle();

};


#endif // !INTEGRATOR_H
