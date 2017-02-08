#pragma once
#include "paddle.h"
#include "ball.h"
#include <SFML/Graphics.hpp>
#include"Constants.h"
#include"brick.h"

using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void start();
	void events();
	void update(Time elapsed);
	void draw();

	void createbricks();

private:
	RenderWindow window;
	Clock clock;

	Paddle paddle;
	Ball ball;
	std::vector<Brick*> bricks;
};