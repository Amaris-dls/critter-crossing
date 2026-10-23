#include "Game.h"
#include <filesystem>
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL)); //seeds random number generator with the current time
}

Game::~Game()
{
	delete font;
	delete [] peoples;
	delete [] passports;
	delete character;
	delete passport;
	delete result_text;
	delete background_texture;
	delete accept_button_texture;
	delete reject_button_texture;
	delete accept;
	delete reject;
	delete accept_button;
	delete reject_button;
	delete table;
}

// We call this once after the game class is instantiated
bool Game::init()
{
	if (!font->openFromFile("Data/Fonts/open-sans/OpenSans-Regular.ttf"))
	{
		std::cerr << "Failed to load font" << std::endl;
		return false;
	}
	peoples[0].loadFromFile("Data/Images/TLOU/ellie-best.png");
	peoples[1].loadFromFile("Data/Images/TLOU/abby-best.png");
	peoples[2].loadFromFile("Data/Images/TLOU/joel-best.png");
	peoples[3].loadFromFile("Data/Images/TLOU/tommy-good.png");
	peoples[4].loadFromFile("Data/Images/TLOU/dina-good.png");
	peoples[5].loadFromFile("Data/Images/TLOU/ellie-bad.png");
	peoples[6].loadFromFile("Data/Images/TLOU/abby-worst.png");
	peoples[7].loadFromFile("Data/Images/TLOU/tommy-bad.png");
	passports[0].loadFromFile("Data/Images/TLOU/ellie-passport.png");
	passports[1].loadFromFile("Data/Images/TLOU/abby-passport.png");
	passports[2].loadFromFile("Data/Images/TLOU/joel-passport.png");
	passports[3].loadFromFile("Data/Images/TLOU/tommy-passport.png");
	passports[4].loadFromFile("Data/Images/TLOU/dina-passport.png");

	character = new sf::Sprite(peoples[0]);
	passport = new sf::Sprite(passports[0]);
	background_texture = new sf::Texture();
	background_texture->loadFromFile("Data/Images/WhackaMole Worksheet/background.png");
	background = new sf::Sprite(*background_texture);

	accept_button_texture = new sf::Texture();
	accept_button_texture->loadFromFile("Data/Images/TLOU/green-stamper.png");
	accept_button = new sf::Sprite(*accept_button_texture);
	accept_button->setScale(sf::Vector2f(0.3f, 0.3f));
	reject_button_texture = new sf::Texture();
	reject_button_texture->loadFromFile("Data/Images/TLOU/red-stamper.png");
	reject_button = new sf::Sprite(*reject_button_texture);
	reject_button->setScale(sf::Vector2f(0.3f, 0.3f));
	accept_button->setPosition(sf::Vector2f(window.getSize().x/2 +300, window.getSize().y - 200));
	reject_button->setPosition(sf::Vector2f(window.getSize().x/2 + 150, window.getSize().y - 200));
	context_show = false;
	dragged = nullptr;

	accept = new sf::Texture();
	accept->loadFromFile("Data/Images/Critter Crossing/accept.png");
	accept_sprite = new sf::Sprite(*accept);
	reject = new sf::Texture();
	reject->loadFromFile("Data/Images/Critter Crossing/reject.png");
	reject_sprite = new sf::Sprite(*reject);
	passport_accepted = false;
	passport_rejected = false;
	clicked_button = false;
	show_text = false;
	table_texture->loadFromFile("Data/Images/TLOU/table.png");
	table = new sf::Sprite(*table_texture);
	table->setPosition(sf::Vector2f(-50, window.getSize().y - 160));
	
	result_text = new sf::Text(*font, "You have guessed correctly!", 30);
	//result_text->setFont(*font);
	//result_text->setString("You have guessed correctly!");
	result_text->setPosition(sf::Vector2f(window.getSize().x / 2 - 100, window.getSize().y / 2 + 100));

	stamp_chosen = false;


	should_accept = false;
	newAnimal();

  return true;
}

// Update runs after event polling and before rendering
// use it for everything that needs to update between frames
void Game::update(float dt)
{
	dragSprite(dragged);
}

