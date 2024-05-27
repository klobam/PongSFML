#pragma once
#include "Ball.h"
#include "PLayers.h"
class Game
{
private:
	Ball Shape;
	PLayers players;
	sf::RenderWindow window;
	int scorePlayer1 = 0;
	int scorePlayer2 = 0;
	bool isGameStarted = false;
public:
	Game();
	~Game();
	void run();
	void restart();

};

