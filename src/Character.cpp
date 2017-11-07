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
const int ROOM_WIDTH       = 1092; // room width
const int ROOM_HEIGHT      = 602;  // room height


// Methods

Character::Character(int a, int b){  // constructor
    // initialize the offsets
    img_rectangle.x = a;
    img_rectangle.y = b;
    img_rectangle.h = CHARACTER_HEIGHT;
    img_rectangle.w = CHARACTER_WIDTH;

	// initialize the values
    xVel    = 0;
    yVel    = 0;
}


void Character::move(Character e1, Character e2, Character e3){}  // virtual function that is redefined in derived classes


bool Character::collision_detect(SDL_Rect r1, SDL_Rect r2){  // collision detection function
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;

    //Calculate the sides of rect r1
    left1 = r1.x;
    right1 = r1.x + r1.w;
    top1 = r1.y;
    bottom1 = r1.y + r1.h;    

    //Calculate the sides of rect r2
    left2 = r2.x;
    right2 = r2.x + r2.w;
    top2 = r2.y;
    bottom2 = r2.y + r2.h;

    // if any r1 sides exist outside r2
    if( bottom1 <= top2 )
    {
        return false;
    }

    if( top1 >= bottom2 )
    {
        return false;
    }

    if( right1 <= left2 )
    {
        return false;
    }

    if( left1 >= right2 )
    {
        return false;
    }

    // if none of the sides from r1 are outside r2
    return true;  // collision detected
}


/*
	GET and SET Methods (see .h for descriptions)
*/


int Character::getX(){
	return img_rectangle.x;
}

int Character::getY(){
	return img_rectangle.y;
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



