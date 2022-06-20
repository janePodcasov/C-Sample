#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collision.h"

class Player
{
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
public:
	//constructor && destructor;
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();
	//functions;
	sf::Vector2f GetPosition() { return body.getPosition(); }	//returns player position;
	Collision GetCollision() { return Collision(body); }
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

#endif