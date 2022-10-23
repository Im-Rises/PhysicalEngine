#ifndef COLLIDERHANDLER_H
#define COLLIDERHANDLER_H

class Scene;

class ColliderHandler {
private:
    Scene *scene;

public:
    ColliderHandler(Scene *scene);

    ~ColliderHandler();

    void update(float deltaTime);

//    void addCollider(Collider *collider);
//
//    void removeCollider(Collider *collider);
};


#endif //COLLIDERHANDLER_H
