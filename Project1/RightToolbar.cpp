#include "RightToolbar.h"

RightToolbar::RightToolbar(
	const Vector2f& position,
	const Vector2f& size,
	const Color& bgColor,
	int layerToolbarHeight
) :
	Toolbar(position, size, bgColor),
	m_layerToolbarHeight(layerToolbarHeight),
	m_layerOffset(3),
	m_layersPerScreen(4),
	from(0),
	to(0),
	addLayerButton(Button(position, "ADD", Vector2i(74, 10))),
	upArrowButton(Button(Vector2f(position.x, position.y + 35), "^", Vector2i(95, 10))),
	downArrowButton(Button(Vector2f(position.x, position.y + size.y - 35), "v", Vector2i(95, 10)))
{
	layerToolbars.push_back(new LayerToolbar(position, Vector2f(size.x, m_layerToolbarHeight), Color::Black));
}

RightToolbar::~RightToolbar()
{
	for (std::vector<LayerToolbar*>::iterator layerPtr = layerToolbars.begin(); layerPtr != layerToolbars.end(); layerPtr++)
		delete *layerPtr;
}

void RightToolbar::update(const RenderWindow& window, Artist& artist)
{
	addLayerButton.update(window);
	upArrowButton.update(window);
	downArrowButton.update(window);

	for (std::vector<LayerToolbar*>::iterator layerPtr = layerToolbars.begin(); layerPtr != layerToolbars.end(); layerPtr++)
		(*layerPtr)->update(window, artist);

	if (addLayerButton.isClicked())
	{
		artist.addLayer();
		artist.selectLayer(layerToolbars.size());
		layerToolbars.push_back(new LayerToolbar(m_position, Vector2f(m_size.x, m_layerToolbarHeight), Color::Black, layerToolbars.size()));
		from = layerToolbars.size() - 1;
		to = std::max(int(layerToolbars.size()) - m_layersPerScreen, 0);
	}
	if (upArrowButton.isClicked())
	{
		from = std::min(int(layerToolbars.size()) - 1, from + 1);
		to = std::max(from - m_layersPerScreen + 1, 0);
	}
	if (downArrowButton.isClicked())
	{
		from = std::max(from - 1, 0);
		to = std::max(to - 1, 0);
	}

}

void RightToolbar::draw(RenderWindow& window)
{
	Toolbar::draw(window);

	addLayerButton.draw(window);
	upArrowButton.draw(window);
	downArrowButton.draw(window);
	for (int i = from; i >= to; i--)
	{
		layerToolbars[i]->setPositionY(m_layerToolbarHeight * (from - i) + m_position.y + 64 + (from - i) * m_layerOffset);
		layerToolbars[i]->draw(window);
	}
}
