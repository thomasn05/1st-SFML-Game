#include "enemy.h"
#include <random>
#include <iostream>

int coord(float coord, int range) //Generate a pos in range away from coord
{
	int pos;

	while (true) //Keep generating a new pos if it has within spawn_dist of coord
	{
		std::random_device rd; //Random generator
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(25, range - 25);

		pos = distrib(gen);

		if (abs(pos - coord) >= spawn_dist) { break; }
	}

	return pos;
}

Vector2f spawn(Player player) //Create a position Vector around the player
{
	float x_pos = (float)coord(player.object.getPosition().x, 1400); //Create x and y coord
	float y_pos = (float)coord(player.object.getPosition().y, 1000);

	return Vector2f(x_pos, y_pos);
}

void Enemy::update(RenderWindow& wn, Player player) //Move enemy towards player
{
	this->move((Vector2i)player.object.getPosition(), this->speed);
	wn.draw(this->object);
}

bool Enemy::is_dead(std::vector<Bullet>& player_bullets) //Check if enemy has collide with player's bullets
{
	for (auto b = player_bullets.begin(); b !=player_bullets.end();)
	{
		if (this->collide(*b)) //If collide remove the bullet from player's bullets and kill this enemy
		{
			player_bullets.erase(b);
			this->lifespan = seconds(0);
			break;
		}

		++b;
	}

	return this->lifespan == seconds(0);
}
