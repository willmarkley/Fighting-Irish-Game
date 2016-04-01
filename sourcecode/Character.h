//Character base class header file


#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character {
	public:
		//Initializes the variables
		Character();

		//Takes key presses and adjusts the character's velocity
		void handle_input();

		//Moves the character
 		void move();

		//Shows the character on the screen
		void show();
		
		//Character shoots projectiles
		void shoot();
	private:
		//The X and Y offsets of the character
		int x, y;

		//The velocity of the character
		int xVel, yVel;
		
		//The number of health the character has
		int health;
	
		//Status if an Item was picked up
		int Item1, Item2, Item3, Item4;
};
#endif
				
	
