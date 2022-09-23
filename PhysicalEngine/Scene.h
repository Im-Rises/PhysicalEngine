#ifndef DEF_SCENE
#define DEF_SCENE

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
};

#endif //DEF_SCENE
