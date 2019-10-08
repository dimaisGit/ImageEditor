#include "LayerToolbar.h"

LayerToolbar::LayerToolbar(
	const Vector2f& position,
	const Vector2f& size,
	const Color& bgColor,
	int innerValue
)
	:
	Toolbar(position, size, bgColor),
	m_innerValue(innerValue),
	hideButton(Button(position, "HIDE", Vector2i(25, 10))),
	showButton(Button(Vector2f(position.x + 104, position.y), "SHOW", Vector2i(15, 10))),
	labelButton(Button(Vector2f(position.x, position.y + 35), std::to_string(innerValue) + " layer", Vector2i(50, 10))),
	selectButton(Button(Vector2f(position.x, position.y + 70), "SELECT", Vector2i(52, 10)))
{

}

void LayerToolbar::setPositionY(int y)
{
	m_background.setPosition(Vector2f(m_position.x, y));
	hideButton.setPositionY(y);
	showButton.setPositionY(y);
	labelButton.setPositionY(y + 35);
	selectButton.setPositionY(y + 70);
}

void LayerToolbar::update(const RenderWindow& window, Artist& artist)
{
	hideButton.update(window);
	showButton.update(window);
	labelButton.update(window);
	selectButton.update(window);

	if (selectButton.isClicked())
		artist.selectLayer(m_innerValue);
	if (hideButton.isClicked())
		artist.hideLayer(m_innerValue);
	if (showButton.isClicked())
		artist.showLayer(m_innerValue);
}

void LayerToolbar::draw(RenderWindow& window) const
{
	Toolbar::draw(window);

	hideButton.draw(window);
	showButton.draw(window);
	labelButton.draw(window);
	selectButton.draw(window);
}