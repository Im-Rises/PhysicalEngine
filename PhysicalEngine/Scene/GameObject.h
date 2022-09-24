#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "Shader/Shader.h"
#include "Mesh/Mesh.h"
#include "../Vector3D/Vector3d.h"

class GameObject {
private:
    std::string name;

    Vector3D position;
    float width, height, depth;
    float rotationX, rotationY, rotationZ;
    float scaleX, scaleY, scaleZ;
    float colorR, colorG, colorB, colorA;

    Mesh mesh;
    unsigned int VBO, VAO, EBO;
    Shader shader;
    bool openglIndicedMesh;
    // std::vector<GameObject> children;
    // std::vector<Component> components;


public:
    GameObject(Mesh mesh);

private:
    void create();


public:
    ~GameObject();

private:
    void destroy();

public:
    void update();

    void draw(int display_w, int display_h, glm::mat4 view);

    std::string getName();
};


#endif //GAMEOBJECT_H
