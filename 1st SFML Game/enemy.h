#pragma once
#include "entity.h"
#include "player.h"

const float SPAWN_DISTANCE = 200; // @brief how far the enemy will spawn from the player
const Vector2f ENEMY_SIZE = Vector2f(25, 25);
const int ENEMY_SPEED = 3;

/*
* @brief Randomizes a coordinate between a certain range at a certain distance away from coord
* @param coord: a coord that the new coord will generate away from
* @param range: the range of the new cord
* @return a new coord
*/
int coord(float coord, int range);

/*
* @brief Create a spawning vector around the player
* @param player: a Player object to generate a new position around
* @return a Vector position
*/
Vector2f spawn(Player player);

class Enemy :
    public Entity
{
private:
    int speed = ENEMY_SPEED;

public:
    /*
    *@brief Create an Enemy Entity at a given spawn
    * @param spawn: thhe spawning location of Enenmy
    */
    Enemy(Vector2f spawn) : Entity(spawn, ENEMY_SIZE, Color::Red) { this->lifespan = seconds(1); }

    /*
    * @brief update the Enemy object to move towards the player
    */
    void update(RenderWindow& wn, Player player);

    /*
    * @brief check if the Enemy object has collide with a player bullet. If it has collide it will delete the bullet from the vector and kill the Enemy.
    * @param player_bullets: a reference of the Player's bullet
    * @return True if the Enemy has collide with a bullet
    */
    bool is_dead(std::vector<Bullet>& player_bullets);
};
