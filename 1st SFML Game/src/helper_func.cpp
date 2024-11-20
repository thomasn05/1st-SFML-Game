#include "helper_func.h"

float get_angle(Vector2f point1, Vector2i point2)
{
	float dx = point1.x - point2.x; //Get their difference in x and y
	float dy = point1.y - point2.y;

	float angle = atan2(dy, dx); //Find theta

	return angle;
}

bool point_collide(Vector2f p1, Vector2i p2)
{
	return (abs(p1.x - p2.x) < 3) && (abs(p1.y - p2.y) < 3);  //Check the player and the target pos (usually a mouse position) is within 3 pixel of each other
}

float radians_to_degree(float radians)
{
	return (radians * 180 / 3.14f) - 90;
}

//float dot_product(Vector2f v1, Vector2f v2)
//{
//	return 0.0f;
//}
//
//std::pair<float, float> project(std::vector<Vector2f> corners, Vector2f axis)
//{
//	return std::pair<float, float>();
//}
//
//bool overlap(std::pair<float, float> proj1, std::pair<float, float> proj2)
//{
//	return false;
//}
//
//bool SAT_Collision(RectangleShape rect1, RectangleShape rect2)
//{
//	return false;
//}

