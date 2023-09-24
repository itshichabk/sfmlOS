#include "WindowManager.h"

void WindowManager::newWin(sf::Vector2f pos, sf::Vector2f size)
{
    _wins.insert(_wins.begin(), Window(pos, size));

    unfocusAll();
    _wins[0].setFocused(true);
}

void WindowManager::moveToFirst(int index)
{
    std::rotate(_wins.begin(), _wins.begin() + index, _wins.begin() + index + 1);

    unfocusAll();
    _wins[0].setFocused(true);
}

void WindowManager::unfocusAll()
{
    for (Window& w : _wins)
    {
        w.setFocused(false);
    }
}

void WindowManager::closeWin(int index)
{
    _wins.erase(_wins.begin() + index);
    unfocusAll();
}

std::vector<Window>& WindowManager::getWins()
{
    return _wins;
}

void WindowManager::draw(sf::RenderWindow& rw)
{
    for (std::vector<Window>::size_type i = _wins.size() - 1; i != (std::vector<Window>::size_type) - 1; i--)
    {
        _wins[i].draw(rw);
    }
}

bool WindowManager::isEmpty()
{
    return _wins.empty();
}
