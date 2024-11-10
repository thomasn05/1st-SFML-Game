#include "entity.h"
#include "bullet.h"
#include <vector>

const int MOVING_SPEED = 5;
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
    int speed = MOVING_SPEED;
    std::vector<Bullet> bullets; //Player bullets
    Time dash_timer = seconds(0);
    Time shoot_timer = seconds(0);
    bool dashing = 0;

public:
    Player(Vector2f spawn) : Entity(spawn, Vector2f(25, 25), Color::Green) {} //Constructor 

    void update(RenderWindow& wn, Clock game_timer);//Update the player positon and draws them on screen

    void shoot(float angle); //Shoot

    bool can_shoot(Clock game_timer);

    bool can_dash(Clock game_timer);

    //TODO: Player abilities - wall, Player CD
};

