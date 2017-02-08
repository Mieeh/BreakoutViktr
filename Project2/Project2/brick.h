#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

using namespace sf;

class Brick
{
public:
	Brick(Vector2f a_startPos);
	RectangleShape& getShape();

	bool isDead() { return dead; }

private:
	RectangleShape shape;
	float w, h;
	bool dead;
};