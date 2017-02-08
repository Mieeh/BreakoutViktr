#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

using namespace sf;

enum class side{left, up, right, down};
enum class corner{upperLeft, upperRight, lowerLeft, lowerRight};
class Collision
{
public:

	/// <summary>
	/// Return which sides the circle intersects rectangle (nothing if completely inside or outside).
	/// </summary>
	/// <param name="a_circle">CircleShape to check.</param>
	/// <param name="a_rectangle">RectangleShape to check.</param>
	/// <returns>Vector containing sides (enum) that intersects.</returns> 
	static std::vector<side> circleIntersectRectangle(CircleShape a_circle, RectangleShape a_rectangle);

	/// <summary>
	/// Return which sides the circle is outside the rectangle (only part of circle needs to be outside).
	/// </summary>
	/// <param name="a_circle">CircleShape to check if outside.</param>
	/// <param name="a_rectangle">Boundary RectangleShape.</param>
	/// <returns>Vector containing sides (enum) that circle is outside rectangle.</returns>
	static std::vector<side> circleOutsideRectangle(CircleShape a_circle, RectangleShape a_rectangle);

	/// <summary>
	/// Return which sides rectangle1 is outside rectangle2 (only part of rectangle1 needs to be outside).
	/// </summary>
	/// <param name="a_rectangle1">RectangleShape to check if it is outside.</param>
	/// <param name="a_rectangle2">Boundary RectangleShape.</param>
	/// <returns>Vector containing sides (enum) that first rectangle is outside second rectangle.</returns>
	static std::vector<side> rectangleOutsideRectangle(RectangleShape a_rectangle1, RectangleShape a_rectangle2);





	/// <summary>
	/// Return if the circle intersects the line (means the line and circle is overlapping).
	/// </summary>
	/// <param name="a_circle">Circle to check if it overlaps.</param>
	/// <param name="a_point1">First point (Vector2f) of line to check.</param>
	/// <param name="a_point2">Second point (Vector2f) of line to check.</param>
	/// <returns>true if the circle intersects the line.</returns>
	static bool circleIntersectLine(CircleShape a_circle ,Vector2f a_point1, Vector2f a_point2);

	/// <summary>
	/// Return if the circle is inside the rectangle (completely inside).
	/// </summary>
	/// <param name="a_circle">CircleShape to check if it is inside.</param>
	/// <param name="a_rectangle">Boundary RectangleShape.</param>
	/// <returns>true if the circle is inside the rectangle.</returns>
	static bool circleInsideRectangle(CircleShape a_circle, RectangleShape a_rectangle);

	/// <summary>
	/// Return if the point is inside the circle
	/// </summary>
	/// <param name="a_point">Point (Vector2f) to check if it is inside.</param>
	/// <param name="a_circle">Boundary CircleShape.</param>
	/// <returns>true if point is inside the circle.</returns>
	static bool pointInCircle(Vector2f a_point, CircleShape a_circle);

	/// <summary>
	/// Return if the point is inside the rectangle
	/// </summary>
	/// <param name="a_point">Point (Vector2f) to check if it is inside.</param>
	/// <param name="a_rectangle">Boundary RectangleShape.</param>
	/// <returns>true if point is inside the rectangle.</returns>
	static bool pointInRectangle(Vector2f a_point, RectangleShape a_rectangle);

	/// <summary>
	/// Return the distance between two points (length of line).
	/// </summary>
	/// <param name="a_point1">First point (Vector2f).</param>
	/// <param name="a_point2">Second point (Vector2f).</param>
	/// <returns>distance (double) between points.</returns>
	static double Collision::distancePointToPoint(Vector2f a_point1, Vector2f a_point2);



	/// <summary>
	/// Return the four corners as points from the Rectangle.
	/// </summary>
	/// <param name="a_rectangle">RectangleShape to get corners (points) from.</param>
	/// <returns>Map with key corner and value Vector2f wich are the different points of the corners.</returns>
	static std::map<corner, Vector2f> getCorners(RectangleShape a_rectangle);

	/// <summary>
	/// Return the center of an circle.
	/// </summary>
	/// <param name="a_circle">Circle to get centerpoint from.</param>
	/// <returns>Vector2f which is the centerpoint of the circle.</returns>
	static Vector2f getCenter(CircleShape a_circle);

	/// <summary>
	/// Return the center of an rectangle.
	/// </summary>
	/// <param name="a_rectangle">Rectangle to get centerpoint from.</param>
	/// <returns>Vector2f which is the centerpoint of the rectangle.</returns>
	static Vector2f getCenter(RectangleShape a_rectangle);
};
