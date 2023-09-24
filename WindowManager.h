#pragma once
#include <vector>
#include "Window.h"

class WindowManager
{
private:
	std::vector<Window> _wins;

public:
	void newWin(sf::Vector2f pos, sf::Vector2f size);
	void moveToFirst(int index);
	void unfocusAll();
	void closeWin(int index);

	std::vector<Window>& getWins();
	void draw(sf::RenderWindow& rw);

	bool isEmpty();
};

