#include "wall.h"

Wall& Wall::operator=(const Wall& other)
{
	if (this != &other)
	{
		Entity::operator=(other);
		this->target_pos = other.target_pos;
	}

	return *this;
}

void Wall::set_target(const Vector2i& new_pos)
{
	this->target_pos = new_pos;
}

void Wall::update(RenderWindow& wn, Time time_elasped)
{
	if (time_elasped >= this->lifespan) { this->kill(); } //kill after a certain time has passed

	if (!this->is_dead()) 
	{
		if (!point_collide(this->object.getPosition(), this->target_pos)) //Keep moving it until it reaches the target
		{ 
			this->move(this->target_pos, this->speed); 
		}

		wn.draw(this->object);
	}
}
bool Wall::check_hit(Entity & other) const
{
	if (!this->is_dead())
	{
		return other.collided_with(*this);
	}
	
	else { return 0; }
}