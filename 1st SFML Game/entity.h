#include <SFML/Graphics.hpp>

using namespace sf;

#pragma once
class Entity
{
private: 
	RectangleShape object;
public:
	Entity(Vector2f position, Vector2f size, Color color); //Constructor
	void move(Vector2i target, int speed); //Moving Entity
	bool collide(Entity& other) const; //Collision Detection
	RectangleShape getRect() const; //Get the RectangeShape
	Vector2f get_component(Vector2i target, int distance) const;
};