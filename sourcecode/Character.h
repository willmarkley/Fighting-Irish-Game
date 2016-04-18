// Character Base Class Header File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character {

	public:
		Character(int=500,int=500);          // constructor
		void handle_input(SDL_Event* event);  // handles key presses and adjusts the character's velocity
 		void move();          // moves the character
		int getX();           // returns X position
		int getY();           // returns X position
		int getImage();		  // return which image to use
		void shoot(int, int, int, int);  // character shoots projectiles
		int getBullet();
		int getxBullet();
		int getyBullet();
		int getPressed();
		SDL_Surface* getSurface();  // returns the surface
		int getHealth();	//returns health
		int getCharVel();	//returns character velocity
		void setHealth(int);	//sets health
		void setCharVel(int);	//sets character velocity
		void move(Character e1, Character e2, Character e3);
		bool collision_detect(SDL_Rect r1, SDL_Rect r2);

	private:
		SDL_Rect img_rectangle;  // SDL rectangle that represents an image
		int image;            // calls left or right image
		int charVel;	      // stores character velocity
		int bullet;
		int lastPressed;
		int xVel, yVel;       // X and Y velocity of the character
		int health;           // character health
		int xBullet, yBullet, pressed;    //for the bullet shooting
};

#endif
