#pragma once
#include "entity.h"

const Vector2f bullet_size = Vector2f(5.f, 10.f);
const int max_distance = 100;

Vector2f bullet_spawn(Entity host, float angle);

class Bullet :
    public Entity
{
private:
    int speed = 10;
    Vector2f target_pos;

public:
    Bullet(Entity host, float angle) : Entity(bullet_spawn(host, angle), bullet_size, Color::Red) {}
    void update(RenderWindow& wn);
};