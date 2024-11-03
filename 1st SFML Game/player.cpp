#include "player.h"

void Player::update(RenderWindow& wn)
{
	this->should_move = Mouse::isButtonPressed(Mouse::Right);

	if (this->should_move)
	{
		this->move(Mouse::getPosition(wn));
	}

	wn.draw(this->getRect());
}