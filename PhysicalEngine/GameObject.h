#ifndef DEF_GAMEOBJECT
#define DEF_GAMEOBJECT

#include <vector>
#include "Shader/Shader.h"

class GameObject {
private:
    float x, y, z;
    float width, height, depth;
    float rotationX, rotationY, rotationZ;
    float scaleX, scaleY, scaleZ;
    float colorR, colorG, colorB, colorA;

    unsigned int VBO, VAO;
    Shader shader;
    std::vector<float> vertices;
    // std::vector<GameObject> children;
    // std::vector<Component> components;

public:
    GameObject();

    ~GameObject();

    void update();

    void draw();

//    GameObject(GameObject &gameObject);

//    GameObject operator=(const GameObject &gameObj);
};


#endif //DEF_GAMEOBJECT
