// Character Class Implementation File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Character.h"
using namespace std;


const int CHARACTER_WIDTH = 100;   // character width
const int CHARACTER_HEIGHT = 86;  // character height
const int BULLET_WIDTH = 40;   // character width
const int BULLET_HEIGHT = 28;  // character height
const int ROOM_WIDTH = 960;     // room width
const int ROOM_HEIGHT = 768;    // room height

Character::Character(){        // constructor
    // initialize the offsets
    x = 0;
    y = 0;
	image = 1;
	bullet=0;
	lastPressed=4;
	charVel = 5;
	health = 3;
    // initialize the velocity
    xVel = 0;
    yVel = 0;
}

void Character::handle_input(SDL_Event* event){
    //If a key was pressed
    if( event->type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event->key.keysym.sym )
        {
            case SDLK_UP: yVel -= charVel; lastPressed=1; break;
            case SDLK_DOWN: yVel += charVel; lastPressed=2;break;
            case SDLK_LEFT: xVel -= charVel; image = 0; lastPressed=3; break;
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
            case SDLK_UP: yVel += charVel; break;
            case SDLK_DOWN: yVel -= charVel; break;
            case SDLK_LEFT: xVel += charVel; break;
            case SDLK_RIGHT: xVel -= charVel; break;
        }
    }
}

void Character::move()
{
    //Move the character left or right
    x += xVel;

    //If the character went too far to the left or right
    if( ( x < 0 ) || ( x + CHARACTER_WIDTH > ROOM_WIDTH ) )
    {
        //move back
        x -= xVel;
    }

    //Move the character up or down
    y += yVel;

    //If the character went too far up or down
    if( ( y < 0 ) || ( y + CHARACTER_HEIGHT > ROOM_HEIGHT ) )
    {
        //move back
        y -= yVel;
    }
}

void Character::shoot(int x, int y, int bullet, int lastPressed){
    if (bullet == 0){
        xBullet = x;
        yBullet = y;
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
	if (xBullet >= ROOM_WIDTH || xBullet <= 0 || yBullet >= ROOM_HEIGHT || yBullet <= 0){
		bullet = 0;
	}
}

int Character::getX(){           // returns X position
	return x;
}

int Character::getY(){           // returns X position
	return y;
}

int Character::getxBullet(){           // returns X position
	return xBullet;
}

int Character::getyBullet(){           // returns X position
	return yBullet;
}

int Character::getImage(){
	return image;
}

int Character::getBullet(){
	return bullet;
}

int Character::getPressed(){
	return lastPressed;
}

int Character::getHealth(){
	return health;
}

int Character::getCharVel(){
	return charVel;
}

void Character::setHealth(int num){
	health = num;
}

void Character::setCharVel(int num){
	charVel = num;
}
	
