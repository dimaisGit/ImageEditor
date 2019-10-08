#include "BottomToolbar.h"
#include <iostream>
#include <string>

BottomToolbar::BottomToolbar(
	const Vector2f& position, 
	const Vector2f& size,
	const Color& bgColor
) :
	Toolbar(position, size, bgColor),
	coordsButton(Button(Vector2f(position.x, position.y + 74), "0, 0", Vector2i(10, 10))),

	sizeLabelButton(Button(Vector2f(position.x, position.y + 2), "Pen width: ", Vector2i(10, 10))),
	colorLabelButton(Button(Vector2f(position.x, position.y + 38), "Pen color: ", Vector2i(10, 10))),

	set1PXPenWidthButton(Button(Vector2f(position.x + 170, position.y + 2), "1px", Vector2i(10, 10))),
	set3PXPenWidthButton(Button(Vector2f(position.x + 232, position.y + 2), "3px", Vector2i(10, 10))),
	set5PXPenWidthButton(Button(Vector2f(position.x + 303, position.y + 2), "5px", Vector2i(10, 10))),
	setCustomPenWidthButton(Button(Vector2f(position.x + 373, position.y + 2), "CUSTOM", Vector2i(10, 10))),

	setColorWhiteButton(Button(Vector2f(position.x + 174, position.y + 38), "WHITE", Vector2i(10, 10))),
	setColorBlackButton(Button(Vector2f(position.x + 273, position.y + 38), "BLACK", Vector2i(10, 10))),
	setColorRedButton(Button(Vector2f(position.x + 379, position.y + 38), "RED", Vector2i(10, 10))),
	setColorGreenButton(Button(Vector2f(position.x + 450, position.y + 38), "GREEN", Vector2i(10, 10))),
	setColorBlueButton(Button(Vector2f(position.x + 556, position.y + 38), "BLUE", Vector2i(10, 10))),
	setCustomColorButton(Button(Vector2f(position.x + 641, position.y + 38), "CUSTOM", Vector2i(10, 10)))
{

}

void BottomToolbar::update(const RenderWindow& window, Artist& artist)
{

	Vector2i coordsInCamera = artist.mouseCoordInCamera(Mouse::getPosition(window));
	coordsButton.setText(std::to_string(coordsInCamera.x) + ", " + std::to_string(coordsInCamera.y));
	coordsButton.update(window);

	sizeLabelButton.update(window);
	colorLabelButton.update(window);

	set1PXPenWidthButton.update(window);
	set3PXPenWidthButton.update(window);
	set5PXPenWidthButton.update(window);
	setCustomPenWidthButton.update(window);

	setColorWhiteButton.update(window);
	setColorBlackButton.update(window);
	setColorRedButton.update(window);
	setColorGreenButton.update(window);
	setColorBlueButton.update(window);
	setCustomColorButton.update(window);

	if (set1PXPenWidthButton.isClicked())
		artist.setPenWidth(1);
	if (set3PXPenWidthButton.isClicked())
		artist.setPenWidth(3);
	if (set5PXPenWidthButton.isClicked())
		artist.setPenWidth(5);
	if (setCustomPenWidthButton.isClicked())
		artist.setPenWidth(getInput<short>(
			"Please enter pen width:\n",
			true,
			1,
			200
			)
		);

	if (setColorWhiteButton.isClicked())
		artist.setPenColor(Color::White);
	if (setColorBlackButton.isClicked())
		artist.setPenColor(Color::Black);
	if (setColorRedButton.isClicked())
		artist.setPenColor(Color::Red);
	if (setColorGreenButton.isClicked())
		artist.setPenColor(Color::Green);
	if (setColorBlueButton.isClicked())
		artist.setPenColor(Color::Blue);
	if (setCustomColorButton.isClicked())
		artist.setPenColor(getColorInput());
}

Color BottomToolbar::getColorInput()
{
	short R = getInput<short>(
		"You need to enter data for color in RGB format, Red value first:\n",
		true,
		0,
		255
		);
	short G = getInput<short>(
		"Ok, now time for Green value:\n",
		true,
		0,
		255
		);
	short B = getInput<short>(
		"Well, Blue value:\n",
		true,
		0,
		255
		);
	return Color(R, G, B);
}

void BottomToolbar::draw(RenderWindow& window) const
{
	Toolbar::draw(window);

	coordsButton.draw(window);

	sizeLabelButton.draw(window);
	colorLabelButton.draw(window);

	set1PXPenWidthButton.draw(window);
	set3PXPenWidthButton.draw(window);
	set5PXPenWidthButton.draw(window);
	setCustomPenWidthButton.draw(window);

	setColorWhiteButton.draw(window);
	setColorBlackButton.draw(window);
	setColorRedButton.draw(window);
	setColorGreenButton.draw(window);
	setColorBlueButton.draw(window);
	setCustomColorButton.draw(window);
}

template <typename T>
static T BottomToolbar::getInput(const char* msg, bool range, int minValue, int maxValue, std::string errorMsg)
{
	std::cout << msg;
	T input;
	while (!(std::cin >> input) || range && std::cin && (input < minValue || input > maxValue))
	{
		std::cout << errorMsg;
		std::cin.clear();
		while (std::cin.get() != '\n');
	}
	return input;
}