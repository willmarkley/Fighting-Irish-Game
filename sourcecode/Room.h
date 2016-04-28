// Room Base Class Header File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Character.h"
#include "Enemy.h"
#include "Player.h"
#include "Item.h"
using namespace std;

#ifndef ROOM_H
#define ROOM_H

class Room{

	public:
		Room(string="", int=1);     // constructor
		~Room();                    // deconstructor
		void play();                // runs the game
		int getLevel();             // returns which level the room is

	private:
		SDL_Surface *background = NULL;      // background image
		SDL_Surface *window = NULL;          // window

		SDL_Surface *bullet_surface = NULL;  // bullet surface
		SDL_Surface *health1_surface = NULL; // health surface 1
		SDL_Surface *health2_surface = NULL; // health surface 2
		SDL_Surface *health3_surface = NULL; // health surface 3
		SDL_Surface *health4_surface = NULL; // health surface 4
		SDL_Surface *health5_surface = NULL; // health surface 5
		SDL_Surface *dead = NULL;            // death screen surface
		SDL_Surface *won = NULL;             // winning screen surface
		SDL_Surface *level1 = NULL;          // passing level 1 screen surface
		SDL_Surface *level2 = NULL;          // passing level 2 screen surface


		SDL_Event event;   // the event structure (to handle key presses)
		Player player;     // main player
		Enemy enemy1;      // enemy 1
		Enemy enemy2;      // enemy 2
		Enemy enemy3;      // enemy 3
		Enemy enemyBeat;   // new enemy with a position off the grid
		Item item1;        // item 1

		bool init();                                                // initilizes SDL
		SDL_Surface *load_image(string filename);                   // loads image to surface
		void apply_surface( int, int, SDL_Surface*, SDL_Surface*);  // applies image to surface
		bool update_screen();                                       // updates screen
		int e1, e2, e3;                                             // represent whether the enemy is dead (0) or alive (1)
		int level;                                                  // the level of the room
};

#endif
