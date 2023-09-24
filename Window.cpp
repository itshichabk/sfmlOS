#include "Window.h"

Window::Window()
{
	_selected = false;
	_dragged = false;
	_mouseOffset = sf::Vector2f(0, 0);

	_titleBar.setSize(sf::Vector2f(400, 20));
	_titleBar.setPosition(100, 80);
	_titleBar.setOutlineColor(sf::Color::Black);
	_titleBar.setOutlineThickness(1);
	_titleBar.setFillColor(sf::Color::Blue);

	//_shadow.setSize(sf::Vector2f(400, 320));
	//_shadow.setPosition(100 + _shadowSize, 80 + _shadowSize);
	//_shadow.setFillColor(sf::Color(0, 0, 0, 100));

	_winRect.setSize(sf::Vector2f(400, 300));
	_winRect.setPosition(100, 100);
	_winRect.setOutlineColor(sf::Color::Black);
	_winRect.setOutlineThickness(1);
}

Window::Window(float x, float y)
{
	_selected = false;
	_mouseOffset = sf::Vector2f(0, 0);

	_titleBar.setSize(sf::Vector2f(400, 20));
	_titleBar.setPosition(x, y);
	_titleBar.setOutlineColor(sf::Color::Black);
	_titleBar.setOutlineThickness(1);
	_titleBar.setFillColor(sf::Color::Blue);

	//_shadow.setSize(sf::Vector2f(400, 320));
	//_shadow.setPosition(100 + _shadowSize, 80 + _shadowSize);
	//_shadow.setFillColor(sf::Color(0, 0, 0, 100));

	_winRect.setSize(sf::Vector2f(400, 300));
	_winRect.setPosition(x, y+20);
	_winRect.setOutlineColor(sf::Color::Black);
	_winRect.setOutlineThickness(1);
}

void Window::setSelected(const bool selected, const sf::Vector2i mousePos)
{
	_selected = selected;

	if (selected)
	{
		_mouseOffset.x = mousePos.x - _winRect.getPosition().x;
		_mouseOffset.y = mousePos.y - _winRect.getPosition().y;
		_titleBar.setFillColor(sf::Color::Green);
	}
	else
	{
		_titleBar.setFillColor(sf::Color::Blue);
	}
}

void Window::setDragged(const bool dragged)
{
	_dragged = dragged;
}

const bool Window::isDragged()
{
	return _dragged;
}

void Window::move(sf::Event::MouseMoveEvent& mv)
{
	_winRect.setPosition(mv.x - _mouseOffset.x, mv.y - _mouseOffset.y);
	_titleBar.setPosition(mv.x - _mouseOffset.x, mv.y - _mouseOffset.y - 20);
	//_shadow.setPosition(mv.x - _mouseOffset.x + _shadowSize, mv.y - _mouseOffset.y - _shadowSize);

}

void Window::draw(sf::RenderWindow& rw)
{
	rw.draw(_shadow);
	rw.draw(_titleBar);
	rw.draw(_winRect);
}
