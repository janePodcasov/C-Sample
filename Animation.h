#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>

class Animation
{
private:
	sf::Vector2u imageCount;	//sprite count in sprite sheet in rows and columns;
	sf::Vector2u currentImage;	//currently displayed sprite;
	float totalTime;			//keeps track of how much time has passed;
	float switchTime;			//how long one sprite from the animation should be displayed;
public:
	sf::IntRect uvRect;			//UV Rectangle used to display the animation;
	//constructor && destructor;
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();
	//function for updating the animation;
	void Update(int row, float deltaTime, bool faceRight);
};

#endif