#include "Collision.h"
#include <iostream>

// Returns the sides which the circle intersects the rectangle
std::vector<side> breakout::Collision::circleIntersectRectangle(CircleShape a_circle, RectangleShape a_rectangle)
{
	std::map<corner, Vector2f> corners = getCorners(a_rectangle);
	std::vector<side> result;

	if (circleIntersectLine(a_circle, corners[corner::lowerLeft], corners[corner::upperLeft]))
	{
		result.push_back(side::left);
	}

	if (circleIntersectLine(a_circle, corners[corner::upperLeft], corners[corner::upperRight]))
	{
		result.push_back(side::up);
	}

	if (circleIntersectLine(a_circle, corners[corner::upperRight], corners[corner::lowerRight]))
	{
		result.push_back(side::right);
	}

	if (circleIntersectLine(a_circle, corners[corner::lowerLeft], corners[corner::lowerRight]))
	{
		result.push_back(side::down);
	}

	return result;
}

// Returns which sides the center and offset by radius is outside the rectangle. Only need to be a bit outside to trigger.
std::vector<side> Collision::circleOutsideRectangle(CircleShape a_circle, RectangleShape a_rectangle)
{
	Vector2f center = getCenter(a_circle);
	std::vector<side> result;

	if (center.x - a_circle.getRadius() < 0)
	{
		result.push_back(side::left);
	}

	if (center.y - a_circle.getRadius() < 0)
	{
		result.push_back(side::up);
	}

	if (center.x + a_circle.getRadius() > a_rectangle.getSize().x)
	{
		result.push_back(side::right);
	}

	if (center.y + a_circle.getRadius() > a_rectangle.getSize().y)
	{
		result.push_back(side::down);
	}

	return result;
}

// Returns the sides where the first rectangle is outside the second rectangle. Only needs to be partly outside
std::vector<side> Collision::rectangleOutsideRectangle(RectangleShape a_rectangle1, RectangleShape a_rectangle2)
{
	std::map<corner, Vector2f> corners1 = getCorners(a_rectangle1);
	std::map<corner, Vector2f> corners2 = getCorners(a_rectangle2);
	std::vector<side> result;

	if (corners1[corner::lowerLeft].x < corners2[corner::lowerLeft].x)
	{
		result.push_back(side::left);
	}

	if (corners1[corner::lowerRight].x > corners2[corner::lowerRight].x)
	{
		result.push_back(side::right);
	}

	if (corners1[corner::lowerLeft].y > corners2[corner::lowerLeft].y)
	{
		result.push_back(side::down);
	}

	if (corners1[corner::upperLeft].y < corners2[corner::upperLeft].y)
	{
		result.push_back(side::up);
	}
	
	return result;
}

// Returns if circle intersects line
bool Collision::circleIntersectLine(CircleShape a_circle, Vector2f a_point1, Vector2f a_point2)
{
	// Check collision with side and corners

	// First corner
	if (pointInCircle(a_point1, a_circle))
	{
		return true;
	}

	// Second corner
	if (pointInCircle(a_point2, a_circle))
	{
		return true;
	}

	// Side
	Vector2f center = getCenter(a_circle);
	if (a_point1.x == a_point2.x)
	{
		double length = distancePointToPoint(center, Vector2f(a_point1.x, center.y));
		if (length < a_circle.getRadius())
		{
			if (a_point1.y < a_point2.y)
			{
				Vector2f temp = a_point1;
				a_point1 = a_point2;
				a_point2 = temp;
			}

			if (center.y <= a_point1.y && center.y >= a_point2.y)
			{
				return true;
			}
		}
	}

	if (a_point1.y == a_point2.y)
	{
		double length = distancePointToPoint(center, Vector2f(center.x, a_point1.y));
		if(length < a_circle.getRadius())
		{
			if (a_point1.x < a_point2.x)
			{
				Vector2f temp = a_point1;
				a_point1 = a_point2;
				a_point2 = temp;
			}

			if (center.x <= a_point1.x && center.x >= a_point2.x)
			{
				return true;
			}
		}
	}

	return false;
}

// Returns if circle is inside rectangle
bool Collision::circleInsideRectangle(CircleShape a_circle, RectangleShape a_rectangle)
{
	return !circleInsideRectangle(a_circle, a_rectangle);
}

// Returns if point is inside circle
bool Collision::pointInCircle(Vector2f a_point, CircleShape a_circle)
{
	Vector2f center = getCenter(a_circle);
	double length = distancePointToPoint(center, a_point);
	
	return length <= a_circle.getRadius();
}

// Returns if point is inside rectangle
bool Collision::pointInRectangle(Vector2f a_point, RectangleShape a_rectangle)
{
	std::map<corner, Vector2f> corners = getCorners(a_rectangle);
	
	if (a_point.x >= corners[corner::upperLeft].x && a_point.x <= corners[corner::lowerRight].x && a_point.y >= corners[corner::upperLeft].y && a_point.y <= corners[corner::lowerRight].x)
	{
		return true;
	}
			
	return false;
}

// Returns distance between two points
double Collision::distancePointToPoint(Vector2f a_point1, Vector2f a_point2)
{
	double dx = a_point1.x - a_point2.x;
	double dy = a_point1.y - a_point2.y;
	return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
}

// Returns the corners of an rectangle as vectors
std::map<corner, Vector2f> Collision::getCorners(RectangleShape a_rectangle)
{
	// Position - origin gives upper left corner. To get other position add width and height where needed.
	Vector2f upperLeft(a_rectangle.getPosition().x - a_rectangle.getOrigin().x, a_rectangle.getPosition().y - a_rectangle.getOrigin().y);
	Vector2f upperRight(a_rectangle.getPosition().x - a_rectangle.getOrigin().x + a_rectangle.getSize().x, a_rectangle.getPosition().y - a_rectangle.getOrigin().y);
	Vector2f lowerLeft(a_rectangle.getPosition().x - a_rectangle.getOrigin().x, a_rectangle.getPosition().y - a_rectangle.getOrigin().y + a_rectangle.getSize().y);
	Vector2f lowerRight(a_rectangle.getPosition().x - a_rectangle.getOrigin().x + a_rectangle.getSize().x, a_rectangle.getPosition().y - a_rectangle.getOrigin().y + a_rectangle.getSize().y);

	std::map<corner, Vector2f> corners;
	corners[corner::upperLeft] = upperLeft;
	corners[corner::upperRight] = upperRight;
	corners[corner::lowerLeft] = lowerLeft;
	corners[corner::lowerRight] = lowerRight;

	return corners;
}

// Gives center of circle as vector
Vector2f Collision::getCenter(CircleShape a_circle)
{
	Vector2f center(a_circle.getPosition().x - a_circle.getOrigin().x + a_circle.getRadius(), a_circle.getPosition().y - a_circle.getOrigin().y + a_circle.getRadius());
	return center;
}

// Gives center of rectangle as vector
Vector2f Collision::getCenter(RectangleShape a_rectangle)
{
	Vector2f center(a_rectangle.getPosition().x - a_rectangle.getOrigin().x + a_rectangle.getSize().x / 2, a_rectangle.getPosition().y - a_rectangle.getOrigin().y + a_rectangle.getSize().y / 2);
	return center;
}
