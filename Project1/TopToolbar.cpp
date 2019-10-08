#include "TopToolbar.h"

TopToolbar::TopToolbar(
	const Vector2f& position,
	const Vector2f& size,
	const Color& bgColor
) :
	Toolbar(position, size, bgColor),
	saveButton(Button(position, "SAVE", Vector2i(15, 18)))
{

}

void TopToolbar::draw(RenderWindow& window) const
{
	Toolbar::draw(window);

	saveButton.draw(window);
}

void TopToolbar::update(const RenderWindow& window, Artist& artist)
{
	saveButton.update(window);

	if (saveButton.isClicked())
		artist.save();
}
