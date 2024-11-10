#include "enemy.h"
#include <vector>

const Time spawn_time = seconds(3);

#pragma once
class EnemyManager
{
private:
	std::vector<Enemy> enemies;
	Player &player;
	const unsigned int max = 10;
	Time enemies_timer = seconds(0);

public:
	EnemyManager(Player &player) : player(player) {}

	void update(RenderWindow &wn, Time game_time);
};

