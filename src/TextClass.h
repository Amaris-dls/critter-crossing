#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include <format>
using namespace std;

class TextClass
{
	public:
		TextClass();
		~TextClass();
		bool makeText(string input, sf::Font* font, int size, int x, int y);
		sf::Text* textSprite = nullptr;


};
#endif // SFML_GAME_H