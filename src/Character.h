// Character Base Class Header File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H


class Character {

	public:
		Character(int=500,int=500);                          // constructor
		virtual void move(Character, Character, Character);  // virtual function that is redefined in derived classes
		bool collision_detect(SDL_Rect r1, SDL_Rect r2);     // collision detection function

		// get functions
		int getX();                 // returns X position
		int getY();                 // returns X position
		int getHealth();	        // returns health
		int getCharVel();	        // returns character velocity
		SDL_Surface* getSurface();  // returns a pointer to the SDL surface

		// set functions
		void setHealth(int);	         // sets character health
		void setCharVel(int);	         // sets character velocity
		void setSurface(SDL_Surface*&);  // sets pointer to SDL surface
		int xVel, yVel;                  // X and Y velocity of the character
		SDL_Rect img_rectangle;          // SDL rectangle that represents an image

	protected:
		SDL_Surface* surface;  // SDL surface of character
		int charVel;	       // stores character velocity
		int health;            // character health
};

#endif
