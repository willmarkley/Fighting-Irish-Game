// Item Base Class Header File

#include "Character.h"

#ifndef ITEM_H
#define ITEM_H
using namespace std;

class Item {

	public:
		Item();                          // constructor
		void Check(Character*);          // checks what item is picked up
		void randItem();                 // creates random Item
		SDL_Surface* getSurface();       // returns a pointer to the SDL surface
		void setSurface(SDL_Surface*&);  // sets pointer to SDL surface
		SDL_Rect getRect();              // returns SDL Rectangle of item
		int getItemX();                  // returns x position of item
		int getItemY();                  // returns y position of item

	private:
		SDL_Surface* surface;  // SDL surface of item
		SDL_Rect itemBox;      // rectangle of item
		int ItemCreate;        // stores item selection
};

#endif
