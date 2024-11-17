#include "helper_func.h"

#pragma once
class Entity
{

public:
	Time lifespan = seconds(1); // @brief lifewspan of an object

	RectangleShape object;

	/**
	*@brief create an entity object
	*
	* @param position: spawning location of the Entity
	* @param size: size of Entity
	* @param color: color of Entity
	* @param angle: the rotation of the Entity
	*/
	Entity(Vector2f position, Vector2f size, Color color, float angle = 0);
	~Entity() = default; //Destructor

	/*
	*@brief move the Entity towards a specific target
	* @param target: the target position where the Entity is moving towards (usually a mouse position which is represented in Vector2i)
	* @param speed: how much the Entity should move each frame
	*/
	void move(Vector2i target, int speed);

	/*
	* @breif Check for collision between two Entity
	* @param other: another Entity object
	* @return True if collided, False if not
	*/
	bool collided_with(Entity other) const; //Collision Detection

	//Vector2f collision_pos(Entity other);

	/*
	* @brief Get the x and y component between the Entity object and a target based on a certain distance
	* @param target: the target pos (usually a mouse position which is represented as Vector2i)
	* @param distance: the hypothenuse between the two point
	* @return a Vector2f(x_component, y_component)
	*/
	Vector2f get_component(Vector2i target, int distance) const; //Get the x and y component distance from the entity to

	/*
	* @brief check if the Entity object lifespan is 0s
	*/
	bool is_dead();

	/*
	* @brief kill the Entity object by setting its lifespan to 0s
	*/
	void kill();
};