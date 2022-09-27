#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <list>

class Rigidbody;

class Integrator {

private:
    std::list<Rigidbody *> m_integrableList;
    int m_fixeFrameRate = 50;
    float m_fixedDeltaTime = 0;
    float m_timeToAdjustFrameRate = 0;

public:

    Integrator();

    void AddIntegrable(Rigidbody *integrable);

    void UpdateAll(double time);

    void boucle();

};


#endif // !INTEGRATOR_H
