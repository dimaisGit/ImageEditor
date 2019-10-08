#pragma once
#include "SFML/Graphics.hpp"
#include "Toolbar.h"
#include "Button.h"
#include "Artist.h"
using namespace sf;
class BottomToolbar : public Toolbar
{
private:
	Button coordsButton;
	Button sizeLabelButton;
	Button colorLabelButton;

	Button set1PXPenWidthButton;
	Button set3PXPenWidthButton;
	Button set5PXPenWidthButton;
	Button setCustomPenWidthButton;

	Button setColorWhiteButton;
	Button setColorBlackButton;
	Button setColorRedButton;
	Button setColorGreenButton;
	Button setColorBlueButton;
	Button setCustomColorButton;

	Color getColorInput();
	
public:

	void update(const RenderWindow& window, Artist& artist);

	void draw(RenderWindow& window) const;

	template <typename T>
	static T getInput(const char* msg, bool range = false, int minValue = 0, int maxValue = 10000000, std::string errorMsg = "Please enter a valid value\n");

	BottomToolbar(
		const Vector2f& position,
		const Vector2f& size,
		const Color& bgColor
	);

};

