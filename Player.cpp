#include "Player.h"

//CONSTRUCTOR;
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) : animation(texture, imageCount, switchTime) {
	//initialize player with default values;
	this->speed = speed;	//movement speed;
	row = 0;				//idle animation on first row;
	faceRight = true;		//facing right;
	body.setSize(sf::Vector2f(70.0f, 100.0f));	//player size;
	body.setPosition(600.0f, 400.0f);			//player spawn;
	body.setTexture(texture);			//player texture(spritesheet);
	body.setOrigin(body.getSize() / 2.0f);	//get player center(origin);
}

//DESTRUCTOR;
Player::~Player() {

}

//FUNCTIONS;
void Player::Update(float deltaTime) {
	//initialize player movement as zero value (the player isn't moving);
	sf::Vector2f movement(0.0f, 0.0f);
	//check for user input for movement;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= speed * deltaTime;	//move up;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;	//move left;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed * deltaTime;	//move down;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;	//move right;
	//if there is no movement, the animation should be idle, on first spritesheet row;
	if (movement.x == 0.0f && movement.y == 0.0f) {
		row = 0;
	}
	//otherwise, set spritesheet to second row, where the running animation is;
	else {
		row = 1;
		//set which way the sprite is facing;
		if (movement.x < 0.0f)
			faceRight = false;
		if(movement.x > 0.0f)
			faceRight = true;
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}
void Player::Draw(sf::RenderWindow& window) {
	window.draw(body);
}