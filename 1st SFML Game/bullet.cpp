#include "bullet.h"
#include <iostream>

Vector2f bullet_spawn(Entity host, float angle)
{
	RectangleShape host_rect = host.getRect();
	float x_dist = ((host_rect.getSize().x) / 2.f) + (bullet_size.x / 2.f) + 5; //How far from the host distance the bullet need to spawn
	float y_dist = ((host_rect.getSize().y) / 2.f) + (bullet_size.y / 2.f) + 5;
	Vector2f pos = host_rect.getPosition();

	Vector2f spawn = Vector2f(pos.x - cos(angle) * x_dist, pos.y - sin(angle)*y_dist); //spawn infron of player

	return spawn;
}

void Bullet::update(RenderWindow& wn) //Draw and check when target is reach
{
	bool reach_dest = point_collide(this->getRect().getPosition(), this->target_pos);
	if (reach_dest) { this->alive = 0; } //No longer will be in player bullet list
	else { this->move(this->target_pos, this->speed); }
	wn.draw(this->getRect());
}

void Bullet::set_target() //Set the target_pos
{
	int x_dist = static_cast<int>(max_distance * cos(this->angle)); //Find the x and y distance 
	int y_dist = static_cast<int>(max_distance * sin(this->angle));
	Vector2f curr_pos = this->getRect().getPosition();

	this->target_pos = Vector2i(static_cast<int>(curr_pos.x) - x_dist, static_cast<int>(curr_pos.y) - y_dist); //Convert to int 
}

bool Bullet::get_status() //Alive status
{
	return this->alive;
}
