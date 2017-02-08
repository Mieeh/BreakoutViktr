#include "paddle.h"

Paddle::Paddle()
{
	int width = 100;
	int height = 20;
	shape.setOrigin(width / 2, height / 2);
	shape.setSize(Vector2f(width, height));
	shape.setFillColor(Color(200, 38, 105));
	shape.setPosition(Vector2f(400, 570));
}

RectangleShape Paddle::getShape()
	{
		return shape;
	};

void Paddle::updatePosition(Vector2i mousePosition)
{
	shape.setPosition(Vector2f(mousePosition.x, shape.getPosition().y));
};