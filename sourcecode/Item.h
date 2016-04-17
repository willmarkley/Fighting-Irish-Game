// Item Base Class Header File

#include "Character.h"

#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item {
	public:
		Item();				//Constructor
		void Check(Character c);	//Checks what item is picked up
		void randItem();		//Creates random Item
	private:
		int x, y;	//Position of item
		int Items;	//Stores item selection
};

#endif
