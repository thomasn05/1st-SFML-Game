#include "bullet.h"
#include <iostream>

Vector2f bullet_spawn(const Entity& host, const float angle)
{
	RectangleShape host_rect = host.object;
	float x_dist = ((host_rect.getSize().x) / 2.f) + (BULLET_SIZE.x / 2.f) + 5; //How far from the host distance the bullet need to spawn
	float y_dist = ((host_rect.getSize().y) / 2.f) + (BULLET_SIZE.y / 2.f) + 5;
	Vector2f pos = host_rect.getPosition();

	Vector2f spawn = Vector2f(pos.x - cos(angle) * x_dist, pos.y - sin(angle)*y_dist); //spawn infront of player

	return spawn;
}

void Bullet::update(RenderWindow& wn) //Draw and check when target is reach
{
	bool reach_dest = point_collide(this->object.getPosition(), this->target_pos);
	if (reach_dest) { this->kill(); } //No longer will be in player bullet list
	else { this->move(this->target_pos, this->speed); }
	wn.draw(this->object);
}

void Bullet::set_target() //Set the target_pos
{
	int x_dist = static_cast<int>(MAX_BULLET_DISTANCE * cos(this->angle)); //Find the x and y distance 
	int y_dist = static_cast<int>(MAX_BULLET_DISTANCE * sin(this->angle));
	Vector2f curr_pos = this->object.getPosition();

	this->target_pos = Vector2i(static_cast<int>(curr_pos.x) - x_dist, static_cast<int>(curr_pos.y) - y_dist); //Convert to int 
}
