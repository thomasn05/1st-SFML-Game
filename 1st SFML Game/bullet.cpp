#include "bullet.h"
#include <iostream>

Bullet::Bullet(Entity host, float angle) : Entity(this->getRect().getPosition(), this->size, Color::Red)
{
	FloatRect host_bound = host.getRect().getGlobalBounds();
	float x_dist = ((host_bound.getSize().x) / 2.f) + (this->size.x / 2.f); //How far from the host distance the bullet need to spawn
	float y_dist = ((host_bound.getSize().y) / 2.f) +  (this->size.y/ 2.f);
	Vector2f pos = host_bound.getPosition();

	Vector2f spawn = Vector2f(pos.x - angle * x_dist, pos.y - angle * max_distance);
	this->getRect().setPosition(spawn);
}

void Bullet::update(RenderWindow& wn)
{
	wn.draw(this->getRect());
}