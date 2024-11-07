#include "player.h"
#include <iostream>

void Player::update(RenderWindow& wn)
{
	if (Mouse::isButtonPressed(Mouse::Right))
	{
		this->target_pos = new Vector2i(Mouse::getPosition(wn)); //Allocate a new Vector2i pointer pointing to a mouse position
		this->speed = MOVING_SPEED;
	}

	if (Keyboard::isKeyPressed(Keyboard::E))
	{
		this->target_pos = new Vector2i(this->get_component(Mouse::getPosition(wn), DASH_DISTANCE)); //Allocate a new Vector2i pointer pointing to a mouse position
		this->speed = DASH_SPEED;
	}

	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		float angle = get_angle(this->getRect().getPosition(), Mouse::getPosition(wn));
		this->shoot(angle);
	}

	if (this->target_pos)
	{
		Vector2f curr = this->getRect().getPosition(); //The curr player postion
		bool reach_dest = point_collide(curr, Vector2f(this->target_pos->x, this->target_pos->y));

		if (!reach_dest) //Keep moving if it hasn't reach its destination
		{
			this->move(*(this->target_pos), this->speed);
		}

		else //if it has set it to a nullptr so that it doesn't try to keep moving
		{
			this->target_pos = nullptr;
			this->speed = MOVING_SPEED;
		}
	}
	wn.draw(this->getRect());
	for (Bullet& bullet : this->bullets)
	{
		bullet.update(wn);
	}
}

void Player::shoot(float angle)
{
	Bullet bullet = Bullet(*this, angle);
	bullet.set_target();

	this->bullets.push_back(bullet);
}