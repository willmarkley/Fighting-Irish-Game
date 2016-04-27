// Room Class Implementation File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include "Room.h"
#include "Character.h"
#include "Timer.h"
#include "Item.h"
#include "Enemy.h"
#include "Player.h"

using namespace std;

const int ROOM_WIDTH        = 1092;   // room width
const int ROOM_HEIGHT       = 602;    // room height
const int ROOM_BPP          = 32;     // room bits per pixel
const int FRAMES_PER_SECOND = 60;     // frame rate


Room::Room(string filename,int round):player(200, 300, round), enemy1(400,500, round), enemy2(200,600, round), enemy3(800,600, round), enemyBeat(-1000,-1000, round){    // constructor
	// Initialize SDL
	init();
	background = load_image(filename);
	apply_surface(0,0,background,window);
	update_screen();

	// Assign surfaces to objects
	SDL_Surface* temp_surface;

	temp_surface = load_image("images/leprechaun_left.bmp");
	player.setSurfaceLeft(temp_surface);
	temp_surface = load_image("images/leprechaun_right.bmp");
	player.setSurface(temp_surface);
	temp_surface = load_image("images/michigan.bmp");
	enemy1.setSurface(temp_surface);
	temp_surface = load_image("images/bc.bmp");
	enemy2.setSurface(temp_surface);
	temp_surface = load_image("images/usc.bmp");
	enemy3.setSurface(temp_surface);
	temp_surface = load_image("images/question-mark.bmp");
	item1.setSurface(temp_surface);

	bullet_surface = load_image("images/football.bmp");	

	health1_surface=load_image("images/health1.bmp");
	health2_surface=load_image("images/health2.bmp");
	health3_surface=load_image("images/health3.bmp");
	health4_surface=load_image("images/health4.bmp");
	health5_surface=load_image("images/health5.bmp");
	dead=load_image("images/youdied.bmp");
	won = load_image("images/won.bmp");
	level1 = load_image("images/level1.bmp");
	e1 = 1;
	e2 = 1;
	e3 = 1;
	level = round;
}


Room::~Room(){    // deconstructor
	SDL_FreeSurface(player.getSurface());
	SDL_FreeSurface(player.getSurfaceLeft());
	SDL_FreeSurface(item1.getSurface());
	SDL_FreeSurface(enemy1.getSurface());
	SDL_FreeSurface(enemy2.getSurface());
	SDL_FreeSurface(enemy3.getSurface());
	SDL_FreeSurface(enemyBeat.getSurface());
	SDL_FreeSurface(bullet_surface);
	SDL_FreeSurface(health1_surface);
	SDL_FreeSurface(health2_surface);
	SDL_FreeSurface(health3_surface);
	SDL_FreeSurface(health4_surface);
	SDL_FreeSurface(health5_surface);
	SDL_FreeSurface(background);
	SDL_FreeSurface(window);
	SDL_FreeSurface(dead);
	SDL_FreeSurface(won);
	SDL_FreeSurface(level1);
	SDL_Quit();
}

void Room::play(){ 
    Timer fps;   // frame rate regulator								// NOT SURE IF WE NEED TIMER  (or any calls to fps)
	bool QUIT=false;

	while(!QUIT){
		fps.start();   // start the frame timer
		while( SDL_PollEvent( &event ) )   // execute while there is an event that needs to be handled
		{
		    player.handle_input( &event );         // handle the characters events

		    if( event.type == SDL_QUIT ){  // closed window
		        QUIT = true;
		    }
		}

		apply_surface(0,0,background,window);
		player.move(enemy1,enemy2,enemy3,item1);  // move player according to input
		player.collision(enemy1, enemy2, enemy3);
		

		if(e1 == 1){
			enemy1.move(player, enemy2, enemy3);
			apply_surface(enemy1.getX(),enemy1.getY(),enemy1.getSurface(), window);
		}
		if(e2 == 1){
			enemy2.move(player, enemy1, enemy3);
			apply_surface(enemy2.getX(),enemy2.getY(),enemy2.getSurface(), window);
		}
		if(e3 == 1){
			enemy3.move(player, enemy2, enemy1);
			apply_surface(enemy3.getX(),enemy3.getY(),enemy3.getSurface(), window);
		}
		apply_surface(450,344, item1.getSurface(), window);
		if(player.getHealth() == 5)
			apply_surface(0, 0, health1_surface, window);
		else if(player.getHealth() == 4)
			apply_surface(0, 0, health2_surface, window);
		else if(player.getHealth() == 3)
			apply_surface(0, 0, health3_surface, window);
		else if(player.getHealth() == 2)
			apply_surface(0, 0, health4_surface, window);
		else if(player.getHealth() == 1)
			apply_surface(0, 0, health5_surface, window);
		
		player.shoot(player.getX(), player.getY(), player.getPressed());
		apply_surface(player.getxBullet(), player.getyBullet(), bullet_surface, window);

		if (player.getImage() == 0){
			apply_surface(player.getX(),player.getY(),player.getSurfaceLeft(),window);
		} else if (player.getImage() == 1){
			apply_surface(player.getX(),player.getY(),player.getSurface(),window);
		}
		
		if(enemy1.getHealth() == 0){
			e1 = 0;
			enemy1 = enemyBeat;
		}
		if(enemy2.getHealth() == 0){
			e2 = 0;
			enemy2 = enemyBeat;
		}
		if(enemy3.getHealth() == 0){
			e3 = 0;
			enemy3 = enemyBeat;
		}

		

		if(player.getHealth() == 0){
			apply_surface(0,0, dead, window);
			update_screen();
			level = 0;
			sleep(5);
			QUIT = true;
		}


		if (e1==0 && e2==0 && e3==0 && level==1){
			apply_surface(0,0, won, window);
			apply_surface(200, 0, level1, window);
			update_screen();
			sleep(5);
			player.shoot(player.getX(), player.getY(), player.getPressed());
			player.move(enemy1,enemy2,enemy3,item1);  // move player according to input
			player.collision(enemy1, enemy2, enemy3);	
			QUIT = true;		
		}
	
		if (e1==0 && e2==0 && e3==0 && level==2){
			apply_surface(0,0, won, window);
			apply_surface(200, 0, level1, window);
			update_screen();
			sleep(5);
			player.shoot(player.getX(), player.getY(), player.getPressed());
			player.move(enemy1,enemy2,enemy3,item1);  // move player according to input
			player.collision(enemy1, enemy2, enemy3);	
			QUIT = true;		
		}		

		update_screen();

// NOT SURE IF WE NEED this block		//Cap the frame rate
		if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ){
        	SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
		}
	}
}


/*
	Graphics functions
*/


bool Room::init(){           // initilizes SDL
 	// initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    // set up the screen
    window = SDL_SetVideoMode( ROOM_WIDTH, ROOM_HEIGHT, ROOM_BPP, SDL_SWSURFACE );

    // if there was an error in setting up the window
    if( window == NULL )
    {
        return false;
    }

    // set the window caption
    SDL_WM_SetCaption( "GAME", NULL );

    // successful initilization
    return true;
}


SDL_Surface* Room::load_image(string filename){  // loads image to surface
	//The temporary storage for loaded image
	SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}


void Room::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination){
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, NULL, destination, &offset );
}


bool Room::update_screen(){
	if( SDL_Flip( window ) == -1 )
	{
		return false;
	}

	return true;
}

int Room::getLevel(){
	return level;
}


