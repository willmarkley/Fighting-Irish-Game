// Room Class Implementation File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "Room.h"
#include "Character.h"
#include "Timer.h"
#include "Item.h"

using namespace std;

const int ROOM_WIDTH = 960;     // room width
const int ROOM_HEIGHT = 768;    // room height
const int ROOM_BPP = 32;        // room bits per pixel
const int FRAMES_PER_SECOND = 60;  // frame rate

Room::Room(string filename){    // constructor
	init();
	background = load_image(filename);
	apply_surface(0,0,background,window);
	update_screen();
	character_left=load_image("images/leprechaun_left.bmp");
	character_right=load_image("images/leprechaun_right.bmp");
	enemy1_surface=load_image("images/michigan.bmp");
	enemy2_surface=load_image("images/Boston_College.bmp");
	bullet_surface=load_image("images/football.bmp");
	item_surface=load_image("images/question-mark.bmp");
}

Room::~Room(){    // deconstructor
	SDL_FreeSurface(character_left);
	SDL_FreeSurface(character_right);
	SDL_FreeSurface(enemy1_surface);
	SDL_FreeSurface(enemy2_surface);
	SDL_FreeSurface(item_surface);
	SDL_FreeSurface(bullet_surface);
	SDL_FreeSurface(background);
	SDL_FreeSurface(window);
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
		apply_surface(200,0,enemy1_surface, window);
		apply_surface(200,300,enemy2_surface, window);
		apply_surface(450,344, item_surface, window);
		player.move();  // move player according to input
		player.shoot(player.getX(), player.getY(), player.getBullet(), player.getPressed());
		apply_surface(player.getxBullet(), player.getyBullet(), bullet_surface, window);
		if (player.getImage() == 0){
			apply_surface(player.getX(),player.getY(),character_left,window);
		} else if (player.getImage() == 1){
			apply_surface(player.getX(),player.getY(),character_right,window);
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

/*void Room::shoot(int x, int y, int bullet, int lastPressed){
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
	if (xBullet > ROOM_WIDTH || xBullet < 0 || yBullet > ROOM_HEIGHT || yBullet < 0){
		bullet = 0;
	}
}*/
