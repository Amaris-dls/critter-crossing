#pragma once
#include <SFML/Graphics.hpp>
using namespace std;

class GameObject {

public:
	GameObject();
	~GameObject() = default;

	sf::Sprite& GetSprite();
	void SetActive(bool active);


private:
	unique_ptr<sf::Sprite> sprite;
	unique_ptr<sf::Texture> texture;
	bool isActive = true;

}