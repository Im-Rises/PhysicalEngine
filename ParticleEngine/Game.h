#ifndef GAME_H
#define GAME_H

#include "Force/Forces/Gravity.h"
#include "Force/Forces/AnchoredSpring.h"

class Particle;

class Scene;

class Game {
private:
    Scene *scene = nullptr;
    float m_speed = 5.0f;

public:
    Game();

    ~Game();

    void start(Scene *scene);

    void goLeft();

    void goRight();

    void goUp();

    void goDown();

public:
    float *getPtrSpeed();
};

#endif // GAME_H
