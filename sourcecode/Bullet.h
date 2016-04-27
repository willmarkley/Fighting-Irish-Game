// Bullet Derived Class Header File

#include "Character.h"


#ifndef BULLET_H
#define BULLET_H

class Bullet: public Character {
	
	public:
		Bullet(int=100, int=100);	                              // constructor
		void move(Character&, Character&, Character&);  // checks for collisions with enemies
		SDL_Rect incomingBullet;
	private:
		int placeholder;
};

#endif
