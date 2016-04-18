// Enemy Derived Class Header File
#include "Character.h"
using namespace std;

#ifndef ENEMY_H
#define ENEMY_H

class Enemy: public Character {
	
	public:
		Enemy(int=100, int=100);	//Constructor
		void enemyMove(Character player, Character e2, Character e3);
		void enemyShoot();
		SDL_Rect incomingBullet;

	protected:
		int enemyHealth;

	private:
		int random, ranCounter;
};

#endif
