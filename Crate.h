#ifndef CRATE_H
#define CRATE_H

#include <SFML\Graphics.hpp>
#include "Collision.h"

class Crate
{
private:
	sf::RectangleShape body;
public:
	//constructor && destructor;
	Crate(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Crate();
	//functions;
	void Draw(sf::RenderWindow& window);
	Collision GetCollision() { return Collision(body); }
};

#endif