#ifndef FORCEGENERATOR_H
#define FORCEGENERATOR_H

#define GRAVITY_FORCE "Gravity"
#define DRAG_FORCE "Drag"
#define SPRING_FORCE "Spring"
#define ANCHORED_SPRING_FORCE "Anchored Spring"
#define BUOYANCY_FORCE "Buoyancy"

#include <string>
#include "../Utility/Vector3d.h"

//class Particle;
//
//class Rigidbody;

class PhysicalComponent;

class Scene;

class GameObject;

class ForceGenerator {
public:
    static const char *forcesNamesList[4];

private:
    static constexpr const char *FORCE_TYPE = "ForceGenerator";

protected:
    GameObject *parentGameObject = nullptr;

public:
//    ForceGenerator();

    virtual ~ForceGenerator();

    explicit ForceGenerator(GameObject *gameObject = nullptr);

    virtual void addForce(PhysicalComponent *physicalComponent) = 0;

    virtual Vector3d getForceValue(PhysicalComponent *physicalComponent)
    {
        return {0, 0, 0};
    }

    virtual void drawGui(Scene *scene) = 0;

    virtual std::string getName() const = 0;

public:
    static ForceGenerator *createForceGenerator(const std::string &name, GameObject *gameObject);

};

#endif /* FORCEGENERATOR_H */
