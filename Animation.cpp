#include "Animation.h"

//CONSTRUCTOR;
Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f; //animation duration time count should start with zero;
	currentImage.x = 0;	//animation should start with the first sprite in the spritesheet row;
	uvRect.width = texture->getSize().x / float(imageCount.x);	//calculate width of the sprite;
	uvRect.height = texture->getSize().y / float(imageCount.y);	//calculate height of the sprite;
}

//DESTRUCTOR;
Animation::~Animation() {

}

//FUNCTIONS;
void Animation::Update(int row, float deltaTime, bool faceRight) {
	currentImage.y = row;
	totalTime += deltaTime;
	//when its time to switch to the next sprite...
	if (totalTime >= switchTime) {
		//..reset time counter and switch to the next sprite in the spritesheet row;
		totalTime = 0.0f;
		currentImage.x++;
		//if the end of the spritesheet row is reached, switch back to the start of it;
		if (currentImage.x >= imageCount.x)
			currentImage.x = 0;
	}
	//figure out the direction of the animation, depending on whether the last button pressed was A(left) or D(right);
	uvRect.top = currentImage.y * uvRect.height;	//vertically, there is no sprite display switch;
	if (faceRight) {	//by default, the sprites are facing right; if player last pressed D, just display normal sprites;
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else {		//if player last pressed A, invert the sprite sheet images;
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}