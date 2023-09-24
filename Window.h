#include <SFML/Graphics.hpp>

#pragma once
class Window
{
private:
	//const int _shadowSize = 10;
	sf::Vector2f _mouseOffset;
	bool _dragged;

public:
	sf::RectangleShape _titleBar;
	sf::RectangleShape _winRect;
	sf::RectangleShape _shadow;
	bool _selected;
	Window();
	Window(float x, float y);
	void setSelected(const bool selected, const sf::Vector2i mousePos = sf::Vector2i(0,0));
	void setDragged(const bool dragged);
	const bool isDragged();
	void move(sf::Event::MouseMoveEvent& mv);
	void draw(sf::RenderWindow& rw);
};

