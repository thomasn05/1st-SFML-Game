#include <SFML/Graphics.hpp>
#include <vector>

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

/*
* @brief give the dot product of two vector
* @param v1: vector 1
* @param v2: vector 2
* @return a scalar float
*/
float dot_product(const Vector2f& v1, const Vector2f& v2); //Use to find distance from corner point to edge norm axis

/*
* @brief project each corner onto the axis and return the maximum and minimum corner on that axis
* @param corners: a vector contain all corners of a polygon
* @param axis: a edge norm axis (perpendicular axis to the polygon's edges)
* @return pair(min, max)
*/
std::pair<float, float> project(const std::vector<Vector2f>& corners, const Vector2f& axis);

/*
* @brief return a vector of the edge norm of the polygon
* @param corners: the corners of the polygon
* @return a vector contain the edge norms
*/
std::vector<Vector2f> get_edge(const std::vector<Vector2f>& corners);

Vector2f dist_component(const float angle, const int distance);