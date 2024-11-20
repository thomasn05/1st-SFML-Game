#include "wall.h"

void Wall::set_target(const Vector2i& new_pos)
{
	this->target_pos = new_pos;
}

void Wall::update(RenderWindow& wn)
{
	if (!this->is_dead()) 
	{
		if (!point_collide(this->object.getPosition(), this->target_pos)) //Keep moving it until it reaches the target
		{ 
			this->move(this->target_pos, this->speed); 
		}

		wn.draw(this->object);
	}
}
