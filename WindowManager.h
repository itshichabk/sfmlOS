#pragma once
#include <vector>
#include "Window.h"

class WindowManager
{
private:
	std::vector<Window> _wins;

public:
	void newWin(float x, float y);
	void moveToFirst(int index);

	std::vector<Window>& getWins();
	void draw(sf::RenderWindow& rw);
};

