#ifndef GAME_H
#define GAME_H

#include "Particule/Particule.h"
#include "Scene/Scene.h"

class Game {
private:
	Particule *m_p;

public:
	Game();
	~Game();
	void start(Scene scene);
	void goLeft();
	void goRight();
	void goUp();
	void goDown();
};
#endif //GAME_H
