#include "Collision.h"

//CONSTRUCTOR
Collision::Collision(sf::RectangleShape& body) : body(body) {

}

//DESTRUCTOR
Collision::~Collision() {

}

//FUNCTIONS
bool Collision::CheckCollision(Collision other, float push) {
	sf::Vector2f otherPosition = other.GetPosition();	//get the position of the object that this object is colliding with;
	sf::Vector2f otherHalfSize = other.GetHalfSize();	//and its center;
	sf::Vector2f thisPosition = GetPosition();	//get the position of this object that is colliding with something; 
	sf::Vector2f thisHalfSize = GetHalfSize();	//and the center;
	//calculate the delta vector coordinates between these two colliding objects;
	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	//get how much both objects are intersecting each other on both axis;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//handle the collision;
	if (intersectX < 0.0f && intersectY < 0.0f) {
		//"push" will decide how much the colliding object wil have to move out;
		//0 = it can not move at all, e.g. when player is colliding with a wall;
		//0.1 to 1.0 = the objects can be pushed, e.g. the player can push a barrel;
		//the higher the number, the more the objects pushes back, e.g. simulating the object being heavier;
		push = std::min(std::max(push, 0.0f), 1.0f);
		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
			}
			else {
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
			}
			else {
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
			}
		}
		return true;	//keep handling the collision;
	}
	return false;	//only returns false when collision is fully handled and none is present anymore;
}