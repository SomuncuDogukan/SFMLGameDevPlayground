#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>
#include<iostream>

//using namespace sf;

int main()
{
    //Window Operations
    sf::RenderWindow window(sf::VideoMode(640, 480), "2D Window Test", sf::Style::Titlebar | sf::Style::Close | sf::Style::Close);
    sf::Event ev;

    //Game loop
    while (window.isOpen())
    {
        //Event polling

        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case:: sf::Event::Closed: //Close button
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }


            

        }


        // Update

        //Render
        window.clear(); //Clear old frame
        //window.clear(sf::Color::Blue); //Clear with the blue color.
        //Draw the game

        window.display(); //Tell app that window is done drawing
    }

    //End of application
    return 0;
}