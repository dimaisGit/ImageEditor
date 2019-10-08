#include <string>
#include "Artist.h"

Artist::Artist(
	const Vector2i& cameraSize, 
	const Vector2i& picSize, 
	const Vector2i& position, 
	const Color& penColor, 
	int penWidth,
	const Color& initialColor
) :
	m_size(picSize), 
	m_cameraSize(cameraSize), 
	m_position(position),
	camera(View(Vector2f(picSize.x / 2, picSize.y / 2),
	Vector2f(cameraSize.x, cameraSize.y))), 
	m_penColor(penColor), 
	prevMousePos(Vector2i(-1, -1)), 
	m_penWidth(penWidth), 
	cameraSpeed(400),
	currentLayerIndex(0)
{
	layers.push_back(Layer(picSize, initialColor));
	sprite.setTextureRect(IntRect(Vector2i(0, 0), picSize));
	resetSprite();
	camera.zoom(2);
}

void Artist::draw(RenderWindow& window) const
{
	View prevView = window.getView();
	window.setView(camera);
	window.draw(sprite);
	window.setView(prevView);
}

void Artist::setPenColor(const Color& color)
{
	m_penColor = color;
}

void Artist::addLayer()
{
	layers.push_back(Layer(m_size, Color(0, 0, 0, 0)));
}

void Artist::selectLayer(int layerIndex)
{
	currentLayerIndex = layerIndex;
}

void Artist::hideLayer(int layerIndex)
{
	layers[layerIndex].hide();
	resetSprite();
}

void Artist::showLayer(int layerIndex)
{
	layers[layerIndex].show();
	resetSprite();
}

Image Artist::getResultingImage()
{
	Image resultImage;
	resultImage.create(m_size.x, m_size.y, Color(0, 0, 0, 0));
	for (std::vector<Layer>::iterator layerPtr = layers.begin(); layerPtr != layers.end(); layerPtr++)
	{
		if (layerPtr->isHidden())
			continue;
		Image tempImage = layerPtr->getImage();
		for (int y = 0; y < m_size.x; y++)
			for (int x = 0; x < m_size.x; x++)
				if (tempImage.getPixel(x, y).a)
					resultImage.setPixel(x, y, tempImage.getPixel(x, y));
	}
	return resultImage;
}

void Artist::save()
{
	Image resultImage = getResultingImage();
	std::string imageName = std::to_string(rand()) + std::to_string(rand()) + std::to_string(rand()) + std::to_string(rand()) + ".png";
	resultImage.saveToFile(imageName);
}

void Artist::resetSprite()
{
	Image resultImage = getResultingImage();
	texture.loadFromImage(resultImage);
	sprite.setTexture(texture);
}

Vector2i Artist::mouseCoordInCamera(const Vector2i& mousePos) const
{
	double scaleX = camera.getSize().x / double(m_cameraSize.x);
	double scaleY = camera.getSize().y / double(m_cameraSize.y);

	return Vector2i(
		mousePos.x * scaleX + camera.getCenter().x - camera.getSize().x / 2,
		mousePos.y * scaleY + camera.getCenter().y - camera.getSize().y / 2
	);
}

void Artist::setPenWidth(int penWidth)
{
	m_penWidth = penWidth;
}

void Artist::handleMouse(const RenderWindow& window)
{

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		Vector2i mousePos = mouseCoordInCamera(Mouse::getPosition(window));
		if (mousePos.x > m_penWidth / 2 - 1 && mousePos.x < m_size.x - m_penWidth / 2 && mousePos.y > m_penWidth / 2 - 1 && mousePos.y < m_size.y - m_penWidth / 2)
		{
			if (prevMousePos.x == -1 && prevMousePos.y == -1)
			{
				prevMousePos = mousePos;
				layers[currentLayerIndex].drawPoint(mousePos, m_penColor, m_penWidth);
			}
			else
			{
				layers[currentLayerIndex].drawLine(prevMousePos, mousePos, m_penColor, m_penWidth);
				prevMousePos = mousePos;
			}
			resetSprite();
		}
	}
	else
		prevMousePos = Vector2i(-1, -1);
}

void Artist::handleKeyboard()
{
	double elapsedTimeInSeconds = clock.getElapsedTime().asMicroseconds() / 1000000.0;
	clock.restart();
	if (Keyboard::isKeyPressed(Keyboard::Left))
		camera.move(-cameraSpeed * elapsedTimeInSeconds, 0);
	if (Keyboard::isKeyPressed(Keyboard::Right))
		camera.move(cameraSpeed * elapsedTimeInSeconds, 0);
	if (Keyboard::isKeyPressed(Keyboard::Up))
		camera.move(0, -cameraSpeed * elapsedTimeInSeconds);
	if (Keyboard::isKeyPressed(Keyboard::Down))
		camera.move(0, cameraSpeed * elapsedTimeInSeconds);
	if (Keyboard::isKeyPressed(Keyboard::LControl))
	{
		if (Keyboard::isKeyPressed(Keyboard::Equal))
			camera.zoom(0.999);
		if (Keyboard::isKeyPressed(Keyboard::Num0))
			camera.zoom(1.001);
	}
}

void Artist::update(const RenderWindow& window)
{
	handleMouse(window);
	handleKeyboard();
}