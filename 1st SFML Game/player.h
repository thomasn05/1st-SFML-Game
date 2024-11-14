#include "bullet.h"
#include "wall.h"
#include <vector>

#pragma once
const int PLAYER_SPEED = 5;
const int DASH_SPEED = 10;
const int DASH_DISTANCE = 50;
const Time SHOOT_CD = seconds(1);
const Time DASH_CD = seconds(3);
const Time WALL_CD = seconds(8);

/*
* @brief Represent the ability of the player
*/
struct Ability
{
    Time timer; // @brief the current ability 
    Time CD; // @brief the cooldown of the ability

    /*
    * @brief Check if the ability is up (set the timer to game time if it is)
    * @param game_time: the curr time of the game
    * @return True if it is up
    */
    bool is_up(Time game_time);
};

class Player :
    public Entity
{
private:
    Vector2i *target_pos = nullptr; // @brief points to the pos that the player is heading towards (null if not moving)
    int speed = PLAYER_SPEED;\
    bool dashing = 0; // @brief 1 is player is currently dashing 0 if not

    std::vector<Bullet> bullets; //@brief Player bullets
    Wall player_wall = Wall(*this);

    Ability shoot = { seconds(0), SHOOT_CD }; // @brief represent player's shoot ability
    Ability dash = { seconds(0), DASH_CD }; // @brief represent player's dash ability
    Ability wall = { seconds(0), WALL_CD }; // @brief represent player's wall ability

public:
    /*
    *@brief Constructor create a Player Entity
    * @param spawn: the starting location of the player
    */
    Player(Vector2f spawn) : Entity(spawn, Vector2f(25, 25), Color::Green) {} //Constructor 

    /*
    * @brief update the player movement and their abilities (dash, shoot, wall)
    * @param wn: the window to draw the player on
    * @param game_timer: the time of the game
    */
    void update(RenderWindow& wn, Time game_time);//Update the player positon and draws them on screen
        
    /*
    * @brief Player's shoot ability
    * @param mouse_pos: the mouse position relative to game window
    */
    void q_ability(Vector2i mouse_pos); //Shoot\

    void w_ability(Vector2i mous_pos);

    /*
    * @brief Player's dash ability
    * @param mouse_pos: the mouse position relative to game window
    */
    void e_ability(Vector2i mouse_pos);
     
    /*
    * @brief return the reference to the player's bullets vector
    */
    std::vector<Bullet>& get_bullets();

    //TODO: Player abilities - wall
};

