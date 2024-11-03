#include <SFML/Graphics.hpp>

using namespace sf;

#pragma once
class Entity
{
private: 
	RectangleShape object;
	int speed = 10;

public:
	Entity(Vector2f position, Vector2f size, Color color); //Constructor
	void move(Vector2i pos); //Moving Entity
	bool collide(Entity& other); //Collision Detection
	RectangleShape getRect() const; //Get the RectangeShape
};

