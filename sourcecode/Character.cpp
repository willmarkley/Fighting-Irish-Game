// Character Class Implementation File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Character.h"
#include <iostream>
using namespace std;

// Constants
const int CHARACTER_WIDTH  = 100;  // character width
const int CHARACTER_HEIGHT = 89;   // character height
const int BULLET_WIDTH     = 40;   // character width
const int BULLET_HEIGHT    = 28;   // character height
const int ROOM_WIDTH       = 960;  // room width
const int ROOM_HEIGHT      = 768;  // room height


// Functions

Character::Character(int a, int b){
    // initialize the offsets
    img_rectangle.x = a;
    img_rectangle.y = b;
    img_rectangle.h = CHARACTER_HEIGHT;
    img_rectangle.w = CHARACTER_WIDTH;
	incomingBullet.x = xBullet;
	incomingBullet.y = yBullet;
	incomingBullet.h = BULLET_HEIGHT;
	incomingBullet.w = BULLET_WIDTH;

	// initialize the values
    bullet  = 0;
    xVel    = 0;
    yVel    = 0;
	health = 5;
	enemyHealth = 3;
}


void Character::move(Character e1, Character e2, Character e3){}


void Character::shoot(int x, int y, int bullet, int lastPressed){
    if (bullet == 0){
        xBullet = img_rectangle.x;
        yBullet = img_rectangle.y;
        pressed = lastPressed;
    } else if (bullet == 1){
        if(pressed == 1){
            yBullet -= BULLET_HEIGHT;
        } else if (pressed == 2){
            yBullet += BULLET_HEIGHT;
        } else if (pressed == 3){
            xBullet -= BULLET_WIDTH;
        } else if (pressed == 4){
            xBullet += BULLET_WIDTH;
        }
    }
}


bool Character::collision_detect(SDL_Rect r1, SDL_Rect r2){
    int leftr1, leftr2;
    int rightr1, rightr2;
    int topr1, topr2;
    int bottomr1, bottomr2;

    //Calculate the sides of rect r1
    leftr1 = r1.x;
    rightr1 = r1.x + r1.w;
    topr1 = r1.y;
    bottomr1 = r1.y + r1.h;    

    //Calculate the sides of rect r2
    leftr2 = r2.x;
    rightr2 = r2.x + r2.w;
    topr2 = r2.y;
    bottomr2 = r2.y + r2.h;

    // if any r1 sides exist outside r2
    if( bottomr1 <= topr2 )
    {
        return false;
    }

    if( topr1 >= bottomr2 )
    {
        return false;
    }

    if( rightr1 <= leftr2 )
    {
        return false;
    }

    if( leftr1 >= rightr2 )
    {
        return false;
    }

    // if none of the sides from r1 are outside r2
    return true;  // collision detected
}


/*
	GET and SET Functions
		-See Character.h for descriptions
*/


int Character::getX(){
	return img_rectangle.x;
}

int Character::getY(){
	return img_rectangle.y;
}

int Character::getxBullet(){
	return xBullet;
}

int Character::getyBullet(){
	return yBullet;
}

int Character::getBullet(){
	return bullet;
}

void Character::setBullet(int num){
	bullet = num;
}

int Character::getHealth(){
	return health;
}

int Character::getCharVel(){
	return charVel;
}

SDL_Surface* Character::getSurface(){
	return surface;
}

void Character::setHealth(int num){
	health = num;
}

void Character::setCharVel(int num){
	charVel = num;
}

void Character::setSurface(SDL_Surface*& img_name){
	surface = img_name;
}



