//Enemy derived class implementation

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Enemy.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int CHARACTER_WIDTH = 100;   // character width
const int CHARACTER_HEIGHT = 89;  // character height
const int ROOM_WIDTH = 960;     // room width
const int ROOM_HEIGHT = 768;    // room height

Enemy::Enemy(int a, int b) : Character(a, b){        // constructor
    // initialize the offsets
    image = 1;
    bullet=0;
    lastPressed=4;
    charVel = 3;
    health = 3;
    // initialize the velocity
    xVel = 0;
    yVel = 0;
	random = 0;
	ranCounter = 100;
}

void Enemy::enemyMove(Character e1, Character e2, Character e3){
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

    //If the character went too far to the left or right
    if(img_rectangle.x < 0){
		img_rectangle = 0;

	if( img_rectangle.x + CHARACTER_WIDTH > ROOM_WIDTH ){
		img_rectangle.x = ROOM_WIDTH - CHARACTER_WIDTH;
	}
	if (collision_detect(img_rectangle,e1.img_rectangle) || collision_detect(img_rectangle,e2.img_rectangle) || collision_detect(img_rectangle,e3.img_rectangle))
    {
        //move back
        img_rectangle.x -= 10*xVel;
		health -= 1;
    }

    //Move the character up or down
    img_rectangle.y += yVel;

    //If the character went too far up or down
    if( img_rectangle.y < 0 ){
		img_rectangle.y = 0;
 	}
	if( img_rectangle.y + CHARACTER_HEIGHT > ROOM_HEIGHT ){
		img_rectangle.y = ROOM_HEIGHT - CHARACTER_HEIGHT;
	}
	if (collision_detect(img_rectangle,e1.img_rectangle) || collision_detect(img_rectangle,e2.img_rectangle) || collision_detect(img_rectangle,e3.img_rectangle))
    {
        //move back
        img_rectangle.y -= 10*yVel;
		health -= 1;
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
	if (xBullet > ROOM_WIDTH || xBullet < 0 || yBullet > ROOM_HEIGHT || yBullet < 0){
		bullet = 0;
		xBullet = img_rectangle.x;
		yBullet = img_rectangle.y;
	}
}
