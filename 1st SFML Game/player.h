#include "entity.h"
#include "bullet.h"
#include <vector>

#pragma once
const int PLAYER_SPEED = 5;
const int DASH_SPEED = 10;
const int DASH_DISTANCE = 50;
const Time SHOOT_CD = seconds(1);
const Time DASH_CD = seconds(3);
const Time WALL_CD = seconds(5);

struct Ability
{
    Time timer;
    Time CD;
    bool is_up(Time game_time);
};

class Player :
    public Entity
{
private:
    Vector2i *target_pos = nullptr;
    int speed = PLAYER_SPEED;
    std::vector<Bullet> bullets; //Player bullets
    Ability shoot = { seconds(0), SHOOT_CD };
    Ability dash = { seconds(0), DASH_CD };
    Ability wall = { seconds(0), WALL_CD };
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
    void update(RenderWindow& wn, Time game_time);//Update the player positon and draws them on screen

    /*
    * @brief Player's shoot ability
    * @param angle: the angle of the bullet in radians
    */
    void fire(float angle); //Shoot
     
    std::vector<Bullet>& get_bullets();

    //TODO: Player abilities - wall
};

