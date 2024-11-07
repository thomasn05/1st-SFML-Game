#include "bullet.h"

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
	wn.draw(this->getRect());
}