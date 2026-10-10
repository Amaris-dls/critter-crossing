#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
  srand(time(NULL));
}

GameObject::~GameObject()
{
  delete sprite;
}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
  if (!texture.loadFromFile(filename))
  {
    std::cout << "Failed to load sprite texture! \n";
    return false;
  }
  sprite = new sf::Sprite(texture);
  sprite->setTexture(texture);
  visibility = true;
  return true;
}
sf::Sprite* GameObject::getSprite()
{
  return sprite;
}