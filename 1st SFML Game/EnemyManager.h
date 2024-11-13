#include "enemy.h"
#include <vector>

const Time spawn_time = milliseconds(500);

#pragma once
class EnemyManager
{
private:
	std::vector<Enemy> enemies;
	Player &player;
	const unsigned int max = 10; // @brief the maximum number of enemy that can appear on screen
	Ability enemy_spawn = { seconds(0), spawn_time };

public:
	/*
	* @brief Create a manager to manage all enemies on screen 
	* @param player: The player object is used to get its position and bullets
	*/
	EnemyManager(Player &player) : player(player) {}

	/*
	* @brief Create new enemy on the screen at set interval and check for their collision with the player and its bullets
	* @param wn: the game window to draw the bullet on
	* @param game_time: the curr time of the game (used for spawning)
	*/
	void update(RenderWindow &wn, Time game_time);
};

