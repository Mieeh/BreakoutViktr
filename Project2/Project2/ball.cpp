#include "ball.h"

Ball::Ball()
{
	int radius = 20;
	shape.setOrigin(radius, radius);
	shape.setRadius(radius);
	shape.setFillColor(Color(200, 38, 105));
	shape.setPosition(Vector2f(400 - radius, 300 - radius));
}

CircleShape Ball::getShape()
{
	return shape;
}

void Ball::update(Time e_elapsed)
{
	shape.move(Vector2f(vx*e_elapsed.asSeconds(), vy*e_elapsed.asSeconds()));
}