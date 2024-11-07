#include "entity.h"

/**
*@brief create an entity object
* 
* @param position: spawning location of the Entity
* @param size: size of Entity
* @param color: color of Entity
* @param angle: the rotation of the Entity
*/
Entity::Entity(Vector2f position, Vector2f size, Color color, float angle) //Constructor
{
	//Setup the RectangleShape
	this->object.setSize(size);
	this->object.setFillColor(color);
	this->object.setOrigin(size.x / 2, size.y / 2); //Set the origin to the middle of the Rectangle
	this->object.setPosition(position);
	this->object.setRotation(angle);
}

/*
*@brief move the Entity towards a specific target
* @param target: the target position where the Entity is moving towards (usually a mouse position which is represented in Vector2i)
* @param speed: how much the Entity should move each frame
*/
void Entity::move(Vector2i target, int speed)
{
	Vector2f new_pos = this->get_component(target, speed);

	this->object.setPosition(new_pos);
}

/*
* @breif Check for collision between two Entity
* @param other: another Entity object
* @return True if collided, False if not
*/
bool Entity::collide(Entity& other) const
{
	FloatRect this_bounds = this->object.getGlobalBounds();
	FloatRect other_bounds = other.object.getGlobalBounds();

	return this_bounds.intersects(other_bounds); //Check if the boundds intersect
}

/*
* @brief get the Rectangle of the Entity
*/
RectangleShape Entity::getRect() const
{
	return this->object;
}

/*
* @brief Get the x and y component between the Entity object and a target based on a certain distance
* @param target: the target pos (usually a mouse position which is represented as Vector2i)
* @param distance: the hypothenuse between the two point
* @return a Vector2f(x_component, y_component)
*/
Vector2f Entity::get_component(Vector2i target, int distance) const 
{
	Vector2f curr_pos = this->object.getPosition();
	
	float angle = get_angle(curr_pos, target);

	float new_x = curr_pos.x - distance * cos(angle); //Use trig to find how much to move in the x and y
	float new_y = curr_pos.y - distance * sin(angle);

	return Vector2f(new_x, new_y);
}

/*
* @brief //Get angle between two position
* @param point1: a position Vecotor
* @param point2: a position Vecotr (usually a mouse position which is represented as Vector2i)
* @return angle float in radians
*/
float get_angle(Vector2f point1, Vector2i point2)
{
	float dx = point1.x - point2.x; //Get their difference in x and y
	float dy = point1.y - point2.y;

	float angle = atan2(dy, dx); //Find theta

	return angle;
}
/*
* @brief //Check collision between 2 points
* @param point1: a position Vecotor
* @param point2: a position Vecotr (usually a mouse position which is represented as Vector2i)
* @return True if collide, False if not
*/

bool point_collide(Vector2f p1, Vector2i p2)
{
	return (abs(p1.x - p2.x) < 3) && (abs(p1.y - p2.y) < 3);  //Check the player and the target pos (usually a mouse position) is within 3 pixel of each other
}
