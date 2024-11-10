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
    int speed = ENEMY_SPEED;

public:
    Enemy(Vector2f spawn) : Entity(spawn, size, Color::Red) {}

    void update(RenderWindow& wn, Player player);

    bool is_dead(std::vector<Bullet> player_bullets);
};
