// Room Base Class Header File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Character.h"
#include "Enemy.h"
using namespace std;

#ifndef ROOM_H
#define ROOM_H

class Room{

	public:
		Room(string="");     // constructor
		~Room();    // deconstructor
		void play();         // plays the game

	private:
		SDL_Surface *background = NULL;   // background image
		SDL_Surface *window = NULL;       // window
		SDL_Surface *character_left = NULL;  // character surface
		SDL_Surface *character_right = NULL; //character surface
		SDL_Surface *enemy1_surface = NULL;  // character surface
		SDL_Surface *enemy2_surface = NULL;  // character surface
		SDL_Surface *enemy3_surface = NULL;  // character surface
		SDL_Surface *bullet_surface = NULL;  // character surface
		SDL_Surface *item_surface = NULL;  // item surface
		SDL_Event event;      // the event structure (to handle key presses)
		Character player;    // main player
		Enemy enemy1;
		Character enemy2;
		Character enemy3;
		//void shoot(int,int,int,int);
		//int xBullet, yBullet;
		//int pressed;

		bool init();           // initilizes SDL
		SDL_Surface *load_image(string filename);  // loads image to surface
		void apply_surface( int, int, SDL_Surface*, SDL_Surface*);  // applies image to surface
		bool update_screen();   // updates screen
};

#endif
