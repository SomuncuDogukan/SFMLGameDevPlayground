#include<iostream>
#include "Game.h"
#include <time.h>
//using namespace sf;

int main()
{

    //Init srand
    std::srand(static_cast<unsigned>(time(NULL))); // Ensure srand is initialized with an unsigned integer value representing current time.


    //Init Game Engine
    Game game;

    //Game loop
    while (game.running())
    {
        //Event polling





        // Update
        game.update();




        //Render
        game.render();
    




        //Draw the game

       // window.display(); //Tell app that window is done drawing
    }

    //End of application
    return 0;
}