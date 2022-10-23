#ifndef GAMETEST_H
#define GAMETEST_H

#include "Force/Gravity.h"
#include "Force/AnchoredSpring.h"

class Particle;

class Scene;

class GameTest {
private:
	Particle* m_p;
	float m_speed = 0.5f;
	Gravity m_G;
	AnchoredSpring m_S = AnchoredSpring(Vector3d(5, 0, 0), 155, 1);

public:
	GameTest();

	~GameTest();

	void start(Scene* scene);

	void goLeft();

	void goRight();

	void goUp();

	void goDown();

public:
	float* getPtrSpeed();
};

#endif //GameTest_H
