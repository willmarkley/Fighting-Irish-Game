// Item Class Implementation File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Item.h"
#include "Character.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Constants
const int CHARACTER_WIDTH  = 100;  // Character width
const int CHARACTER_HEIGHT = 89;   // Character height
const int ITEM_WIDTH     = 50;   // Item width
const int ITEM_HEIGHT    = 50;   // Item height
const int ROOM_WIDTH       = 1092;  // Room width
const int ROOM_HEIGHT      = 602;  // Room height

Item::Item() {		//Constructor
	time_t start, end;
	ItemCreate = 0;
	randItem();
	itemBox.x = 450;
	itemBox.y = 344;
	itemBox.h = ITEM_HEIGHT;
	itemBox.w = ITEM_WIDTH;
}


void Item::randItem() {
	ItemCreate = rand() % 5 + 1;
}


void Item::Check(Character* player) {		//Checks what item was picked up
	if( ItemCreate == 1){
		if( player->getHealth() < 5 ){
			player->setHealth(player->getHealth() + 1);
		}
	}
	else if( ItemCreate == 2){
		player->setCharVel(player->getCharVel() + 3);
	}
	else if( ItemCreate == 3){
		player->setHealth(player->getHealth() - 1);
	}
	else if( ItemCreate == 4){
		player->setCharVel(player->getCharVel() - 2);
	}
	else if( ItemCreate == 5){
		player->setHealth(10);
	}
}



int Item::getItemX() {
	return itemBox.x;
}


int Item::getItemY() {
	return itemBox.y;
}


SDL_Surface* Item::getSurface(){
	return surface;
}


void Item::setSurface(SDL_Surface*& img_name){
	surface = img_name;
}


SDL_Rect Item::getRect(){
	return itemBox;
}
