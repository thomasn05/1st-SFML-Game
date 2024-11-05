#include "entity.h"

#pragma once
class Player :
    public Entity
{
    using Entity::Entity;//Using the Entity Constructor

private:
    Vector2i *target_pos = nullptr;
    int speed = 5;

public:
    void update(RenderWindow& wn);
    //TODO: Player abilities - shoot, dash, wall
};

