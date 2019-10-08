#include "Layer.h"
#include <iostream>
void Layer::drawPoint(const Vector2i& where, const Color& penColor, int penWidth)
{
	for (int y = -penWidth / 2; y <= penWidth / 2; y++)
		for (int x = -penWidth / 2; x <= penWidth / 2; x++)
			image.setPixel(where.x + x, where.y + y, penColor);
}

Image Layer::getImage() const
{
	return image;
}

void Layer::drawLine(const Vector2i& from, const Vector2i& to, const Color& penColor, int penWidth)
{
	double steps = std::max(abs(to.x - from.x), abs(to.y - from.y));
	double stepX = (to.x - from.x) / steps;
	double stepY = (to.y - from.y) / steps;

	double xNow = from.x;
	double yNow = from.y;
	for (int stepNow = 0; stepNow < steps; stepNow++)
	{
		drawPoint(Vector2i(xNow + 0.5, yNow + 0.5), penColor, penWidth);
		xNow += stepX;
		yNow += stepY;
	}
}

bool Layer::isHidden() const
{
	return hidden;
}

void Layer::hide()
{
	hidden = true;
}

void Layer::show()
{
	hidden = false;
}

Layer::Layer(const Vector2i& size, const Color& color) : 
	m_size(size), hidden(false)
{
	image.create(size.x, size.y, color);
}
