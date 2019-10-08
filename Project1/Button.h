#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace sf;
using std::string;
class Button
{
private:
	Vector2f position;
	Font font;
	short fontSize;
	Vector2i padding;
	bool isButtonClicked;
	Clock clickTimer;
	int clickDelay;
	Text textForButton;
	string outString;
	RectangleShape background;
	Color backgroundColor;
	Color textColor;
	Color backgroundOnHoverColor;
	Color textOnHoverColor;

	void setPosition();
	bool isMouseInArea(const FloatRect& area, const RenderWindow& window) const;
public:
	void setText(const string& outString);
	void setPositionY(int y);

	void draw(RenderWindow& window) const;
	void update(const RenderWindow& window);

	bool isClicked();

	Button(
		const Vector2f& position = Vector2f(0, 0),
		const string& outString = "null",
		const Vector2i& padding = Vector2i(0, 0),
		const string& pathToFont = "Fonts/font.ttf",
		short fontSize = 20,
		const Color& backgroundColor = Color::White,
		const Color& textColor = Color::Black,
		const Color& backgroundOnHoverColor = Color::Black,
		const Color& textOnHoverColor = Color::White
	);
	~Button();
};

