
#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseButtonPressed(const sf::Event::MouseButtonPressed* event);
  void mouseButtonReleased(const sf::Event::MouseButtonReleased* event);
  void keyPressed(const sf::Event::KeyPressed* event);
  void keyReleased(const sf::Event::KeyReleased* event);
  void newAnimal();
  void dragSprite(sf::Sprite* sprite);

 private:
  sf::RenderWindow& window;
  sf::Font* font = new sf::Font();
  
  sf::Texture* background_texture;
  sf::Sprite* background;

  sf::Sprite* character;
  sf::Sprite* passport;
  sf::Texture* peoples = new sf::Texture[8];
  sf::Texture* passports = new sf::Texture[5];

  sf::Texture* accept_button_texture;
  sf::Texture* reject_button_texture;
  sf::Sprite* accept_button;
  sf::Sprite* reject_button;
  sf::Texture* accept;
  sf::Texture* reject;
  sf::Sprite* accept_sprite;
  sf::Sprite* reject_sprite;
  bool context_show = false;
  sf::Vector2f clickr;
  bool passport_accepted;
  bool passport_rejected;
  sf::Vector2f click_control;
  sf::Vector2i mouse_position_control;

  sf::Sprite* dragged = nullptr;
  sf::Vector2i mouse_position;
  sf::Vector2f mouse_positionf;
  sf::Vector2f drag_offset;
  sf::Vector2f drag_position;
  sf::Vector2f click;
  bool should_accept;
  bool clicked_button = false;  

  sf::Text* result_text;
  bool show_text = false;
  

};

#endif // SFML_GAME_H
