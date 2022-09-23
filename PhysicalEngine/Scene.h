#ifndef DEF_SCENE
#define DEF_SCENE

#include <vector>

#include "GameObject.h"

class Scene {
private:
    std::vector<GameObject *> gameObjects;
//    GameObject gameObject;
//    Camera camera;

public:
    Scene();

    ~Scene();

    void update();

    void draw();
};

#endif //DEF_SCENE
