#include <SFML/Graphics.hpp>

#pragma once
class Window
{
private:
	//const int _shadowSize = 10;
	sf::Vector2i _size;
	sf::Vector2f _mouseOffset;
	bool _dragged;
	bool _focused;

public:
	sf::RectangleShape _titleBar;
	sf::RectangleShape _winRect;
	sf::RectangleShape _shadow;
	bool _selected;

	Window();
	Window(float x, float y);
	Window(sf::Vector2f pos, sf::Vector2f size);

	void setSelected(const bool selected, const sf::Vector2i mousePos = sf::Vector2i(0,0));
	void setDragged(const bool dragged);
	void setFocused(const bool focused);
	const bool isDragged();
	void move(sf::Event::MouseMoveEvent& mv);
	void draw(sf::RenderWindow& rw);
};

