#ifndef COLLISION_H
#define COLLISION_H

#include <SFML\Graphics.hpp>

class Collision
{
private:
	sf::RectangleShape& body;
public:
	//constructor && destructor;
	Collision(sf::RectangleShape& body);
	~Collision();
	//functions;
	void Move(float dx, float dy) { body.move(dx, dy); }
	bool CheckCollision(Collision other, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
};

#endif