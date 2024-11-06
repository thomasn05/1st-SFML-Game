#pragma once
#include "entity.h"


class Bullet :
    public Entity
{
private:
    int speed = 10;
    const Vector2f size = Vector2f(5.f, 10.f);
    const int max_distance = 100;
    Vector2f target_pos;

public:
    Bullet(Entity host, float angle);
    void update(RenderWindow& wn);
};

