#include "entity.h"

Entity::Entity(const Vector2f& position, const Vector2f& size, const Color color, const float angle) //Constructor
{
	//Setup the RectangleShape
	this->object.setSize(size);
	this->object.setFillColor(color);
	this->object.setOrigin(size.x / 2, size.y / 2); //Set the origin to the middle of the Rectangle
	this->object.setPosition(position);
	this->object.setRotation(angle);
}

void Entity::move(const Vector2i& target, const int speed)
{
	Vector2f new_pos = this->get_component(target, speed);

	this->object.setPosition(new_pos);
}

bool Entity::collided_with(const Entity& other) const
{
	std::vector<Vector2f> this_corners = this->get_corners();
	std::vector<Vector2f> other_corners = other.get_corners();

	std::vector<Vector2f> edges1 = get_edge(this_corners); //Get the edge norm
	std::vector<Vector2f> edges2 = get_edge(other_corners);

	edges1.insert(edges1.end(), edges2.begin(), edges2.end()); //Combine the two edge norm vector

	for (auto& e : edges1)
	{
		auto proj1 = project(this_corners, e); //P{Project each corner onto edge norm
		auto proj2 = project(other_corners, e);

		float overlap = std::min(proj1.second, proj2.second) - std::max(proj1.first, proj2.first);
		if (overlap < 0) //Check for seperating axis, no collision
		{
			return 0;
		}
	}

	return 1; //All axis overlap, collision detected
}

//Vector2f Entity::collision_pos(Entity other)
//{
//	/*FloatRect intersection;
//	this->object.getGlobalBounds().intersects(other.object.getGlobalBounds(), intersection);
//	return Vector2f(intersection.left, intersection.top);*/
//
//
//}

Vector2f Entity::get_component(Vector2i target, int distance) const 
{
	Vector2f curr_pos = this->object.getPosition();
	
	float angle = get_angle(curr_pos, target);

	float new_x = curr_pos.x - distance * cos(angle); //Use trig to find how much to move in the x and y
	float new_y = curr_pos.y - distance * sin(angle);

	return Vector2f(new_x, new_y);
}

bool Entity::is_dead() const
{
	return this->lifespan == seconds(0);
}

void Entity::kill()
{
	this->lifespan = seconds(0);
}

std::vector<Vector2f> Entity::get_corners() const
{
	std::vector<Vector2f> corners;
	Transform transform = this->object.getTransform();
	Vector2f size = this->object.getSize();

	corners.push_back(transform.transformPoint(Vector2f(0, 0)));
	corners.push_back(transform.transformPoint(Vector2f(size.x, 0)));
	corners.push_back(transform.transformPoint(Vector2f(size.x, size.y)));
	corners.push_back(transform.transformPoint(Vector2f(0, size.y)));

	return corners;
}