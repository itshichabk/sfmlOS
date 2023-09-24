#include "WindowManager.h"

void WindowManager::newWin(float x, float y)
{
    _wins.insert(_wins.begin(), Window(x, y));
}

void WindowManager::moveToFirst(int index)
{

    //std::iter_swap(_wins.begin() + 0, _wins.begin() + index);
    std::rotate(_wins.begin(), _wins.begin() + index, _wins.begin() + index + 1);
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
