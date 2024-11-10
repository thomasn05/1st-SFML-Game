#include "EnemyManager.h"
#include <iostream>

void EnemyManager::update(RenderWindow& wn, Time game_time)
{
	if ((game_time - this->enemies_timer) >= spawn_time && this->enemies.size() < this->max)
	{
		this->enemies_timer = game_time;
		Enemy enemy(spawn(this->player));
		this->enemies.push_back(enemy);
	}

	for (auto e = this->enemies.begin(); e != this->enemies.end();)
	{
		
		if (e->is_dead(this->player.get_bullets())) { e = this->enemies.erase(e); }
		else
		{
			e->update(wn, this->player);
			++e;
		}
	}
}
