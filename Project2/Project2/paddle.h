#pragma once
#include <SFML/Graphics.hpp>
#include "paddle.h"

using namespace sf;

class Paddle
{
public:
	Paddle();
	RectangleShape getShape();
	void updatePosition(Vector2i mousePosition);

private:
	RectangleShape shape;
};