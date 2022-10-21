#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "../Vector3d/Vector3d.h"
#include "Camera.h"
#include "PhysicHandler.h"
#include "Axis.h"

class GameObject;

class Scene {
private:
    // Window size
    int windowHeight, windowWidth;

    // Scene elements
    Axis axis;
    Camera camera;
    PhysicHandler physicHandler;
    std::vector<GameObject *> gameObjects;

    // View settings
    bool wireFrame = false;
    bool showAxis = false;

    // OpenGL framebuffer
    unsigned int fbo;

public:
    Scene(int windowWidth, int windowHeight);

    void create();

    ~Scene();

    void destroy();

public:
    void update(float deltaTime);

    void draw(int display_w, int display_h);

    void updateViewport(int width, int height);

public:
    void addGameObject(GameObject *gameObject);

//    void translateCamera(Vector3d vector3D);
//
//    void rotateCamera(Vector3d vector3D, float angle);

public:
    unsigned int getFrameBufferId() const;

    std::vector<GameObject *> &getGameObjects();

    bool *getPtrWireFrameState();

    bool *getPtrShowAxis();

    GameObject *getPtrGameObjectByIndex(int index) const;
};

#endif //SCENE_H
