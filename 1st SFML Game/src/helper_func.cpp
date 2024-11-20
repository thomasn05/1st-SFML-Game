#include "helper_func.h"

float get_angle(Vector2f point1, Vector2i point2)
{
	float dx = point1.x - point2.x; //Get their difference in x and y
	float dy = point1.y - point2.y;

	float angle = atan2(dy, dx); //Find theta

	return angle;
}

bool point_collide(Vector2f p1, Vector2i p2)
{
	return (abs(p1.x - p2.x) < 3) && (abs(p1.y - p2.y) < 3);  //Check the player and the target pos (usually a mouse position) is within 3 pixel of each other
}

float radians_to_degree(float radians)
{
	return (radians * 180 / 3.14f) - 90;
}

float dot_product(const Vector2f& v1, const Vector2f& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

std::pair<float, float> project(const std::vector<Vector2f>& corners, const Vector2f& axis)
{
	float min = dot_product(corners[0], axis); //get the projection of the first corner onto the axis
	float max = min;
	std::pair<float, float> proj(min, max);

	for (auto& c : corners)
	{
		float projection = dot_product(c, axis); //Project each corner onto axis
		if (projection < proj.first) { proj.first = projection; } //find the min and max corners on the axis
		if (projection > proj.second) { proj.second = projection; }
	}

	return proj;
}

std::vector<Vector2f> get_edge(const std::vector<Vector2f>& corners)
{
	std::vector<Vector2f> edges;
	for (int i = 0; i < (int)corners.size(); i++)
	{
		Vector2f edge = corners[(i + 1) % corners.size()] - corners[i]; //find the edge vector (i+1)%corner.size() make sure it loops back to the first corner
		Vector2f edge_norm(-edge.y, edge.x); //find the perpendicular axis to the edge

		float magnitude = std::sqrt(edge_norm.x * edge_norm.x + edge_norm.y * edge_norm.y); //Normalize it by dividing the vector by its length: becomes a unit vector (vector with length of 1)
		Vector2f normalize_edge(edge_norm.x / magnitude, edge_norm.y / magnitude);

		edges.push_back(normalize_edge);
	}

	return edges;
}

bool SAT_Collision(const std::vector<Vector2f>& corners1, const std::vector<Vector2f>& corners2)
{
	std::vector<Vector2f> edges1 = get_edge(corners1); //Get the edge norm
	std::vector<Vector2f> edges2 = get_edge(corners2);

	edges1.insert(edges1.end(), edges2.begin(), edges2.end()); //Combine the two edge norm vector

	for (auto& e : edges1)
	{
		auto proj1 = project(corners1, e); //P{Project each corner onto edge norm
		auto proj2 = project(corners2, e);

		if (proj1.first > proj2.second || proj1.second < proj2.first) //Check for seperating axis, no collision
		{
			return 0;
		}
	}

	return 1; //All axis overlap, collision detected
}

