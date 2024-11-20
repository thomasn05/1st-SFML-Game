#include "player.h"
#include <iostream>

void Player::update(RenderWindow& wn, const Time& game_time)
{

	if (Mouse::isButtonPressed(Mouse::Right) && !this->dashing) //Move
	{
		this->target_pos = new Vector2i(Mouse::getPosition(wn)); //Allow a new Vector for the mouse position 
		this->speed = PLAYER_SPEED;
	}

	Vector2i mouse_pos = Mouse::getPosition(wn);//Get the current mouse position relative to game window
	if (Keyboard::isKeyPressed(Keyboard::E) && this->dash.is_up(game_time)) //Dash
	{
		this->e_ability(mouse_pos);
	}

	if (Keyboard::isKeyPressed(Keyboard::W) && this->wall.is_up(game_time)) //wall
	{
		this->w_ability(mouse_pos);
	}

	if (Keyboard::isKeyPressed(Keyboard::Q) && this->shoot.is_up(game_time)) //Shoot
	{
		this->q_ability(mouse_pos);
	}

	if (this->target_pos) //Check if player has reach target
	{
		float angle = get_angle(this->object.getPosition(), *this->target_pos);
		this->object.setRotation(radians_to_degree(angle));

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

	//if (game_time - this->wall.timer >= this->player_wall.lifespan) { this->player_wall.kill(); } //update the player's wall Entity
	this->player_wall.update(wn);

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

void Player::q_ability(const Vector2i& mouse_pos) //Create a new bullet and add it to player list
{
	float angle = get_angle(this->object.getPosition(), mouse_pos);
	Bullet bullet = Bullet(*this, angle);
	bullet.set_target();//Set the bullet target_destination

	this->bullets.push_back(bullet);
}

void Player::w_ability(const Vector2i& mouse_pos) //The wall ability
{
	this->player_wall.lifespan = WALL_LIFESPAN;

	float angle = get_angle(this->object.getPosition(), mouse_pos);
	Vector2f wall_spawn = bullet_spawn(*this, angle); //spawn the wall infront of the player 
	this->player_wall.object.setPosition(wall_spawn); //Set the position of the wall to be infron of the player
	this->player_wall.object.setRotation(radians_to_degree(angle)); //Rotate the wall to be horizontal

	Vector2f target = this->player_wall.get_component(mouse_pos, MAX_WALL_DISTANCE); //Target pos MAX_WALL_DISTANCE away from the player
	this->player_wall.set_target((Vector2i)target);
}

void Player::e_ability(const Vector2i& mouse_pos) //Dash ability
{
	this->dashing = 1;
	this->target_pos = new Vector2i(this->get_component(mouse_pos, DASH_DISTANCE)); //Allocate a new Vector2i pointer pointing to a mouse position
	this->speed = DASH_SPEED;
}

std::vector<Bullet>& Player::get_bullets() //Return a reference of the player's bullets
{
	return this->bullets;
}

bool Ability::is_up(const Time& game_time) // Check if an ability's cooldown is up
{
	if (game_time - this->timer >= this->CD)  //Check if enough time has passes
	{
		this->timer = game_time;
		return 1;
	}

	return 0;
}
