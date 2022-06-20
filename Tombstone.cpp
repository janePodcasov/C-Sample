#include "Tombstone.h"

//CONSTRUCTOR
Tombstone::Tombstone(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position) {
	//initialize the platform with passed in values from parameters;
	body.setTexture(texture);
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
}

//DESTRUCTOR
Tombstone::~Tombstone() {

}

//FUNCTIONS
void Tombstone::Draw(sf::RenderWindow& window) {
	window.draw(body);
}