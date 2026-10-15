
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL)); //seeds random number generator with the current time
}

Game::~Game()
{
	delete [] animals;
	delete [] passports;
	delete character;
	delete passport;
}

// We call this once after the game class is instantiated
bool Game::init()
{
	animals[0].loadFromFile("../Data/Images/Critter Crossing/elephant.png");
	animals[1].loadFromFile("../Data/Images/Critter Crossing/moose.png");
	animals[2].loadFromFile("../Data/Images/Critter Crossing/penguin.png");
	passports[0].loadFromFile("../Data/Images/Critter Crossing/elephant passport.png");
	passports[1].loadFromFile("../Data/Images/Critter Crossing/moose passport.png");
	passports[2].loadFromFile("../Data/Images/Critter Crossing/penguin passport.png");
	
	character = new sf::Sprite(animals[0]);
	passport = new sf::Sprite(passports[0]);
	background_texture.loadFromFile("../Data/Images/WhackaMole Worksheet/background.png");
	background = sf::Sprite(background_texture);

	should_accept = false;
D:\critter - crossing\Data\Images\WhackaMole Worksheet\background.png


	newAnimal();

  return true;
}

// Update runs after event polling and before rendering
// use it for everything that needs to update between frames
void Game::update(float dt)
{
	
}

// Runs after update, use it to tell the window what to draw this frame
void Game::render()
{
	//window.draw(background);
	window.draw(*character);
	window.draw(*passport);
	
}

void Game::newAnimal() {
	int animal_index = rand() % 3;
	int passport_index = rand() % 3;

	if (animal_index == passport_index) {
		should_accept = true;
	}
	else {
		should_accept = false;
	}
	character->setTexture(animals[animal_index], true);
	character->setScale({ 1.8, 1.8 });
	//character->setPosition(sf::Vector2(window.getSize().x / 12, window.getSize().y / 12));
	character->setPosition(sf::Vector2f(window.getSize().x / 12, window.getSize().y / 12));

	passport->setTexture(passports[passport_index]);
	passport->setScale({ 0.6, 0.6 });
	//passport->setPosition(sf::Vector2(window.getSize().x / 2, window.getSize().y / 2));
	passport->setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
}

void Game::dragSprite(sf::Sprite* sprite) {
	if (sprite != nullptr) {
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		sf::Vector2f mouse_positionf = static_cast<sf::Vector2f>(mouse_position);
		sf::Vector2f drag_position = mouse_positionf - drag_offset;
		sprite->setPosition({ drag_posiion.x, drag_position.y });
	}
}

//Called by event polling when a MouseButtonPressed event is found
void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	// Event contains mouse position and which button was clicked

	// Don't need to extract position to a variable like this, this is just to show you it's a Vector2i
	sf::Vector2i position = event->position;

	// You can tell which button was pressed by comparing it to SFML's definitions of mouse buttons
	if (event->button == sf::Mouse::Button::Left)
	{
		//Left mouse button was pressed
	}
}

//Called by event polling when a MouseButtonReleased event is found
void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
	//Works the same as MouseButtonPressed
	if (event->button == sf::Mouse::Button::Left)
	{
		//Left mouse button was released
	}
}

// Called by event polling when a KeyPressed event is found
void Game::keyPressed(const sf::Event::KeyPressed* event)
{
	// You can tell which button was pressed by the scancode to SFML's definitions of keyboard keys
	if (event->scancode == sf::Keyboard::Scancode::W)
	{
		// W was pressed
	}

}

// Called by event polling when a KeyReleased event is found
void Game::keyReleased(const sf::Event::KeyReleased* event)
{
	// Works the same way as KeyPressed
	if (event->scancode == sf::Keyboard::Scancode::W)
	{
		// W was released
	}

}


