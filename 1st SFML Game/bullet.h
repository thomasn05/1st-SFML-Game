#pragma once
#include "entity.h"

const Vector2f bullet_size = Vector2f(5.f, 10.f);
const int max_distance = 200;

/*
* @breif Calculate the spawning of the bullet around its host Entity
* @param host: the Entity that shoot the Bullet
* @param angle: the angle of the Bullet
* @return a Vector2f represent the spawning location of the Bullet
*/
Vector2f bullet_spawn(Entity host, float angle);

class Bullet :
    public Entity
{
private:
    int speed = 10;
    Vector2i target_pos;
    float angle;

public:
    /*
    * @brief create a Bullet Entity
    * @param host: the Entity that fired the bullett (used to determine spawn)
    * @param angle: angle that the bullet will be facing
    */
    Bullet(Entity host, float angle) : Entity(bullet_spawn(host, angle), bullet_size, Color::White, (angle * 180 / 3.14f) - 90), angle(angle) { this->lifespan = seconds(1); } //Construtor
    
    /*
    *@brief update the Bullet state moving it if it is alive (become dead if it has reach it target)
    * @param wn: window to draw the Bullet on
    */
    void update(RenderWindow& wn); //Draw and check for when target is reach

    /*
    * @brief Calcualte the target position of the Bullet (done after Bullet is initialized)
    */
    void set_target();//Set target_pos

    /*
    * @brief get the Bullet alive state (0s = dead, 1+ seconds = alive)
    */
    bool is_dead(); //Get alive 
};