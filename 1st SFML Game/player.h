#include "entity.h"
#include "bullet.h"
#include <vector>

const int PLAYER_SPEED = 5;
const int DASH_SPEED = 10;
const int DASH_DISTANCE = 50;
const Time SHOOT_CD = seconds(1);
const Time DASH_CD = seconds(3);

#pragma once
class Player :
    public Entity
{
private:
    Vector2i *target_pos = nullptr;
    int speed = PLAYER_SPEED;
    std::vector<Bullet> bullets; //Player bullets
    Time dash_timer = seconds(0);
    Time shoot_timer = seconds(0);
    bool dashing = 0;

public:
    /*
    *@brief Constructor create a Player Entity
    * @param spawn: the starting location of the player
    */
    Player(Vector2f spawn) : Entity(spawn, Vector2f(25, 25), Color::Green) {} //Constructor 

    /*
    * @brief update the player movement and their abilities (dash, shoot, wall)
    * @param wn: the window to draw the player on
    * @param game_timer: the time of the game
    */
    void update(RenderWindow& wn, Clock game_timer);//Update the player positon and draws them on screen

    /*
    * @brief Player's shoot ability
    * @param angle: the angle of the bullet in radians
    */
    void shoot(float angle); //Shoot
     
    /*
    * @brief check if the player's shoot ability is up
    * @param game_timer: time of the game
    * @return True if player shoot ability is up
    */
    bool can_shoot(Clock game_timer);

    /*
    * @brief check if the player's dash ability is up
    * @param game_timer: time of the game
    * @return True if player dash ability is up
    */
    bool can_dash(Clock game_timer);

    /*
    * @brief returns a reference to the player curremt bullet vector
    * @return a reference to player bullet vector
    */
    std::vector<Bullet>& get_bullets();

    //TODO: Player abilities - wall
};

