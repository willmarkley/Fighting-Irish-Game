// Room Base Class Header File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
using namespace std;

class Room{

	public:
		Room();     // constructor
		~Room();    // deconstructor
		clear();    // clear screen

	private:
		Room* left;   // points to room at the left
		Room* right;  // points to room at the right
		Room* up;     // points to room above
		const int ROOM_WIDTH = 640;   // room width
		const int ROOM_HEIGHT = 480;  // room height
		const int ROOM_BPP = 32;      // room bits per pixel
		SDL_Surface *background = NULL;   // background image
		Character player;   // main player
}
