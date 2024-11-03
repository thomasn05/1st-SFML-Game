#include "entity.h"

Entity::Entity(Vector2f position, Vector2f size, Color color)
{
	this->object.setSize(size); //Setup the RectangleShape
	this->object.setFillColor(color);
	this->object.setOrigin(size.x / 2, size.y / 2);
	this->object.setPosition(position);
}

void Entity::move(Vector2i pos)
{
	Vector2f curr_pos = this->object.getPosition();
	int dx = curr_pos.x - pos.x;
	int dy = curr_pos.y - pos.y;
	float angle = atan2(dy, dx);
	float new_x = curr_pos.x - speed * cos(angle);
	float new_y = curr_pos.y - speed * sin(angle);

	this->object.setPosition(new_x, new_y);
}

bool Entity::collide(Entity& other, int strictness)
{
	FloatRect this_bounds = this->object.getGlobalBounds();
	FloatRect other_bounds = other.object.getGlobalBounds();

	return this_bounds.intersects(other_bounds);
}

RectangleShape Entity::getRect() const
{
	return this->object;
}