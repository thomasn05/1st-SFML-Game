#include "player.h"

void Player::update(RenderWindow& wn)
{
	this->should_move = Mouse::isButtonPressed(Mouse::Right);//Use to check when the Mouse button is held down

	if (this->should_move) //If the Mouse button is held down then move the player towards the mouse
	{
		this->move(Mouse::getPosition(wn));
	}

	wn.draw(this->getRect());
}