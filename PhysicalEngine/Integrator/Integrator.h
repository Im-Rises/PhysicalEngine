#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "../../PhysicalEngine/Particule/Particule.h"
#include <iostream>
#include <iterator>
#include <list>
#include <chrono>
#include "../Integrable/Integrable.h"

class Integrator {

private:
    std::list<Integrable> m_integrableList;
    bool m_StopPhysics = false;

public:

    Integrator();

    void AddIntegrable(Integrable &integrable);

    void UpdateAll(double time);

    void boucle();

};


#endif // !INTEGRATOR_H