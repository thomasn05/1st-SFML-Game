#include "bullet.h"
#include "wall.h"

#pragma once
const int PLAYER_SPEED = 5;
const int DASH_SPEED = 10;
const int DASH_DISTANCE = 70;
const Time SHOOT_CD = milliseconds(500);
const Time DASH_CD = seconds(3);
const Time WALL_CD = seconds(7);

/*
* @brief Represent the ability of the player
*/
struct Ability
{
    Time CD; // @brief the cooldown of the ability
    Time timer = seconds(0); // @brief the current ability 
    bool is_up = 1; //@brief state of ability 0 if on CD, 1 if UP

    /*
    * @brief Check if the ability is up (set the timer to game time if it is)
    * @param game_time: the curr time of the game
    * @return True if it is up
    */
    bool check_CD(const Time& game_time);
};

class Player :
    public Entity
{
private:
    Vector2i *target_pos = nullptr; // @brief points to the pos that the player is heading towards (null if not moving)
    int speed = PLAYER_SPEED; //@brief player speed
    bool dashing = 0; // @brief 1 is player is currently dashing 0 if notconst float angle

    std::vector<Bullet> bullets; //@brief Player bullets
    Wall player_wall = Wall(*this); //@brief player's wall

    Ability shoot = {SHOOT_CD }; // @brief represent player's shoot ability
    Ability dash = {DASH_CD }; // @brief represent player's dash ability
    Ability wall = {WALL_CD }; // @brief represent player's wall ability

public:
    /*
    *@brief Constructor create a Player Entity
    * @param spawn: the starting location of the player
    */
    Player(const Vector2f& spawn) : Entity(spawn, Vector2f(25, 25), Color::Green) {} //Constructor 

    /*
    * @brief update the player movement and their abilities (dash, shoot, wall)
    * @param wn: the window to draw the player on
    * @param game_timer: the time of the game
    */
    void update(RenderWindow& wn, const Time& game_time);//Update the player positon and draws them on screen

    /*
    * @brief Player's shoot ability
    * @param angle: the angle from the player to the mouse
    */
    void q_ability(const float angle); //Shoot

    /*
    * @brief Player's wall ability
    * @param angle: the angle from the player to the mouse
    */
    void w_ability(const float angle);

    /*
    * @brief Player's dash ability
    * @param angle: the angle from the player to the mouse
    */
    void e_ability(const float angle);
     
    /*
    * @brief return the reference to the player's bullets vector
    */
    std::vector<Bullet>& get_bullets();

    Wall get_wall() const;

    Ability get_abilities(const int id);
};

