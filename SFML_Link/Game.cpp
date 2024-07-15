#include "Game.h"



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

	//this->window = new  sf::RenderWindow(sf::VideoMode(800, 600), "2D Window Test_Game 1", sf::Style::Titlebar | sf::Style::Close | sf::Style::Close);
}

Game::Game()
{
	this->initializeVariables();
	this->initWindow();
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

    //Functions
void Game::update() //Updates the game - logic
{
    
    this->pollEvents();
 


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
    this->window->clear(sf::Color(255, 0, 0, 255));

    //Draw game objects

    this->window->display();
}
