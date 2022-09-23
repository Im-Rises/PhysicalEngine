#ifndef DEF_SCENE
#define DEF_SCENE

#include <vector>

class Scene {
private:
    std::vector<GameObject> gameObjects;
public:
    Scene();

    ~Scene();

    void clock();
};

#endif //DEF_SCENE
