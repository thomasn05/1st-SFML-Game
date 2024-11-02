#include "entity.h"

Entity::Entity(Vector2f position, Vector2f size, Color color)
{
	this->object.setPosition(position); //Setup the RectangleShape
	this->object.setSize(size);
	this->object.setFillColor(color);

	this->position = position;
	this->size = size;
}

void Entity::draw(RenderWindow &wn) const
{
	wn.draw(this->object);
}