// Enemy Derived Class Header File

using namespace std;

#ifndef ENEMY_H
#define ENEMY_H

class Enemy: public Character {
	
	public:
		Enemy();	//Constructor
		void move();
		int getX();
		int getY();
		int getImage();
		void shoot();		
		//int getBullet();
		//int getxBullet();
		//int getyBullet();
		//int getHealth();

	private:
		int health;
		int xBullet, yBullet;
		int x, y;
		int bullet;
		int xVel, yVel;
};

#endif
