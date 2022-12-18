#ifndef PHYSICALENGINE_PLANEPREFAB_H
#define PHYSICALENGINE_PLANEPREFAB_H

#include "../GameObject.h"

class PlanePrefab : public GameObject {
private:
    //    Plane* plane;
    //    PlaneCollider* planeCollider;

public:
    PlanePrefab(Scene* scene, float width, float height);

    ~PlanePrefab();
};



#endif // PHYSICALENGINE_PLANEPREFAB_H
