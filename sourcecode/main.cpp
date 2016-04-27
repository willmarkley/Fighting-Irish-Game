// Main Execution

#include "Room.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h> 
#include <cstdlib>

using namespace std;


int main(){
	srand(time(NULL));
	Room r1("images/NDField.bmp", 1);
	Room r2("images/basketball.bmp", 2);
	r1.play();
	r2.play();
		
	return 0;
}
