#include "brick.h"

Brick::Brick(Vector2f a_startPos)
{
	shape.setSize(Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
	shape.setPosition(a_startPos);
	shape.setFillColor(Color::Yellow);
	dead = false;
}

RectangleShape& Brick::getShape()
{
	return shape;
}
