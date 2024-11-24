#include "enemy.h"

const Time SPAWN_INTERVAL = milliseconds(500);

#pragma once
class EnemyManager
{
private:
	std::vector<Enemy> enemies; //@brief a vector of enemies on screen
	Player &player; //@brief reference to player
	const unsigned int max = 20; // @brief the maximum number of enemy that can appear on screen
	Ability enemy_spawn = {SPAWN_INTERVAL }; //@brief spawn_timer
	int enemies_killed = 0;

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
	void update(RenderWindow& wn, const Time& game_time);

	int get_enemies_killed() const;
};

