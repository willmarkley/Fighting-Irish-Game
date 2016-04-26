// Bullet Derived Class Header File

#include "Character.h"


#ifndef BULLET_H
#define BULLET_H

class Bullet: public Character {
	
	public:
		Bullet(int=100, int=100);	                              // constructor
		void move(Character e1, Character e2, Character e3, Character player);  // checks for collisions with enemies
		// void enemyShoot(); not used
	private:
		int placeholder;
};

#endif
