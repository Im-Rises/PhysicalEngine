#ifndef RIGIDBODYPREFAB_H
#define RIGIDBODYPREFAB_H

#include "../GameObject.h"

class Scene;

class RigidbodyPrefab : public GameObject {
private:

public:
    explicit RigidbodyPrefab(Scene *scene);

    RigidbodyPrefab(Scene *scene, Mesh *mesh);

    ~RigidbodyPrefab();
};


#endif //RIGIDBODYPREFAB_H
