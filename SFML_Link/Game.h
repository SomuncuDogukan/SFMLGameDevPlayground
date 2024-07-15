#pragma once

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


	//Private Functions
private:
	//Variables
	//Window
	sf::RenderWindow* window;  
	sf::VideoMode videoMode;
	sf::Event ev;

	void initializeVariables();
	void initWindow();



public:

	//Consturctors / Destructors
	Game(); //Constructor

	virtual ~Game(); //Destructor

	//Accesors
	const bool running() const;


	//Functions
	void pollEvents();

	void update();

	void render();




};

