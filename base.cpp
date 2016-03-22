#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h> // allows for the use of standard IO
#include <string> // included after the 4th tutorial
using namespace std;

	const int SCREEN_WIDTH = 500;
	const int SCREEN_HEIGHT = 500;
		
	enum KeyPressSurfaces{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP, 
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL,
	};
	// Starts up SDL and creates a new window
	bool init();
	// Loads Media for tutorial, no media for our project yet
	bool loadMedia();
	// Frees media and shuts down SDL
	void close();						
	// Loads the individual image
	SDL_Surface* loadSurface( string path );
	// The window we are rendering to
	SDL_Window* gWindow = NULL;
	// The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;
	// The image we will load and show on the screen
	SDL_Surface* gMario = NULL;
	//The images that correspond to a key press
	SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
	// Current Displayed Image
	SDL_Surface* gCurrentSurface = NULL; 
	// Function for initializing the surface
	bool init(){
		bool success = true;
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		} else{
			// Create window
			gWindow = SDL_CreateWindow( "SDL_Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if( gWindow == NULL){
				cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			} else{
				// Get window surface
				gScreenSurface = SDL_GetWindowSurface( gWindow );
			}
		}
		return success;
	} // End of Function
	// Loading the media
	bool loadMedia(){
	// Loading Success Flag
	bool success = true;
	// Load splash Image
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "./defaultsprite.bmp" );
	if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL){
		cout << "Unable to load default image! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "./upsprite.bmp" );
	if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL){
		cout << "Unable to load up image! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}	
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "./downsprite.bmp" );
	if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL){
		cout << "Unable to load down image! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "./leftsprite.bmp" );
	if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL){
		cout << "Unable to load left image! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "./rightsprite.bmp" );
	if (gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL){
		cout << "Unable to load right image! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	return success;
	} // End of Function
	void close(){
		// Deallocate surfaces
		for(int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i){
			SDL_FreeSurface( gKeyPressSurfaces[ i ] );
			gKeyPressSurfaces[ i ] = NULL; 
		}
		// Destroy the window
		SDL_DestroyWindow (gWindow);
		gWindow = NULL;
		SDL_Quit();
	}
	// Loading the surface
	SDL_Surface* loadSurface( string path){
		SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str() );
		if(loadedSurface == NULL){
			cout << "Unable to load image: " << path.c_str() << ". SDL Error: " << SDL_GetError() << endl;		
		}
		return loadedSurface; 
	}
	int main(int argc, char* args[]){
		if(!init()){
			cout << "Failed to initialize!" << endl;
		} else{ //load media	
		if(!loadMedia()){
			cout << "Unable to load media" << endl; 
		} else{
			// main loop flag
			bool quit = false;
			// Event handler
			SDL_Event e;
			// while application is running and user has not pressed the x button
			while ( !quit ){
				while (SDL_PollEvent( &e ) != 0 ){
					if(e.type == SDL_QUIT){
						quit = true;
					} else if(e.type == SDL_KEYDOWN){ // user presses a key
					// select surfaces based on new key presses
					switch(e.key.keysym.sym){
						case SDLK_UP:
						gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
						break;
						case SDLK_DOWN:
						gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
						break;
						case SDLK_LEFT:
						gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
						break;
						case SDLK_RIGHT:
						gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
						break;
						default:
						gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
						break;
					}
				}
			}
			// Apply Image and update the surface
			SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL);
			SDL_UpdateWindowSurface(gWindow);
		}
	}
}
// free resources and close SDL
close();
return 0; 
}
