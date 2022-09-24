#ifndef DEF_GAMEOBJECT
#define DEF_GAMEOBJECT

#include <vector>
#include "Shader/Shader.h"
#include "Mesh/Mesh.h"
#include "Vector3D/Vector3d.h"

class GameObject {
private:
    Vector3D position;
    float width, height, depth;
    float rotationX, rotationY, rotationZ;
    float scaleX, scaleY, scaleZ;
    float colorR, colorG, colorB, colorA;

    Mesh mesh;
    std::string name;
    unsigned int VBO, VAO;
    Shader shader;
//    std::vector<float> vertices;
    // std::vector<GameObject> children;
    // std::vector<Component> components;


public:
    GameObject(Mesh mesh, bool indiced = true);

//    GameObject(std::vector<float> vertices);

private:
    void create();

    
public:
    ~GameObject();

    void update();

    void draw(int display_w, int display_h, glm::mat4 view);

//    GameObject(GameObject &gameObject);

//    GameObject operator=(const GameObject &gameObj);

    std::string getName();
};


#endif //DEF_GAMEOBJECT
