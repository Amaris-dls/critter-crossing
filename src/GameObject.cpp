#include "GameObject.h"

GameObject::GameObject() {
	texture = std::make_unique<sf::Texture>();
	sprite = std::make_unique<sf::Sprite>(*texture);
}
GameObject::GameObject(const sf::Texture& texture) {
    sprite = std::make_unique<sf::Sprite>(texture);
}

sf::Sprite& GameObject::GetSprite() {
	return *sprite;
}

void GameObject::SetActive(bool active) {
	isActive = active;
}