#pragma once
#include <vector>
#include <iterator>
#include "SFML/Graphics.hpp"
#include "Layer.h"
using namespace sf;

class Artist
{
private:
	Vector2i m_size;
	Vector2i m_cameraSize;
	Vector2i m_position;
	Vector2i prevMousePos;
	View camera;
	double cameraSpeed;
	Clock clock;
	Color m_penColor;
	int m_penWidth;
	Texture texture;
	Sprite sprite;
	int currentLayerIndex;
	std::vector<Layer> layers;

	void resetSprite();
	void handleMouse(const RenderWindow& window);
	void handleKeyboard();
	Image getResultingImage();
public:
	void save();
	void update(const RenderWindow& window);
	Vector2i mouseCoordInCamera(const Vector2i& mousePos) const;

	void setPenWidth(int penWidth);
	void setPenColor(const Color& color);
	void addLayer();
	void selectLayer(int layerIndex);
	void hideLayer(int layerIndex);
	void showLayer(int layerIndex);

	void draw(RenderWindow& window) const;

	Artist(
		const Vector2i& cameraSize, 
		const Vector2i& picSize, 
		const Vector2i& position = Vector2i(0, 0), 
		const Color& penColor = Color::White, 
		int penWidth = 1,
		const Color& initialColor = Color::White
	);
};

