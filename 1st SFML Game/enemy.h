#pragma once
#include "entity.h"

const float spawn_dist = 200;
const Vector2f size = Vector2f(25, 25);

float coord(float coord, int range);

Vector2f spawn(Entity player);

class Enemy :
    public Entity
{
private:
    Entity player;

public:
    Enemy(Entity player) : Entity(spawn(player), size, Color::Red), player(player) {}

    void update(RenderWindow& wn);
};