// Runs after update, use it to tell the window what to draw this frame
void Game::render()
{
	//window.draw(*background);
	window.draw(*character);
	window.draw(*passport);
	window.draw(*table);
	if(clicked_button == false){
		window.draw(*accept_button);
		window.draw(*reject_button);
	}
	if(passport_accepted == true){
		accept_sprite->setPosition(sf::Vector2f(passport->getPosition().x, passport->getPosition().y));
		window.draw(*accept_sprite);
	}
	if(passport_rejected == true){
		reject_sprite->setPosition(sf::Vector2f(passport->getPosition().x, passport->getPosition().y));
		window.draw(*reject_sprite);
	}
	if(show_text == true){
		window.draw(*result_text);
	}

}

void Game::newAnimal() {
	int animal_index = rand() % 8;
	int passport_index = rand() % 5;

	if (animal_index == passport_index) {
		should_accept = true;
	}
	else {
		should_accept = false;
	}
	character->setTexture(peoples[animal_index], true);
	character->setScale({ 0.9f, 0.9f });

	const sf::FloatRect bounds = character->getGlobalBounds();
	float characterHeight = bounds.size.y;
	character->setPosition(sf::Vector2f(
		window.getSize().x / 12.f - 50.f,
		window.getSize().y - characterHeight
	));

	passport->setTexture(passports[passport_index]);
	passport->setScale({ 0.6f, 0.6f });
	//passport->setPosition(sf::Vector2(window.getSize().x / 2, window.getSize().y / 2));
	passport->setPosition(sf::Vector2f(window.getSize().x / 2 , window.getSize().y / 2 -200));
}

void Game::dragSprite(sf::Sprite* sprite) {
	if (sprite != nullptr) {
		mouse_position = sf::Mouse::getPosition(window);
		mouse_positionf = static_cast<sf::Vector2f>(mouse_position);
		drag_position = mouse_positionf - drag_offset;
		sprite->setPosition({ drag_position.x, drag_position.y });
	}
}


//Called by event polling when a MouseButtonPressed event is found
void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	// Event contains mouse position and which button was clicked
	// Don't need to extract position to a variable like this, this is just to show you it's a Vector2i
	sf::Vector2i position = event->position;
	std::cout << "Mouse button pressed"<< std::endl;
	// You can tell which button was pressed by comparing it to SFML's definitions of mouse buttons
	if (event->button == sf::Mouse::Button::Left)
	{
		std::cout << "Left button pressed"<< std::endl;
		click = static_cast<sf::Vector2f>(position);
		//mouse_position = sf::Mouse::getPosition(window);
		click_reject = static_cast<sf::Vector2f>(position);
		click_accept = static_cast<sf::Vector2f>(position);
		mouse_position_control = sf::Mouse::getPosition(window);
		if(passport->getGlobalBounds().contains(click)){
			std::cout << "Passport clicked" << std::endl;
			dragged = passport;
			drag_offset = click - passport->getPosition();
		}
		 if(accept_button->getGlobalBounds().contains(click_accept)){
			dragged = accept_button;
			drag_offset = click_accept - accept_button->getPosition();
			//clicked_button = true;
			//passport_accepted = true;
		}
		 if(reject_button->getGlobalBounds().contains(click_reject)){
			dragged = reject_button;
			drag_offset = click_reject - reject_button->getPosition();
			//clicked_button = true;
			//passport_rejected = true;
		}
		
	}
	/*if (event->button == sf::Mouse::Button::Right){
		clickr = static_cast<sf::Vector2f>(position);
		context_show = true;
		if(clicked_button == false){
			accept_button->setPosition(sf::Vector2f(window.getSize().x/2 +300, window.getSize().y/2 - 300));
			reject_button->setPosition(sf::Vector2f(window.getSize().x/2 - 50, window.getSize().y/2 -300));
		}	
	}*/
}

//Called by event polling when a MouseButtonReleased event is found
void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
	sf::Vector2i position = event->position;
	//Works the same as MouseButtonPressed
	if (event->button == sf::Mouse::Button::Left)
	{
		if(dragged == passport && passport->getPosition().y < 100 && passport->getPosition().x < 100){
			if(passport_accepted == true || passport_rejected == true){
				if(should_accept){
					result_text->setString("You have guessed correctly!");
					show_text = true;
				}
				else{
					result_text->setString("You have guessed incorrectly!");
					show_text = true;
				}
				newAnimal();
				passport_accepted = false;
				passport_rejected = false;
				clicked_button = false;
			}
		}
		if(dragged == accept_button || dragged == reject_button){
			click = static_cast<sf::Vector2f>(position);
			if(passport->getGlobalBounds().contains(click)){
				if(dragged == accept_button){
					passport_accepted = true;
				}
				else{
					passport_rejected = true;
				}
			}
		}
		dragged = nullptr;
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




