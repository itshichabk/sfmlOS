#include <iostream>
#include "WindowManager.h"

void main()
{
    //sf::RenderWindow rwin(sf::VideoMode(1280, 720), "sfmlOS", sf::Style::Titlebar | sf::Style::Close);
    sf::RenderWindow rwin(sf::VideoMode(), "sfmlOS", sf::Style::Fullscreen);

    WindowManager wm;

    //Window window;
    int selectedWindow = 0;

    for (float i = 0; i < 1; i++)
    {
        wm.newWin(sf::Vector2f(i * 40, i * 40), sf::Vector2f(400, 300));
    }
    //wm.newWin(0, 0);
    //wm.newWin(120, 120);

    // run the program as long as the window is open
    while (rwin.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (rwin.pollEvent(event))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(rwin);

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                rwin.close();
                exit(0);
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::W)
                {
                    wm.newWin(sf::Vector2f(0, 0), sf::Vector2f(400, 300));
                }
                else if (event.key.code == sf::Keyboard::Escape)
                {
                    rwin.close();
                    exit(0);
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                int i = 0;
                bool clickedOnWin = false;

                for (Window& w : wm.getWins())
                {
                    if (w._titleBar.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || 
                        w._winRect.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            clickedOnWin = true;
                            w.setSelected(true, mousePos);
                            wm.moveToFirst(i);
                        }
                        else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                        {
                            wm.closeWin(i);
                        }
                        break;
                        //std::cout << mouseWinOffsetX << ", " << mouseWinOffsetY << ":)\n";
                    }
                    i++;
                }

                if (!clickedOnWin)
                {
                    wm.unfocusAll();
                }
                //if (window._titleBar.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                //{
                //    window.setSelected(true, mousePos);
                //    //std::cout << mouseWinOffsetX << ", " << mouseWinOffsetY << ":)\n";
                //}
            }
            else if (event.type == sf::Event::MouseButtonReleased && !wm.isEmpty())
            {
                //window._winRect.setFillColor(sf::Color::White);
                wm.getWins()[0].setSelected(false);
                wm.getWins()[0].setDragged(false);
                //std::cout << ":(\n";
            }

            if (!wm.isEmpty())
            {
                if (wm.getWins()[0]._selected)
                {
                    if (event.type == sf::Event::MouseMoved)
                    {
                        if (wm.getWins()[0].isDragged() || wm.getWins()[0]._titleBar.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
                        {
                            wm.getWins()[0].move(event.mouseMove);
                            wm.getWins()[0].setDragged(true);
                        }

                        /*window._winRect.setFillColor(sf::Color::Green);

                        float movedWinPosX = event.mouseMove.x - mouseWinOffsetX;
                        float movedWinPosY = event.mouseMove.y - mouseWinOffsetY;

                        window._winRect.setPosition(movedWinPosX, movedWinPosY);
                        window._titleBar.setPosition(movedWinPosX, movedWinPosY - 20);
                        window._shadow.setPosition(movedWinPosX + 10, movedWinPosY - 10);*/

                        //std::cout << mouseWinOffsetX << ", " << mouseWinOffsetX << ":(\n";
                    }
                }
            }

        }
        
        rwin.clear(sf::Color(59, 110, 165, 255));
        wm.draw(rwin);
        rwin.display();
    }
}