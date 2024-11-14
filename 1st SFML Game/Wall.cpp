#include "Wall.h"

void Wall::update(RenderWindow& wn)
{
	if (!this->is_dead()) { wn.draw(this->object); }
}
