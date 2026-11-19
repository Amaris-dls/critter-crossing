#include "TextClass.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

TextClass::TextClass() {

}
TextClass::~TextClass() {
    delete textSprite;
}

bool TextClass::makeText(string input, sf::Font* font, int size, int x, int y) {
    if (!font->openFromFile("../Data/Fonts/open-sans/OpenSans-Regular.ttf"))
	{
		std::cerr << "Failed to load font" << std::endl;
		return false;
	}
    textSprite = new sf::Text(*font, input, size);
    textSprite->setPosition(sf::Vector2f(x, y));

    return true;
}

sf::Text* TextClass::getText() {
    return textSprite;
}