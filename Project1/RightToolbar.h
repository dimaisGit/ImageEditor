#pragma once
#include <vector>
#include <iterator>
#include "SFML/Graphics.hpp"
#include "Artist.h"
#include "Toolbar.h"
#include "Button.h"
#include "LayerToolbar.h"
using namespace sf;
class RightToolbar : public Toolbar
{
private:
	int m_layerToolbarHeight;
	int m_layerOffset;
	int m_layersPerScreen;
	int from;
	int to;
	Button addLayerButton;
	Button upArrowButton;
	Button downArrowButton;
	std::vector<LayerToolbar*> layerToolbars;
public:

	void update(const RenderWindow& window, Artist& artist);

	void draw(RenderWindow& window);

	RightToolbar(
		const Vector2f& position,
		const Vector2f& size,
		const Color& bgColor,
		int layerToolbarHeight
	);
	~RightToolbar();
};

