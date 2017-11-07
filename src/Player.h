// Player Derived Class Header File

#include "Character.h"
#include "Item.h"
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player: public Character {
	
	public:
		Player(int=100, int=100,int=1);	                            // constructor
		void move(Character, Character, Character, Item);           // moves the character while checking for collisions
		void shoot(int, int, int);                                  // allows the character to shoot projectiles
		void handle_input(SDL_Event* event);                        // handles key presses and adjusts the character's velocity
		int getImage();                                             // returns which image to use
		int getPressed();                                           // returns the last pressed key
		int getxBullet();                                           // returns x position of bullet
		int getyBullet();                                           // returns y position of bullet
		int getBullet();				                            // returns bullet existence
		SDL_Surface* getSurfaceLeft();                              // returns a pointer to the left SDL surface
		void setSurfaceLeft(SDL_Surface*&);                         // sets pointer to the left SDL surface
		void collision_Bullet(Character&, Character&, Character&);  // checks bullet collision with enemies
		int getItemHit();

	private:
		int image;                  // determines left or right image
		int lastPressed;            // represents the last key pressed
		int bullet;                 // determines bullet existence
		int pressed;                // represents key press
		SDL_Surface* surface_Left;  // SDL surface of character
		SDL_Rect incomingBullet;    // Rectangle of Bullet
		int itemHit;
		int tempVel;
};

#endif
