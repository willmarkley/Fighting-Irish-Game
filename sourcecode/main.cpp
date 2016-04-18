// Main Execution

#include "Room.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main(){
	srand(time(NULL));
	Room r1("images/background.bmp");
	
	r1.play();
	return 0;
}
