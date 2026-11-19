
#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include <format>
#include "TextClass.h"
#include "GameObject.h"
#include <array>
#include <iostream>
using namespace std;

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
  enum GameState{MENU, PLAY, LOSE, WIN};

 private:
  sf::RenderWindow& window;
  sf::Font* font = new sf::Font();
  
  std::unique_ptr<sf::Texture> background_texture;
  std::unique_ptr<sf::Sprite> background;

  std::unique_ptr<GameObject> character;
  std::unique_ptr<GameObject> passport;
  std::unique_ptr<sf::Texture[]> peoples;
  std::unique_ptr<sf::Texture[]> passports;
  //sf::Texture* passports = new sf::Texture[5];
  TextClass start_button;
  TextClass quit_button;
  GameState state = MENU;

  unique_ptr<sf::Texture> accept_button_texture;
  unique_ptr<sf::Texture> reject_button_texture;
  unique_ptr<GameObject> accept_button;
  unique_ptr<GameObject> reject_button;
  unique_ptr<sf::Texture> accept;
  unique_ptr<sf::Texture> reject;
  unique_ptr<sf::Texture> table_texture;
  std::unique_ptr<GameObject> accept_sprite;
  std::unique_ptr<GameObject> reject_sprite;
  bool context_show = false;
  sf::Vector2f clickr;
  bool passport_accepted;
  bool passport_rejected;
  sf::Vector2f click_accept;
  sf::Vector2f click_reject;
  sf::Vector2i mouse_position_control;

  unique_ptr<GameObject> table;

  sf::Sprite* dragged = nullptr;
  sf::Vector2i mouse_position;
  sf::Vector2f mouse_positionf;
  sf::Vector2f drag_offset;
  sf::Vector2f drag_position;
  sf::Vector2f click;
  bool should_accept;
  bool clicked_button = false;  

  TextClass result_text;
  bool show_text = false;

  bool stamp_chosen;

  TextClass timer_text;
  float time_remaining = 5.0f;

  TextClass game_over_text;
  TextClass restart_button;


  //sf::Text* image_names = new sf::Text[8];
  

};

#endif // SFML_GAME_H
