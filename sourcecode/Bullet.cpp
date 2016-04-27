// Bullet derived class implementation

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Bullet.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Constants
const int CHARACTER_WIDTH  = 100;  // Character width
const int CHARACTER_HEIGHT = 89;   // Character height
const int BULLET_WIDTH     = 40;   // Bullet width
const int BULLET_HEIGHT    = 28;   // Bullet height
const int ROOM_WIDTH       = 960;  // Room width
const int ROOM_HEIGHT      = 768;  // Room height


// Functions

Bullet::Bullet(int a, int b) : Character(a, b){        // constructor
    // initialize the offsets
	incomingBullet.x = getxBullet();
	incomingBullet.y = getyBullet();
	incomingBullet.h = BULLET_HEIGHT;
	incomingBullet.w = BULLET_WIDTH;

	// initialize values

}

void Bullet::move(Character& e1, Character& e2, Character& e3){
	// Collides with e1
	if(collision_detect(incomingBullet,e1.img_rectangle)){
		e1.setHealth(e1.getHealth() - 1);
	}
	// Collides with e2
	if(collision_detect(incomingBullet,e2.img_rectangle)){
		e2.setHealth(e2.getHealth() - 1);
	}
	// Collides with e3
	if(collision_detect(incomingBullet,e3.img_rectangle)){
		e3.setHealth(e3.getHealth() - 1);
    }
}
