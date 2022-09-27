#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "../Vector3d/Vector3d.h"
#include "Camera.h"
#include "Components/Particule/Integrator/Integrator.h"

class GameObject;

class Scene {
private:
    Camera camera;
    std::vector<GameObject *> gameObjects;
    bool wireFrame = false;
    Integrator m_integrator;

public:
    Scene();

    ~Scene();

    void update();

    void updatePhysics(float time);

    void addPhysicalComponent();

    void draw(int display_w, int display_h);

    void translateCamera(Vector3d vector3D);

    void rotateCamera(Vector3d vector3D, float angle);

    size_t getNbGameObjects();

    std::string getGameObjectName(int index);

    void addGameObject(GameObject *gameObject);

public:
    bool *getWireFrameStatePtr();
};

#endif //SCENE_H
