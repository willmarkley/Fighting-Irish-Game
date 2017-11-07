// Player derived class implementation

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
using namespace std;

// Constants
const int CHARACTER_WIDTH  = 100;  // character width
const int CHARACTER_HEIGHT = 89;   // character height
const int BULLET_WIDTH     = 40;   // character width
const int BULLET_HEIGHT    = 28;   // character height
const int ROOM_WIDTH       = 1092; // room width
const int ROOM_HEIGHT      = 602;  // room height


// Methods

Player::Player(int a, int b, int round) : Character(a, b){ // constructor
	// initialize values
	image       = 1;
	lastPressed = 4;
	itemHit		= 0;
	tempVel = 0;
	if(round == 1 || round == 2){
    	charVel     = 5;
		health      = 5;
	} else if (round == 3){
		charVel = 5;
		health = 5;
	}

	// initialize bullet
   	bullet  = 0;
	incomingBullet.x = img_rectangle.x;
	incomingBullet.y = img_rectangle.y;
	incomingBullet.h = BULLET_HEIGHT;
	incomingBullet.w = BULLET_WIDTH;
}

void Player::move(Character e1, Character e2, Character e3, Item item){ // moves the character while checking for collisions
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
    if(collision_detect(img_rectangle,e1.img_rectangle) || collision_detect(img_rectangle,e2.img_rectangle) || collision_detect(img_rectangle,e3.img_rectangle))
    {
        // change x position back
        img_rectangle.x -= 10*xVel;
		health -= 1;
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
    if(collision_detect(img_rectangle,e1.img_rectangle) || collision_detect(img_rectangle,e2.img_rectangle) || collision_detect(img_rectangle,e3.img_rectangle))
    {
        // change x position back
        img_rectangle.y -= 10*yVel;
		health -= 1;
    }

	//Collision detection with Item and corresponding function calls	
	if(collision_detect(img_rectangle,item.getRect()) && !(itemHit)){
		itemHit = 1;
		tempVel = charVel;
		item.Check(this);
		if(tempVel != charVel && lastPressed==1){
			yVel += tempVel;
			yVel -= charVel;
		}else if(tempVel != charVel && lastPressed==2){
			yVel -= tempVel;
			yVel += charVel;
		}else if(tempVel != charVel && lastPressed==3){
			xVel += tempVel;
			xVel -= charVel;
		}else if(tempVel != charVel && lastPressed==4){
			xVel -= tempVel;
			xVel += charVel;
		}
	}

	//Checks if the bullet is on screen
	if (incomingBullet.x > ROOM_WIDTH || incomingBullet.x < 0 || incomingBullet.y > ROOM_HEIGHT || incomingBullet.y < 0){
		bullet = 0;
		incomingBullet.x = img_rectangle.x;
		incomingBullet.y = img_rectangle.y;
	}


}


void Player::handle_input(SDL_Event* event){ // handles key presses and adjusts the character's velocity
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
            case SDLK_UP:     if(charVel == 5) {yVel += charVel;} else{ yVel = -1;} break;
            case SDLK_DOWN:   if(charVel == 5) {yVel -= charVel;} else{ yVel = 1;} break;
            case SDLK_LEFT:   if(charVel == 5) {xVel += charVel;} else{ xVel = -1;} break;
            case SDLK_RIGHT:  if(charVel == 5) {xVel -= charVel;} else{ xVel = 1;} break;
			case SDLK_SPACE:
					if (incomingBullet.x > ROOM_WIDTH || incomingBullet.x < 0 || incomingBullet.y > ROOM_HEIGHT || incomingBullet.y < 0){
						bullet = 0;
						incomingBullet.x = img_rectangle.x;
						incomingBullet.y = img_rectangle.y;
					}
				break;
        }
    }
}


void Player::shoot(int x, int y, int lastPressed){ // allows the character to shoot projectiles
	// Checks if bullet exists
    if (bullet == 0){
		incomingBullet.x = img_rectangle.x;
		incomingBullet.y = img_rectangle.y;
        pressed = lastPressed;
    } else if (bullet == 1){
        if(pressed == 1){
            incomingBullet.y -= BULLET_HEIGHT;
        } else if (pressed == 2){
            incomingBullet.y += BULLET_HEIGHT;
        } else if (pressed == 3){
            incomingBullet.x -= BULLET_WIDTH;
        } else if (pressed == 4){
            incomingBullet.x += BULLET_WIDTH;
        }
    }
	
}


void Player::collision_Bullet(Character& e1, Character& e2, Character& e3){ //checks bullet collision with enemies
	// Collides with e1
	if(collision_detect(incomingBullet,e1.img_rectangle)){
		e1.setHealth(e1.getHealth() - 1);
		bullet=0;
	}
	// Collides with e2
	if(collision_detect(incomingBullet,e2.img_rectangle)){
		e2.setHealth(e2.getHealth() - 1);
		bullet=0;
	}
	// Collides with e3
	if(collision_detect(incomingBullet,e3.img_rectangle)){
		e3.setHealth(e3.getHealth() - 1);
		bullet=0;
    }
}

/*
	GET and SET Methods (see .h for descriptions)
*/

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

int Player::getxBullet(){
	return incomingBullet.x;
}

int Player::getyBullet(){
	return incomingBullet.y;
}

int Player::getBullet(){
	return bullet;
}

int Player::getItemHit(){
	return itemHit;
}
