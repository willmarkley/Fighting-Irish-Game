// Item Class Implementation File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Item.h"
#include "Character.h"
#include <stdlib.h>
using namespace std;

Item::Item() {		//Constructor
	Items = 0;
}


void Item::randItem() {
	Items = rand() % 3 + 1;
}


void Item::Check(Character c) {		//Checks what item was picked up
	if( Items == 1){
		c.setHealth(c.getHealth() + 1);	
	}
	else if( Items == 2){
		c.setCharVel(c.getCharVel() + 4);
	}
	else if( Items == 3){
		c.setHealth(c.getHealth() - 1);
	}
}


SDL_Surface* Item::getSurface(){
	return surface;
}


void Item::setSurface(SDL_Surface*& img_name){
	surface = img_name;
}

