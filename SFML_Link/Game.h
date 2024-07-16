#pragma once

//#ifndef GAME_H // if not defined
//#define GAME_H


#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Network.hpp>

//Check pre-compiled headers after all


/*
	Class that acts like the game engine.
	Wrapper class.

*/

class Game
{


	
private:
	//Variables
	//Window
	sf::RenderWindow* window;  
	sf::VideoMode videoMode;
	sf::Event ev;

	//Game objects
	// 
	//sf::Sprite  //maybe later

	sf::RectangleShape enemy;



	//Private Functions
	void initializeVariables();
	void initWindow();
	void initEnemies();


public:

	//Consturctors / Destructors
	Game(); //Constructor - Called when a new game object has been created from Game class. 

	virtual ~Game(); //Destructor - Called automatically when a game object is destroyed, used cleanup the tasks. 
					// Virtual for polymorphism and the sign of '~' for destructor.
	
					
	//Accesors
	const bool running() const;


	//Functions
	void pollEvents();

	void update();

	void render();




};

