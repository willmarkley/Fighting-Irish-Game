// Character Class Implementation File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Character.h"
#include <iostream>

using namespace std;


const int CHARACTER_WIDTH = 100;   // character width
const int CHARACTER_HEIGHT = 89;  // character height
const int BULLET_WIDTH = 40;   // character width
const int BULLET_HEIGHT = 28;  // character height
const int ROOM_WIDTH = 960;     // room width
const int ROOM_HEIGHT = 768;    // room height

Character::Character(int a, int b){        // constructor
    // initialize the offsets
    img_rectangle.x = a;
    img_rectangle.y = b;
    img_rectangle.h = CHARACTER_HEIGHT;
    img_rectangle.w = CHARACTER_WIDTH;
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

void Character::move(Character e1, Character e2, Character e3){
    //Move the character left or right
    img_rectangle.x += xVel;

    //If the character went too far to the left or right
    if( ( img_rectangle.x < 0 )){
		img_rectangle.x = 0;
	}
	if(( img_rectangle.x + CHARACTER_WIDTH > ROOM_WIDTH )){
		img_rectangle.x = ROOM_WIDTH - CHARACTER_WIDTH;
    }
    if(collision_detect(img_rectangle,e1.img_rectangle) || collision_detect(img_rectangle,e2.img_rectangle) || collision_detect(img_rectangle,e3.img_rectangle))
    {
        //move back
        img_rectangle.x -= 10*xVel;
		health -= 1;
    }

    //Move the character up or down
    img_rectangle.y += yVel;

    //If the character went too far up or down
    if( ( img_rectangle.y < 0 )){
		img_rectangle.y = 0;
	}
	if( img_rectangle.y + CHARACTER_HEIGHT > ROOM_HEIGHT ){
		img_rectangle.y = ROOM_HEIGHT - CHARACTER_HEIGHT;
    }
    if(collision_detect(img_rectangle,e1.img_rectangle) || collision_detect(img_rectangle,e2.img_rectangle) || collision_detect(img_rectangle,e3.img_rectangle))
    {
        //move back
        img_rectangle.y -= 10*yVel;
		health -= 1;
    }
	if (xBullet > ROOM_WIDTH || xBullet < 0 || yBullet > ROOM_HEIGHT || yBullet < 0){
		bullet = 0;
		xBullet = img_rectangle.x;
		yBullet = img_rectangle.y;
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

int Character::getX(){           // returns X position
	return img_rectangle.x;
}

int Character::getY(){           // returns Y position
	return img_rectangle.y;
}

int Character::getxBullet(){           // returns X position
	return xBullet;
}

int Character::getyBullet(){           // returns Y position
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

