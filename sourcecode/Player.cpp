// Player derived class implementation

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Player.h"
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

Player::Player(int a, int b) : Character(a, b){        // constructor
	// initialize values
    image = 1;
    bullet=0;
    lastPressed=4;
    charVel = 3;
    health = 3;
    xVel = 0;
    yVel = 0;
}

/*
void Player::move(Character player, Character e2, Character e3){

}
*/

void Player::handle_input(SDL_Event* event){
    //If a key was pressed
    if( event->type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event->key.keysym.sym )
        {
            case SDLK_UP:    yVel -= charVel; lastPressed=1; break;
            case SDLK_DOWN:  yVel += charVel; lastPressed=2;break;
            case SDLK_LEFT:  xVel -= charVel; image = 0; lastPressed=3; break;
            case SDLK_RIGHT: xVel += charVel; image = 1; lastPressed=4; break;
            case SDLK_SPACE: bullet=1; break;
        }
    }
    //If a key was released
    else if( event->type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event->key.keysym.sym )
        {
            case SDLK_UP:    yVel += charVel; break;
            case SDLK_DOWN:  yVel -= charVel; break;
            case SDLK_LEFT:  xVel += charVel; break;
            case SDLK_RIGHT: xVel -= charVel; break;
			case SDLK_SPACE:
					if (xBullet > ROOM_WIDTH || xBullet < 0 || yBullet > ROOM_HEIGHT || yBullet < 0){
						bullet = 0;
						xBullet = img_rectangle.x;
						yBullet = img_rectangle.y;
					}
				break;
        }
    }
}


int Player::getImage(){
	return image;
}


int Player::getPressed(){
	return lastPressed;
}

SDL_Surface* Player::getSurfaceLeft(){
	return surface_Left;
}

void Player::setSurfaceLeft(SDL_Surface*& img_name){
	surface_Left = img_name;
}



