#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "../Vector3D/Vector3d.h"
#include "Camera.h"

class GameObject;

class Scene {
private:
    Camera camera;
    std::vector<GameObject *> gameObjects;
    bool wireFrame = false;

public:
    Scene();

    ~Scene();

    void update();

    void draw(int display_w, int display_h);

    void translateCamera(Vector3d vector3D);

    void rotateCamera(Vector3d vector3D, float angle);

    size_t getNbGameObjects();

    std::string getGameObjectName(int index);

public:
    bool *getWireFrameStatePtr();
};

#endif //SCENE_H
