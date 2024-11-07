#include "bullet.h"
#include <iostream>

Vector2f bullet_spawn(Entity host, float angle)
{
	RectangleShape host_rect = host.getRect();
	float x_dist = ((host_rect.getSize().x) / 2.f) + (bullet_size.x / 2.f) + 5; //How far from the host distance the bullet need to spawn
	float y_dist = ((host_rect.getSize().y) / 2.f) + (bullet_size.y / 2.f) + 5;
	Vector2f pos = host_rect.getPosition();

	Vector2f spawn = Vector2f(pos.x - cos(angle) * x_dist, pos.y - sin(angle)*y_dist);

	return spawn;
}

void Bullet::update(RenderWindow& wn)
{
	this->move(this->target_pos, this->speed);
	wn.draw(this->getRect());
}

void Bullet::set_target()
{
	int x_dist = static_cast<int>(max_distance * cos(this->angle));
	int y_dist = static_cast<int>(max_distance * sin(this->angle));
	Vector2f curr_pos = this->getRect().getPosition();

	this->target_pos = Vector2i(static_cast<int>(curr_pos.x) + x_dist, static_cast<int>(curr_pos.y) + y_dist);
}