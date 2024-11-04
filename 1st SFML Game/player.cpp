#include "player.h"
#include <iostream>

void Player::update(RenderWindow& wn)
{
	if (Mouse::isButtonPressed(Mouse::Right))
	{
		this->target_pos = new Vector2i(Mouse::getPosition(wn));
	}

	if (this->target_pos)
	{
		Vector2f curr = this->getRect().getPosition();
		bool reach_dest = (curr.x - this->target_pos->x < 1) && (curr.y - this->target_pos->y < 1);

		if (!reach_dest)
		{
		this->move(*(this->target_pos));
		}

		else
		{
			this->target_pos = nullptr;
		}
	}

	wn.draw(this->getRect());
}