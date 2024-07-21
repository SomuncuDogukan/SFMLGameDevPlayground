#include "Game.h"
#include <iostream>
#include <ctime>

//Private functions
void Game::initializeVariables()
{
	this->window = nullptr;

    //Game logic variables comes from Game.h
    //this->points = 0;
    //this->enemySpawnTimer = 0.f;
    //this->enemySpawnTimerMax = 1000.f; //todo realclock timer
    //this->maxEnemies = 5;
	

    //todo realclock timer
    //Enemies spawn directly
    this->points = 0;
    this->enemySpawnTimerMax = 10000.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;

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


/*
   The term "poll event" in the SFML library refers to a function call
   used to track user interactions and system events. This function is
   used to capture window events (such as mouse or keyboard inputs),
   game events (like timer or game state changes), and other system
   events.
*/


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

void Game::spawnEnemy()
{
    /*
        @return void

        Spawn enemies and sets their color and positions.
        -Sets a random position.
        -Sets a random color.
        -Adds enemy to the vector.

    */

    this->enemy.setPosition(
        static_cast<float> (rand() % static_cast<int>(this->window->getSize().x) - (this->enemy.getSize().x)),
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().y) - (this->enemy.getSize().y))
        );
    
    this->enemy.setFillColor(sf::Color::Green);

    //Spawn the enemy
    this->enemies.push_back(this->enemy);

}

void Game::updateMousePosition()
{
    /*
    @return void

    Updates the mouse position:
        *Mouse position relative to window (Vector2i)
         
        
    */

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

    
void Game::updateEnemies()
{
    /**
        @return void

        Updates the enemy spawn timer and spawns enemies
        when the total number of enemies are smaller than the maximum of them.
        Moves the enemies downwards.
        Removes the enemies at the edge of the screen. //TODO
    
    */

    //Updating the timer for enemy spawning

    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {

            //Spawn the enemy and reset the timer
            
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;

        }
        else
            this->enemySpawnTimer += 1.f;

    }

    //Moving and Updating the enemies
    for (int i = 0; i < this->enemies.size(); i++) {
        
        this->enemies[i].move(0.f, 5.f);
        bool deleted = false;

        //Check if clicked upon
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        
            //contains: Checks if a specific point is inside the bounds of an object.
            //intersects: Determines whether the bounds of two objects overlap.
            if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
            {
                this->enemies.erase(this->enemies.begin() + i); //To erase, it founds the realted enemy

            }

        }

        if (this->enemies[i].getPosition().y >= this->window->getSize().y)
        {
            ////std::cout << "Enemy is out of the window";

            //deleted = true;

            ////Score
            //this->points += 5.f;

        }

        //Final Delete
        if (deleted) {


            this->enemies.erase(this->enemies.begin() + i);

        }

    }

}

void Game::update() //Updates the game - logic
{
    //Functions

    this->pollEvents();

    this->updateMousePosition();

    this->updateEnemies();
    
    //update mouse position
    
    //std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n"; //Relative to the all screen
    
    //std::cout << "Mouse pos: "
    //    << sf::Mouse::getPosition(*this->window).x 
    //    << " " << sf::Mouse::getPosition(*this->window).y << "\n"; //Relative to the window screen
}

void Game::renderEnemies()
{
    for (auto&e : this->enemies) {

        this->window->draw(e);

    }

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
    //this->window->draw(this->enemy);
    this->renderEnemies();

    this->window->display();
}
