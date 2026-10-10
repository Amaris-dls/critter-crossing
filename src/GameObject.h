#ifndef SFML_GAMEOBJECT_H
#define SFML_GAMEOBJECT_H

#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject
{
 public:
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture& texture, std::string filename);
  sf::Sprite* getSprite();
  bool visibility;
  int speed;


 //private:
  sf::Sprite* sprite = nullptr;
};





#endif // SFML_GAMEOBJECT_H