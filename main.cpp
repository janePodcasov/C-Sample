#include <iostream>
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Crate.h"
#include "Tombstone.h"

//VARIABLES
static const float VIEW_WIDTH = 1200.0f;
static const float VIEW_HEIGHT = 800.0f;
//FUNCTIONS
void ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_WIDTH * aspectRatio, VIEW_HEIGHT);
}

int main() {
	//VARIABLES
	//a graphics window, with specified window size, title, and window style (here, enabled only close button, shown titlebar, and enabled resizing of the window);
	sf::RenderWindow window(sf::VideoMode(1200, 800), "C++ SFML Demo Project", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));	//set the camera view center;
	//background texture
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Background.png");	//load the texture from a file;
	sf::RectangleShape backgroundRect(sf::Vector2f(2000.0f, 1000.0f));	//create the rectangle with given size where the background texture will be displayed;
	backgroundRect.setTexture(&backgroundTexture);	//set the background texture to background rectangle;
	backgroundRect.setPosition(-400.0f, -100.0f);	//position it so that player spawns in the center of the whole background;
	//player texture;
	sf::Texture playerTexture;
	playerTexture.loadFromFile("CatSpriteSheet.png");	//load the texture from a file;
	//player;
	Player player(&playerTexture, sf::Vector2u(10, 2), 0.05f, 100.0f);
	//ingame object textures;
	sf::Texture crateTexture;
	crateTexture.loadFromFile("Crate.png");
	sf::Texture tombstoneTexture;
	tombstoneTexture.loadFromFile("TombStone.png");
	//create and initialize with values game objects;
	Crate crate1(&crateTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(800.0f, 600.0f));
	Crate crate2(&crateTexture, sf::Vector2f(100.0f, 100.0f), sf::Vector2f(300.0f, 200.0f));
	Tombstone tombstone1(&tombstoneTexture, sf::Vector2f(80.0f, 80.0f), sf::Vector2f( 900.0f, 300.0f));
	Tombstone tombstone2(&tombstoneTexture, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(200.0f, 700.0f));
	//ingame time;
	float deltaTime = 0.0f;
	sf::Clock clock;

	//FUNCTIONS


	//GAME LOOP
	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)	//cap the delta time to be the same regardless of how powerful the computer is, to prevent weird bugs;
			deltaTime = 1.0f / 20.0f;
		sf::Event evnt;
		//pollEvent allows the user to drag the window around the screen;
		while (window.pollEvent(evnt)) {
			//the program uses a switch statement to check for user input events;
			switch (evnt.type) {
				//check if the user has pressed close button and window needs to be closed;
				case sf::Event::Closed :
					window.close();
					break;
				//check if the user is trying to resize the window;
				case sf::Event::Resized :
					printf("New window size: %i x %i \n", evnt.size.width, evnt.size.height);	//print in console the new window size;
					ResizeView(window, view); //resize the camera view to fit the new screen size;
					break;
				//check if he user is pressing a keyboard button;
				case sf::Event::TextEntered :
					if (evnt.text.unicode < 128)			//make sure the character is not in the range of unreadable characters, like "ctrl" button;
						printf("%c \n", evnt.text.unicode);	//print in console the character;
					break;
			}
		}

		//update player animation; set animation row to 0 (first one), where the idle animation is;
		player.Update(deltaTime);
		//check player collision with game objects;
		crate1.GetCollision().CheckCollision(player.GetCollision(), 0.0f);
		crate2.GetCollision().CheckCollision(player.GetCollision(), 0.5f);
		tombstone1.GetCollision().CheckCollision(player.GetCollision(), 1.0f);
		tombstone2.GetCollision().CheckCollision(player.GetCollision(), 1.0f);
		//set view center to player;
		view.setCenter(player.GetPosition());

		//clear the window every frame before drawing a new frame;
		window.clear();
		//set view;
		window.setView(view);
		//draw the background;
		window.draw(backgroundRect);
		//draw the player;
		player.Draw(window);
		//draw game objects;
		crate1.Draw(window);
		crate2.Draw(window);
		tombstone1.Draw(window);
		tombstone2.Draw(window);
		//display the graphics;
		window.display();
	}

	return 0;
}