#include "entity.h"
#include "bullet.h"
#include <vector>

const int MOVING_SPEED = 5;
const int DASH_SPEED = 10;
const int DASH_DISTANCE = 30;

#pragma once
class Player :
    public Entity
{
private:
    Vector2i *target_pos = nullptr;
    int speed = MOVING_SPEED;
    std::vector<Bullet> bullets; //Player bullets

public:
    Player(Vector2f spawn) : Entity(spawn, Vector2f(25, 25), Color::Green) {} //Constructor 

    void update(RenderWindow& wn);//Update the player positon and draws them on screen

    void shoot(float angle); //Shoot

    //TODO: Player abilities - wall, Player CD
};

