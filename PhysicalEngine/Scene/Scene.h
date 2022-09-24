#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "GameObject.h"
#include "Camera.h"

class Scene {
private:
    Camera camera;
    std::vector<GameObject *> gameObjects;

public:
    Scene();

    ~Scene();

    void update();

    void draw(int display_w, int display_h);

    void translateCamera();

    size_t getNbGameObjects();

    std::string getGameObjectName(int index);
};

#endif //SCENE_H
