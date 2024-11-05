#include "entity.h"

const int MOVING_SPEED = 5;
const int DASH_SPEED = 10;
const int DASH_DISTANCE = 30;
const Color color = Color::Green;
const Vector2f size = Vector2f(25, 25);

#pragma once
class Player :
    public Entity
{
private:
    Vector2i *target_pos = nullptr;
    int speed = MOVING_SPEED;

public:
    Player(Vector2f spawn) : Entity(spawn, size, color) {}
    void update(RenderWindow& wn);
    //TODO: Player abilities - shoot, dash, wall
};

