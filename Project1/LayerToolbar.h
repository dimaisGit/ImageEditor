#pragma once
#include "SFML/Graphics.hpp"
#include "Artist.h"
#include "Button.h"
#include "Toolbar.h"
class LayerToolbar : public Toolbar
{
private:
	int m_innerValue;
	Button hideButton;
	Button showButton;
	Button labelButton;
	Button selectButton;
public:

	void setPositionY(int y);

	void update(const RenderWindow& window, Artist& artist);

	void draw(RenderWindow& window) const;

	LayerToolbar(
		const Vector2f& position, 
		const Vector2f& size, 
		const Color& bgColor, 
		int innerValue = 0
	);
};

