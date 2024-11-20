#include <SFML/Graphics.hpp>

using namespace sf;

#pragma once

/*
* @brief //Get angle between two position
* @param point1: a position Vecotor
* @param point2: a position Vecotr (usually a mouse position which is represented as Vector2i)
* @return angle float in radians
*/
float get_angle(Vector2f point1, Vector2i point2); //Get the angle from the entity to a target

/*
* @brief //Check collision between 2 points
* @param point1: a position Vecotor
* @param point2: a position Vecotr (usually a mouse position which is represented as Vector2i)
* @return True if collide, False if not
*/
bool point_collide(Vector2f p1, Vector2i p2); //Check if two point are colliding

/*
* @brief converts a radian to a degree
* @param radian: the angle in radian
* @return the angle in degrees
*/
float radians_to_degree(float radians);

//SAT collision detection
//float dot_product(Vector2f v1, Vector2f v2);
//
//std::pair<float, float> project(std::vector<Vector2f> corners, Vector2f axis);
//
//bool overlap(std::pair<float, float> proj1, std::pair<float, float> proj2);
//
//bool SAT_Collision(RectangleShape rect1, RectangleShape rect2);

