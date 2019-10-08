#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

class Layer
{
private:
	Vector2i m_size;

	Image image;//layer for drawing
	bool hidden;

public:
	void drawPoint(const Vector2i& where, const Color& penColor, int penWidth);
	void drawLine(const Vector2i& from, const Vector2i& to, const Color& penColor, int penWidth);
	void hide();
	void show();


	Image getImage() const;
	bool isHidden() const;

	Layer(const Vector2i& size, const Color& color);
};

