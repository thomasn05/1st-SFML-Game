#pragma once
#include "entity.h"

const Time WALL_LIFESPAN = seconds(4);
const int WALL_SPEED = 2;
const int MAX_WALL_DISTANCE = 50; //@brief how far the wall will spawn away from the player
const Vector2f WALL_SIZE = Vector2f(60, 10);

class Wall :
    public Entity
{
private:
    int speed = WALL_SPEED; //@brief wall speed
    Vector2i target_pos; //@brief where the wall will end u

public:
    /*
    * @brief Wall constructor: is initially dead
    * @param host: the Entity that created the wall
    */
    Wall(const Entity& host) : Entity(host.object.getPosition(), WALL_SIZE, Color::Blue) { this->kill(); }

    /*
    * @brief change the target_pos of the wall
    * @param new_pos: the position of the new target
    */
    void set_target(const Vector2i& new_pos);

    /*
    * @brief update the wall's movement and draw it to screen
    * @param the window to draw it to
    */
    void update(RenderWindow& wn, Time time_elasped);

    bool check_hit(Entity& other) const;
};

