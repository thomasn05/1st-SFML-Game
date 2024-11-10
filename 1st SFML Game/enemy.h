#pragma once
#include "entity.h"
#include "player.h"

const float spawn_dist = 200;
const Vector2f size = Vector2f(25, 25);
const int ENEMY_SPEED = 4;

int coord(float coord, int range);

Vector2f spawn(Player player);

class Enemy :
    public Entity
{
private:
    Player& player;
    int speed = ENEMY_SPEED;

public:
    Enemy(Player& player) : Entity(spawn(player), size, Color::Red), player(player) {}

    void update(RenderWindow& wn);

    bool is_dead();
};
