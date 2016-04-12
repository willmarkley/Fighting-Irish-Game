// Room Base Class Header File

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
using namespace std;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;


class Room{

	public:
		Room(string="");     // constructor
		~Room();    // deconstructor

	private:
		Room* left = NULL;   // points to room at the left
		Room* right = NULL;  // points to room at the right
		Room* up = NULL;     // points to room above
		SDL_Surface *background = NULL;   // background image
		SDL_Surface *window = NULL;       // window
		//Character player;    // main player

		bool init();           // initilizes SDL
		SDL_Surface *load_image(string filename);  // loads image to surface
		void apply_surface( int, int, SDL_Surface*, SDL_Surface*);  // applies image to surface
		bool update_screen();   // updates screen
};


