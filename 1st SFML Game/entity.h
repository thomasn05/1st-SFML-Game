#include <SFML/Graphics.hpp>

using namespace sf;

#pragma once
class Entity
{
private: 
	RectangleShape object;
	int speed = 10;

public:
	Entity(Vector2f position, Vector2f size, Color color);
	void move(Vector2i pos);
	bool collide(Entity& other, int strictness = 0);
	RectangleShape getRect() const;
};

