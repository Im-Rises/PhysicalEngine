#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "../Octree/Octree.h"
#include "../ParticleContact/ContactGenerator/ParticleCollide.h"
#include "../ParticleContact/ParticleContactResolver.h"
#include "../ParticleContact/ParticlesContactGeneratorRegistry.h"
#include "../Utility/Vector3d.h"
//#include "Axis.h"
#include "Camera.h"
#include "PhysicHandler.h"

#define PHYSIC_UPDATE_PER_SECOND 50

class GameObject;

class Scene {
private:
    // Window size
    int windowHeight, windowWidth;

    // Scene elements
//    Axis axis;
    Camera camera;
    PhysicHandler physicHandler;
    std::vector<GameObject *> gameObjects;
    ParticleContactGeneratorRegistry particleContactGeneratorRegistry = ParticleContactGeneratorRegistry(1000000);
    ParticleContactResolver particleContactResolver = ParticleContactResolver(2000000);
    ParticleCollide particleCollide;
    Octree octree;


    // View settings
    bool wireFrame = false;
//    bool showAxis = false;

    // OpenGL framebuffer
    unsigned int fbo;

    float physicalUpdateTimer = 0;

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

    //    void translateCamera(const Vector3d& vector3D);

    //    void rotateCamera(Vector3d vector3D, float angle);

    //    void setCameraPosition(const Vector3d& position);

public:
    ParticleContactGeneratorRegistry getParticleContactGeneratorRegistry();

//    void addParticleCollider(ParticleCollider* particleCollider);

    void collectParticleColliders();

    void cleanParticleColliders();

    unsigned int getFrameBufferId() const;

    std::vector<GameObject *> &getGameObjects();

#ifndef __EMSCRIPTEN__

    bool *getPtrWireFrameState();

#endif

//    bool *getPtrShowAxis();

    GameObject *getPtrGameObjectByIndex(int index) const;

    Camera *getCameraPtr();

    void deleteGameObject(GameObject *gameObject);

    GameObject *createGameObject(std::string name);
};

#endif // SCENE_H
