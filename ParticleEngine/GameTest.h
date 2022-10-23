#ifndef GAME_H
#define GAME_H

class Particule;

class Scene;

//class PhysicHandler;

class GameTest {
private:
	Particule* m_p;
	Particule* m_p2;
	float m_speed = 0.5f;

public:
	GameTest();

	~GameTest();

	void start(Scene* scene);

public:

	float* getPtrSpeed();
};

#endif //GAME_H
