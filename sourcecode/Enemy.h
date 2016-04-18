// Enemy Derived Class Header File
#include "Character.h"
using namespace std;

#ifndef ENEMY_H
#define ENEMY_H

class Enemy: public Character {
	
	public:
		Enemy(int=100, int=100);	//Constructor
		void enemyMove(Character e1, Character e2, Character e3);
		void enemyShoot();

	private:
		int random, ranCounter;
};

#endif
