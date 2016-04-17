// Character Class Implementation File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Character.h"
using namespace std;


const int CHARACTER_WIDTH = 100;   // character width
const int CHARACTER_HEIGHT = 86;  // character height   

Character::Character(){        // constructor
    // initialize the offsets
    x = 0;
    y = 0;
	image = 1;

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
            case SDLK_UP: yVel -= 5; break;
            case SDLK_DOWN: yVel += 5; break;
            case SDLK_LEFT: xVel -= 5; image = 0; break;
            case SDLK_RIGHT: xVel += 5; image = 1; break;
        }
    }
    //If a key was released
    else if( event->type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event->key.keysym.sym )
        {
            case SDLK_UP: yVel += 5; break;
            case SDLK_DOWN: yVel -= 5; break;
            case SDLK_LEFT: xVel += 5; break;
            case SDLK_RIGHT: xVel -= 5; break;
        }
    }
}

void Character::move()
{
    //Move the character left or right
    x += xVel;

    //If the character went too far to the left or right
    if( ( x < 0 ) || ( x + CHARACTER_WIDTH > 960 ) )
    {
        //move back
        x -= xVel;
    }

    //Move the character up or down
    y += yVel;

    //If the character went too far up or down
    if( ( y < 0 ) || ( y + CHARACTER_HEIGHT > 768 ) )
    {
        //move back
        y -= yVel;
    }
}

int Character::getX(){           // returns X position
	return x;
}

int Character::getY(){           // returns X position
	return y;
}

int Character::getImage(){
	return image;
}
