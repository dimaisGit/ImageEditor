#include "Button.h"
Button::Button(
	const Vector2f& position,
	const string& outString,
	const Vector2i& padding,
	const string& pathToFont,
	short fontSize,
	const Color& backgroundColor,
	const Color& textColor,
	const Color& backgroundOnHoverColor,
	const Color& textOnHoverColor
)
{
	this->position = position;
	this->padding = padding;
	this->fontSize = fontSize;
	this->outString = outString;
	this->backgroundColor = backgroundColor;
	this->textColor = textColor;
	this->backgroundOnHoverColor = backgroundOnHoverColor;
	this->textOnHoverColor = textOnHoverColor;
	this->clickDelay = 400;
	this->isButtonClicked = false;


	this->font.loadFromFile(pathToFont);
	this->textForButton = Text(this->outString, this->font, this->fontSize);
	this->textForButton.setPosition(position.x + padding.x, position.y + padding.y);
	this->textForButton.setColor(this->textColor);

	this->background.setPosition(position);
	this->background.setSize(Vector2f(
		this->textForButton.getLocalBounds().width + padding.x * 2,
		this->textForButton.getLocalBounds().height + padding.y * 2
	));
	this->background.setFillColor(this->backgroundColor);
}

void Button::draw(RenderWindow& window) const
{
	window.draw(background);
	window.draw(textForButton);
}

void Button::setText(const string& outString)
{
	this->outString = outString;
	this->textForButton = Text(outString, this->font, this->fontSize);
	this->textForButton.setPosition(position.x + padding.x, position.y + padding.y);
	this->textForButton.setColor(this->textColor);
	this->background.setSize(Vector2f(
		this->textForButton.getLocalBounds().width + padding.x * 2,
		this->textForButton.getLocalBounds().height + padding.y * 2
	));
	this->background.setFillColor(this->backgroundColor);
}

bool Button::isMouseInArea(const FloatRect& area, const RenderWindow& window) const
{
	return area.contains(Vector2f(
		Mouse::getPosition(window).x,
		Mouse::getPosition(window).y
	));
}

void Button::update(const RenderWindow& window)
{
	if (isMouseInArea(background.getGlobalBounds(), window))
	{
		background.setFillColor(backgroundOnHoverColor);
		textForButton.setColor(textOnHoverColor);

		if (Mouse::isButtonPressed(Mouse::Left) && clickTimer.getElapsedTime().asMilliseconds() > clickDelay)
		{
			isButtonClicked = true;
			clickTimer.restart();
		}

	}
	else
	{
		background.setFillColor(backgroundColor);
		textForButton.setColor(textColor);
	}
}

void Button::setPositionY(int y)
{
	position.y = y;
	setPosition();
}

void Button::setPosition()
{
	textForButton.setPosition(Vector2f(position.x + padding.x, position.y + padding.y));
	background.setPosition(position);
}

bool Button::isClicked()
{
	if (isButtonClicked)
	{
		isButtonClicked = false;
		return true;
	}
	else
		return false;
}

Button::~Button()
{

}