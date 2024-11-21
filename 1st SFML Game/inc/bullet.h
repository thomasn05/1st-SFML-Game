#pragma once
#include "entity.h"

const Vector2f BULLET_SIZE = Vector2f(5.f, 10.f);
const int MAX_BULLET_DISTANCE = 300; // @brief the maximum distance the bullet can travel
const int BULLET_SPEED = 10;

/*
* @breif Calculate the spawning of the bullet around its host Entity
* @param host: the Entity that shoot the Bullet
* @param angle: the angle of the Bullet
* @return a Vector2f represent the spawning location of the Bullet
*/
Vector2f bullet_spawn(const Entity& host, const float angle);

class Bullet :
    public Entity
{
private:
    int speed = BULLET_SPEED; //@brief bullet speed
    Vector2i target_pos; // @brief where the bullet is moving towards
    float angle; // @brief roation of the ullet

public:
    /*
    * @brief create a Bullet Entity
    * @param host: the Entity that fired the bullett (used to determine spawn)
    * @param angle: angle that the bullet will be facing
    */
    Bullet(const Entity& host, const float angle) : Entity(bullet_spawn(host, angle), BULLET_SIZE, Color::White, radians_to_degree(angle)), angle(angle) {} //Construtor
    
    /*
    *@brief update the Bullet state moving it if it is alive (become dead if it has reach it target)
    * @param wn: window to draw the Bullet on
    */
    void update(RenderWindow& wn); //Draw and check for when target is reach

    /*
    * @brief Calcualte the target position of the Bullet (done after Bullet is initialized)
    */
    void set_target();//Set target_pos
};