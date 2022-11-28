#ifndef PARTICLEPREFAB_H
#define PARTICLEPREFAB_H

#include "../GameObject.h"

class Scene;

class ParticlePrefab : public GameObject {
private:

public:
    explicit ParticlePrefab(Scene *scene);

    ~ParticlePrefab();
};


#endif //PARTICLEPREFAB_H
