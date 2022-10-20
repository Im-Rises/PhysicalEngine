#ifndef GAME_H
#define GAME_H

class Particle;

class Scene;

//class PhysicHandler;

class Game {
private:
    Particle *m_p;
    float m_speed = 0.5f;

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
