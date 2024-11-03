#include "entity.h"

#pragma once
class Player :
    public Entity
{
    using Entity::Entity;//Using the Entity Constructor

private:
    bool should_move = 0;

public:
    void update(RenderWindow& wn);
};

