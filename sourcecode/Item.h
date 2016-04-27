// Item Base Class Header File

#include "Character.h"

#ifndef ITEM_H
#define ITEM_H
using namespace std;

class Item {

	public:
		Item();				             // constructor
		void Check(Character c);         // checks what item is picked up
		void randItem();                 // creates random Item
		SDL_Surface* getSurface();       // returns a pointer to the SDL surface
		void setSurface(SDL_Surface*&);  // sets pointer to SDL surface
		SDL_Rect itemBox;

	private:
		SDL_Surface* surface;
		int ItemCreate;	// stores item selection
		int HP;			// stores health
};

#endif
