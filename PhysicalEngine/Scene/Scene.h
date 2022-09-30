#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "../Vector3d/Vector3d.h"
#include "Camera.h"
#include "PhysicHandler.h"
#include "PhysicHandler.h"

class GameObject;

class Scene {
private:
    int windowHeight, windowWidth;
    Camera camera;
    PhysicHandler physicHandler;
    std::vector<GameObject *> gameObjects;
    bool wireFrame = false;
    PhysicHandler m_integrator;

    unsigned int fbo;

public:
    Scene(int windowWidth, int windowHeight);

    void create();

    ~Scene();

    void destroy();

    void updateViewport(int width, int height);

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

    unsigned int getFrameBufferId();

    GameObject *getPtrGameObjectByName(std::string name);
};

#endif //SCENE_H
