#ifndef TOMBSTONE_H
#define TOMBSTONE_H

#include <SFML\Graphics.hpp>
#include "Collision.h"

class Tombstone
{
private:
	sf::RectangleShape body;
public:
	//constructor && destructor;
	Tombstone(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Tombstone();
	//functions;
	void Draw(sf::RenderWindow& window);
	Collision GetCollision() { return Collision(body); }
};

#endif