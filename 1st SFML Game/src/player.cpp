#include "player.h"

void Player::update(RenderWindow& wn, const Time& game_time)
{

	if (Mouse::isButtonPressed(Mouse::Right) && !this->dashing) //Move
	{
		this->target_pos = new Vector2i(Mouse::getPosition(wn)); //Allow a new Vector for the mouse position 
		this->speed = PLAYER_SPEED;
	}

	Vector2i mouse_pos = Mouse::getPosition(wn);//Get the current mouse position relative to game window
	float angle = get_angle(this->object.getPosition(), mouse_pos);
	if (Keyboard::isKeyPressed(Keyboard::E) && this->dash.check_CD(game_time)) //Dash
	{
		this->e_ability(angle);
	}

	if (Keyboard::isKeyPressed(Keyboard::W) && this->wall.check_CD(game_time)) //wall
	{
		this->w_ability(angle);
	}

	if (Keyboard::isKeyPressed(Keyboard::Q) && this->shoot.check_CD(game_time)) //Shoot
	{
		this->q_ability(angle);
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

	this->player_wall.update(wn, game_time - this->wall.timer);
	this->player_wall.check_hit(*this);

	//Update player bullets
	for (auto b = this->bullets.begin(); b != this->bullets.end();)
	{
		if (b->is_dead() || this->player_wall.check_hit(*b)) { b = this->bullets.erase(b); } //Remove if bullet is not alive if it either reach its dest of hit a wall
		else 
		{ 
			b->update(wn);
			++b; 
		}
	}
}

void Player::q_ability(const float angle) //Create a new bullet and add it to player list
{
	Bullet bullet = Bullet(*this, angle);
	bullet.set_target();//Set the bullet target_destination

	this->bullets.push_back(bullet);

	this->shoot.is_up = 0; //Put Ability on CD
}

void Player::w_ability(const float angle) //The wall ability
{
	this->player_wall.lifespan = WALL_LIFESPAN;

	Vector2f wall_spawn = bullet_spawn(*this, angle); //spawn the wall infront of the player 
	this->player_wall.object.setPosition(wall_spawn); //Set the position of the wall to be infron of the player
	this->player_wall.object.setRotation(radians_to_degree(angle)); //Rotate the wall to be horizontal

	Vector2f target_dist = dist_component(angle, MAX_WALL_DISTANCE); //Target pos MAX_WALL_DISTANCE away from the player
	Vector2f target = this->object.getPosition() + target_dist;
	this->player_wall.set_target((Vector2i)target);

	this->wall.is_up = 0; //Put Ability on CD
}

void Player::e_ability(const float angle) //Dash ability
{
	this->dashing = 1;
	Vector2f target_dist = dist_component(angle, DASH_DISTANCE);
	this->target_pos = new Vector2i(this->object.getPosition() + target_dist); //Allocate a new Vector2i pointer pointing to a mouse position
	this->speed = DASH_SPEED;

	this->dash.is_up = 0; //Put Ability on CD
}

std::vector<Bullet>& Player::get_bullets() //Return a reference of the player's bullets
{
	return this->bullets;
}

Wall Player::get_wall() const
{
	return this->player_wall;
}

Ability Player::get_abilities(const int id)
{
	switch (id)
	{
	case 0:
		return this->shoot;
	case 1:
		return this->wall;
	case 2:
		return this->dash;
	}
}

bool Ability::check_CD(const Time& game_time) // Check if an ability's cooldown is up
{
	if (game_time - this->timer >= this->CD)  //Check if enough time has passes
	{
		this->timer = game_time;
		this->is_up = 1;
	}

	return this->is_up;
}
