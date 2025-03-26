#include "EnemyManager.h"

EnemyManager& EnemyManager::operator=(const EnemyManager& other)
{
	if (this != &other) {
		this->enemies = other.enemies;
		this->enemy_spawn = other.enemy_spawn;
		this->enemies_killed = other.enemies_killed;
	}
	
	return *this;
}

void EnemyManager::update(RenderWindow& wn, const Time& game_time, Player& player)
{
	if (this->enemy_spawn.check_CD(game_time) && this->enemies.size() < this->max) //Create an Enemy is store it in its vector after a certain time (capped at max)
	{
		Enemy enemy(spawn(player));
		this->enemies.push_back(enemy);

		this->enemy_spawn.is_up = 0;
	}

	for (auto e = this->enemies.begin(); e != this->enemies.end();) //Chec for player collision and bullet collsion for each enemy on screen
	{
		if (e->collided_with(player)) { player.kill(); return; } //Kill player if enemy collide with it and end update since player is already 
		player.get_wall().check_hit(*e);
		

		auto& player_bullets = player.get_bullets();
		if (e->is_dead(player_bullets)) //Kill enenemy and remove bullet if they collide
		{ 
			e = this->enemies.erase(e); 
			this->enemies_killed++;	
		} 
		else
		{
			e->update(wn, player);
			++e;
		}
	}
}

int EnemyManager::get_enemies_killed() const
{
	return this->enemies_killed;
}
