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
const int CHARACTER_WIDTH  = 100;  // character width
const int CHARACTER_HEIGHT = 89;   // character height
const int BULLET_WIDTH     = 40;   // character width
const int BULLET_HEIGHT    = 28;   // character height
const int ROOM_WIDTH       = 960;  // room width
const int ROOM_HEIGHT      = 768;  // room height


// Functions

Bullet::Bullet(int a, int b) : Character(a, b){        // constructor
    // initialize the offsets
	placeholder = 0;

	// initialize values

}

void Bullet::move(Character e1, Character e2, Character e3, Character player){
	
	if (collision_detect(incomingBullet,e1.img_rectangle) || collision_detect(incomingBullet,e2.img_rectangle) || collision_detect(incomingBullet,e3.img_rectangle))
    {
        //move back
		health -= 1;
		incomingBullet.x = player.img_rectangle.x;
		incomingBullet.y = player.img_rectangle.y;
    }

}
