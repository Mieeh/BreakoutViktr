#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
public:
	Ball();
	CircleShape getShape();

	void update(Time e_elapsed);

private:
	double vx = 200;
	double vy = 300;
	CircleShape shape;
};