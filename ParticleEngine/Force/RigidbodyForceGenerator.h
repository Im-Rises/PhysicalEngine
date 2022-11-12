#ifndef RIGIDBODYFORCEGENERATOR_H
#define RIGIDBODYFORCEGENERATOR_H

#include <string>

class Rigidbody;

class Scene;

class GameObject;

class RigidbodyForceGenerator {

protected:
    GameObject *parentGameObject = nullptr;

public:
    virtual ~RigidbodyForceGenerator();

    explicit RigidbodyForceGenerator(GameObject *gameObject = nullptr);

    virtual void addForce(Rigidbody *rigidbody) = 0;


};

#endif /* RIGIDBODYFORCEGENERATOR_H */
