#include "Game.h"
#include <iostream>


//Private functions
void Game::initializeVariables()
{
	this->window = nullptr;
	
}

void Game::initWindow()
{
	this->videoMode.width = 800;
	this->videoMode.height = 600;
	this->window = new  sf::RenderWindow(videoMode, "2D Window Test_Game 1", sf::Style::Titlebar | sf::Style::Close | sf::Style::Close);
    this->window->setFramerateLimit(60);
	//this->window = new  sf::RenderWindow(sf::VideoMode(800, 600), "2D Window Test_Game 1", sf::Style::Titlebar | sf::Style::Close | sf::Style::Close);
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f,10.f); //SFML, like OpenGL, has a coordinate system where the origin (0, 0) is in the top-left corner.
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));  //Setting up the size
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));   //Better way to manipulate the size of the object
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);

}

Game::Game()
{
	this->initializeVariables();
	this->initWindow();
    this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

//Accesors

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
    //Event polling
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case::sf::Event::Closed: //Close button
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }

    }

}

    
void Game::update() //Updates the game - logic
{
    //Functions

    this->pollEvents();
    
    //update mouse position
    
    std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n"; //Relative to the all screen
   

}

void Game::render()
{

    /*
        @return void       
        - clear old frame
        - render objects
        - display frame in window
    
        Renders the game objects
    */
    this->window->clear(); //becomes black 

    //Draw game objects
    this->window->draw(this->enemy);

    this->window->display();
}
