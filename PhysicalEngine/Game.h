#ifndef GAME_H
#define GAME_H

class Particule;

class Scene;

class Game {
private:
    Particule *m_p;
    float m_speed = 0.5f;

public:
    Game();

    ~Game();

    void setSpeed(float speed);

    void start(Scene *scene);

    void goLeft();

    void goRight();

    void goUp();

    void goDown();
};

#endif //GAME_H
