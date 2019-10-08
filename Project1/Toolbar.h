#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Toolbar
{
protected:
	Vector2f m_position;
	RectangleShape m_background;
	Color m_bgColor;
	Vector2f m_size;
public:

	void draw(RenderWindow& window) const;

	Toolbar(
		const Vector2f& position,
		const Vector2f& size,
		const Color& bgColor
	);
};

