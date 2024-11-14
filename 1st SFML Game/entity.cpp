#include "entity.h"

Entity::Entity(Vector2f position, Vector2f size, Color color, float angle) //Constructor
{
	//Setup the RectangleShape
	this->object.setSize(size);
	this->object.setFillColor(color);
	this->object.setOrigin(size.x / 2, size.y / 2); //Set the origin to the middle of the Rectangle
	this->object.setPosition(position);
	this->object.setRotation(angle);
}

void Entity::move(Vector2i target, int speed)
{
	Vector2f new_pos = this->get_component(target, speed);

	this->object.setPosition(new_pos);
}

bool Entity::collided_with(Entity other) const
{
	FloatRect this_bounds = this->object.getGlobalBounds();
	FloatRect other_bounds = other.object.getGlobalBounds();

	return this_bounds.intersects(other_bounds); //Check if the boundds intersect
}

Vector2f Entity::collision_pos(Entity other)
{
	FloatRect intersection;
	this->object.getGlobalBounds().intersects(other.object.getGlobalBounds(), intersection);
	return Vector2f(intersection.left, intersection.top);
}

Vector2f Entity::get_component(Vector2i target, int distance) const 
{
	Vector2f curr_pos = this->object.getPosition();
	
	float angle = get_angle(curr_pos, target);

	float new_x = curr_pos.x - distance * cos(angle); //Use trig to find how much to move in the x and y
	float new_y = curr_pos.y - distance * sin(angle);

	return Vector2f(new_x, new_y);
}

bool Entity::is_dead()
{
	return this->lifespan == seconds(0);
}

void Entity::kill()
{
	this->lifespan = seconds(0);
}

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
