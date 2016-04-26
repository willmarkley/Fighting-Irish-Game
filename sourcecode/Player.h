// Player Derived Class Header File

#include "Character.h"
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player: public Character {
	
	public:
		Player(int=100, int=100);	//Constructor
		// move
		// shoot
		void handle_input(SDL_Event* event);  // handles key presses and adjusts the character's velocity
		int getImage();                       // returns which image to use
		int getPressed();                     // returns the last pressed key
		SDL_Surface* getSurfaceLeft();            // returns a pointer to the left SDL surface
		void setSurfaceLeft(SDL_Surface*&);       // sets pointer to the left SDL surface

	private:
		int image;                  // determines left or right image
		int lastPressed;
		SDL_Surface* surface_Left;  // SDL surface of character
};

#endif
