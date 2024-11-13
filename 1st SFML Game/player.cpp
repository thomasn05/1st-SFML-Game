#include "player.h"

void Player::update(RenderWindow& wn, Time game_time)
{
	if (Mouse::isButtonPressed(Mouse::Right) && !this->dashing) //Move
	{
		this->target_pos = new Vector2i(Mouse::getPosition(wn)); //Allocate a new Vector2i pointer pointing to a mouse position
		this->speed = PLAYER_SPEED;
	}

	if (Keyboard::isKeyPressed(Keyboard::E) && this->dash.is_up(game_time)) //Dash
	{
		this->dashing = 1;
		this->dash.timer = game_time;
		this->target_pos = new Vector2i(this->get_component(Mouse::getPosition(wn), DASH_DISTANCE)); //Allocate a new Vector2i pointer pointing to a mouse position
		this->speed = DASH_SPEED;
	}

	if (Keyboard::isKeyPressed(Keyboard::Q) && this->shoot.is_up(game_time)) //Shoot
	{
		this->shoot.timer = game_time;
		float angle = get_angle(this->object.getPosition(), Mouse::getPosition(wn));
		this->fire(angle);
	}

	if (this->target_pos) //Check if player has reach target
	{
		Vector2f curr = this->object.getPosition(); //The curr player postion
		bool reach_dest = point_collide(curr, *(this->target_pos));

		if (!reach_dest) //Keep moving if it hasn't reach its destination
		{
			this->move(*(this->target_pos), this->speed);
		}

		else //if it has set it to a nullptr so that it doesn't try to keep moving
		{
			this->target_pos = nullptr;
			this->speed = PLAYER_SPEED;
			this->dashing = 0;
		}
	}

	wn.draw(this->object);

	//Update player bullets
	for (auto b = this->bullets.begin(); b != this->bullets.end();)
	{
		if (b->is_dead()) { b = this->bullets.erase(b); } //Remove if bullet is not alive
		else 
		{ 
			b->update(wn);
			++b; 
		}
	}
}

void Player::fire(float angle) //Create a new bullet and add it to player list
{
	Bullet bullet = Bullet(*this, angle);
	bullet.set_target();//Set the bullet target_destination

	this->bullets.push_back(bullet);
}

std::vector<Bullet>& Player::get_bullets() //Return a reference of the player's bullets
{
	return this->bullets;
}

bool Ability::is_up(Time game_time)
{
	return game_time - this->timer >= this->CD;
}
