#pragma once
#include "Toolbar.h"
#include "Artist.h"
#include "Button.h"
class TopToolbar : public Toolbar
{
private:
	Button saveButton;

public:

	void draw(RenderWindow& window) const;
	void update(const RenderWindow& window, Artist& artist);

	TopToolbar(
		const Vector2f& position, 
		const Vector2f& size, 
		const Color& bgColor
	);
};

