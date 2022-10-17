#ifndef GAME_H
#define GAME_H

class Particule;

class Scene;

//class PhysicHandler;

class Game {
private:
    Particule *m_p;
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
    void setSpeed(float speed);

    float *getPtrSpeed();
};

#endif //GAME_H
