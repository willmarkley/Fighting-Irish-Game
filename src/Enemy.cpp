// Enemy derived class implementation

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Constants
const int CHARACTER_WIDTH  = 100;  // character width
const int CHARACTER_HEIGHT = 89;   // character height
const int ROOM_WIDTH       = 1092; // room width
const int ROOM_HEIGHT      = 602;  // room height


// Methods

Enemy::Enemy(int a, int b, int round) : Character(a, b){  // constructor
	// initialize values
	if(round == 1){
	    charVel = 3;
		health = 3;
	}else if(round == 2){
		charVel = 7;
		health = 7;
	}else if(round == 3){
		charVel = 10;
		health = 15;
	}
	random     = 0;
	ranCounter = 100;
}

void Enemy::move(Character &p1, Character &e2, Character &e3){  // moves the enemy while checking for collisions
	if (ranCounter == 100){
		random = rand() % 4 + 1;
		ranCounter = 0;
	} else{
		ranCounter++;
	}
	if (random == 1){
		yVel -= charVel;
	} else if (random == 2){
		yVel += charVel;
	} else if (random == 3){
		xVel -= charVel;
	} else if (random == 4){
		xVel += charVel;
	}    
	//Move the character left or right
    img_rectangle.x += xVel;

    //If the character went too far to the left
    if(img_rectangle.x < 0){
		img_rectangle.x = 0;
	}
	//If the character went too far to the right
	if(img_rectangle.x + CHARACTER_WIDTH > ROOM_WIDTH){
		img_rectangle.x = ROOM_WIDTH - CHARACTER_WIDTH;
	}
	//If Collision with another Character after changing x position
	if (collision_detect(img_rectangle,p1.img_rectangle))
    {
        // change x position back
        img_rectangle.x -= 10*xVel;
		p1.setHealth(p1.getHealth() - 1);
    }
	if(collision_detect(img_rectangle,e2.img_rectangle) || collision_detect(img_rectangle,e3.img_rectangle))
	{
		img_rectangle.x -= 10*xVel;
	}

    //Move the character up or down
    img_rectangle.y += yVel;

    //If the character went too far up
    if(img_rectangle.y < 0){
		img_rectangle.y = 0;
	}
	//If the character went too far updown
	if(img_rectangle.y + CHARACTER_HEIGHT > ROOM_HEIGHT){
		img_rectangle.y = ROOM_HEIGHT - CHARACTER_HEIGHT;
    }

	//If Collision with another Character after changing y position
	if (collision_detect(img_rectangle,p1.img_rectangle))
    {
        // change x position back
        img_rectangle.y -= 10*yVel;
		p1.setHealth(p1.getHealth() - 1);
    }
	if(collision_detect(img_rectangle,e2.img_rectangle) || collision_detect(img_rectangle,e3.img_rectangle))
	{
		img_rectangle.y -= 10*yVel;
	}

	if (random == 1){
		yVel += charVel;
	} else if (random == 2){
		yVel -= charVel;
	} else if (random == 3){
		xVel += charVel;
	} else if (random == 4){
		xVel -= charVel;
	}    

}



