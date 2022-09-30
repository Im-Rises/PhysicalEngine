#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <list>

class Rigidbody;

class PhysicHandler {

private:
    std::list<Rigidbody *> m_integrableList;
    int m_fixeFrameRate = 50;
    float m_fixedDeltaTime = 0;
    float m_timeToAdjustFrameRate = 0;

public:

    PhysicHandler();

    void addIntegrable(Rigidbody *integrable);

    void updateAll(float time);

    void boucle();

};


#endif // !INTEGRATOR_H
