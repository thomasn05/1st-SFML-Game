#include <SFML/Graphics.hpp>

using namespace sf;

#pragma once
class Entity
{
private: 
	Vector2f position;
	Vector2f size;
	RectangleShape object;

public:
	Entity(Vector2f position, Vector2f size, Color color);
	void draw(RenderWindow &wn) const;
};

