// Character Base Class Header File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character {

	public:
		Character();          // constructor
		void handle_input(SDL_Event* event);  // handles key presses and adjusts the character's velocity
 		void move();          // moves the character
		int getX();           // returns X position
		int getY();           // returns X position
		int getImage();		  // return which image to use
		int getBullet();
		int getPressed();
		SDL_Surface* getSurface();  // returns the surface
	//	void shoot();         // character shoots projectiles
		int getHealth();	//returns health
		int getCharVel();	//returns character velocity
		void setHealth(int);	//sets health
		void setCharVel(int);	//sets character velocity
	private:
		int x, y;             // X and Y offsets of the character
		int image;            // calls left or right image
		int charVel;	      // stores character velocity
		int bullet;
		int lastPressed;
		int xVel, yVel;       // X and Y velocity of the character
		int health;           // character health
	//	int [] Item;          // status if an Item "i" was picked up
};

#endif
