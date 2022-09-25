#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "../Vector3D/Vector3d.h"
#include "GameObject.h"
#include "Camera.h"

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

    void translateCamera(Vector3D vector3D);

    size_t getNbGameObjects();

    std::string getGameObjectName(int index);

public:
    bool *getWireFrameStatePtr();
};

#endif //SCENE_H
