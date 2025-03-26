#include "helper_func.h"

#pragma once
class Entity
{
public:
	Time lifespan = seconds(1); // @brief lifewspan of an object

	RectangleShape object; //@breif the RectangleShape

	/**
	*@brief create an entity object
	*
	* @param position: spawning location of the Entity
	* @param size: size of Entity
	* @param color: color of Entity
	* @param angle: the rotation of the Entity
	*/
	Entity(const Vector2f& position, const Vector2f& size, const Color color, const float angle = 0);
	~Entity() = default; //Destructor

	Entity& operator=(const Entity& other);

	/*
	*@brief move the Entity towards a specific target
	* @param target: the target position where the Entity is moving towards (usually a mouse position which is represented in Vector2i)
	* @param speed: how much the Entity should move each frame
	*/
	void move(const Vector2i& target, const int speed);

	/*
	* @breif Check for collision between two Entity using SAT
	* @param other: another Entity object
	* @return True if collided, False if not
	*/
	bool collided_with(const Entity& other); //Collision Detection

	/*
	* @brief check if the Entity object lifespan is 0s
	*/
	bool is_dead() const;

	/*
	* @brief kill the Entity object by setting its lifespan to 0s
	*/
	void kill();
	
	/*
	* @brief get the  four corners of the Entity
	* @return vector {top-right, top-left, bottom-right, bottom left}
	*/
	std::vector<Vector2f> get_corners() const;
};