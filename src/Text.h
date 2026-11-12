#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include <format>
using namespace std;

class Text
{
	public:
		Text();
		~Text();
		makeText(string text, sf::Font font, int size, int x, int y);


};
#endif // SFML_GAME_H