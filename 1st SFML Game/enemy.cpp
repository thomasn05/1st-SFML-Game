#include "enemy.h"
#include <random>

int coord(float coord, int range)
{
	int pos;

	while (true)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(25, range - 25);

		pos = distrib(gen);

		if (abs(pos - coord) >= spawn_dist) { break; }
	}

	return pos;
}

Vector2f spawn(Player player)
{
	float x_pos = coord(player.object.getPosition().x, 1400);
	float y_pos = coord(player.object.getPosition().y, 1000);

	return Vector2f(x_pos, y_pos);
}

void Enemy::update(RenderWindow& wn)
{
	this->move((Vector2i)(player.object.getPosition()), this->speed);
	wn.draw(this->object);
}

bool Enemy::is_dead()
{
	std::vector<Bullet> player_bullets = this->player.get_bullets();
	for (auto b = player_bullets.begin(); b !=player_bullets.end();)
	{
		if (this->collide(*b))
		{
			this->lifespan = seconds(0);
			break;
		}
	}

	return this->lifespan == seconds(0);
}