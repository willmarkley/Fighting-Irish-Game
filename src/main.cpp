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
	int level = 0;

	// Level 1
	Room r1("images/NDField.bmp", 1);
	r1.play();
	level = r1.getLevel();

	// Level 2
	if(level){
		Room r2("images/basketball.bmp", 2);
		r2.play();
		level = r2.getLevel();
	}
	else{
		return 0;
	}

	// Level 3
	if(level){
		Room r3("images/jesus.bmp", 3);
		r3.play();
		level = r3.getLevel();
	} else{
		return 0;
	}

	return 0;
}
