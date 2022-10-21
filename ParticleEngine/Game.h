#ifndef GAME_H
#define GAME_H

#include "Force/Gravity.h"
#include "Force/AnchoredSpring.h"

class Particle;

class Scene;

class Game {
private:
    Particle *m_p;
    float m_speed = 0.5f;
    Gravity m_G;
    AnchoredSpring m_S = AnchoredSpring(Vector3d(5, 0, 0), 155, 1);

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

#endif //GAME_H
