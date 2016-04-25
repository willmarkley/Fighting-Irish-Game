// Character Base Class Header File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character {

	public:
		Character(int=500,int=500);                           // constructor
		void handle_input(SDL_Event* event);                  // handles key presses and adjusts the character's velocity
		void move(Character e1, Character e2, Character e3);  // moves the character while checking for collisions
		void shoot(int, int, int, int);                       // allows the character to shoot projectiles
		bool collision_detect(SDL_Rect r1, SDL_Rect r2);      // collision detection function

		// get functions
		int getX();                 // returns X position
		int getY();                 // returns X position
		int getImage();		        // returns which image to use		// DERIVED
		int getBullet();            // returns bullet
		int getxBullet();           // returns bullet x position
		int getyBullet();           // returns bullet y position
		int getPressed();           // returns the last pressed key
		int getHealth();	        // returns health
		int getCharVel();	        // returns character velocity
		SDL_Surface* getSurface();  // returns a pointer to the SDL surface

		// set functions
		void setHealth(int);	         // sets character health
		void setCharVel(int);	         // sets character velocity
		void setSurface(SDL_Surface*&);  // sets pointer to SDL surface

		SDL_Rect img_rectangle;  // SDL rectangle that represents an image
	

	protected:
		SDL_Surface* myimage;  // SDL surface of character
		int image;             // determines left or right image		// DERIVED
		int charVel;	       // stores character velocity
		int bullet;
		int lastPressed;
		int xVel, yVel;        // X and Y velocity of the character
		int health;            // character health
		int xBullet, yBullet, pressed;    // determines the bullet shooting
};

#endif
