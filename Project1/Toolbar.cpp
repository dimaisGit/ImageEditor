#include "Toolbar.h"

Toolbar::Toolbar(
	const Vector2f& position,
	const Vector2f& size,
	const Color& bgColor
) :
	m_position(position),
	m_size(size),
	m_bgColor(bgColor)
{
	m_background.setSize(m_size);
	m_background.setFillColor(m_bgColor);
	m_background.setPosition(m_position);
}

void Toolbar::draw(RenderWindow& window) const
{
	window.draw(m_background);
}