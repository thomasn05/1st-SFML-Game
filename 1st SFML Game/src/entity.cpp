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
	Vector2f curr_pos = this->object.getPosition();
	float angle = get_angle(curr_pos, target);

	Vector2f new_pos = dist_component(angle, speed);

	this->object.move(new_pos);
}

bool Entity::collided_with(const Entity& other)
{
	std::vector<Vector2f> this_corners = this->get_corners();
	std::vector<Vector2f> other_corners = other.get_corners();

	std::vector<Vector2f> edges1 = get_edge(this_corners); //Get the edge norm
	std::vector<Vector2f> edges2 = get_edge(other_corners);

	edges1.insert(edges1.end(), edges2.begin(), edges2.end()); //Combine the two edge norm vector

	Vector2f smallest_edge;
	float min_overlap = FLT_MAX;
	for (auto& e : edges1)
	{
		auto proj1 = project(this_corners, e); //Project each corner onto edge norm
		auto proj2 = project(other_corners, e);

		float overlap = std::min(proj1.second, proj2.second) - std::max(proj1.first, proj2.first); //Overlapping of two vectors negative is they dont cross, positive if they do
		if (overlap < 0) //Check for seperating axis, no collision
		{
			return 0;
		}

		if (overlap < min_overlap)
		{
			min_overlap = overlap;
			smallest_edge = e;
		}
	}

	Vector2f mtv = min_overlap * smallest_edge;
	Vector2f center_dist = this->object.getPosition() - other.object.getPosition();

	if (dot_product(mtv, center_dist) < 0) { mtv = -mtv; }

	this->object.move(mtv);

	return 1; //All axis overlap, collision detected
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