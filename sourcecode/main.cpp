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
	Room r3("images/jesus.bmp", 3);
	r1.play();
	if(r1.getLevel() == 1){
		r2.play();
		r1.deconstructor();
	} else if (r1.getLevel() == 0){
		r1.deconstructor();
		return 0;
	}	
	if(r2.getLevel() == 2){
		r3.play();
		r2.deconstructor();
	} else if (r2.getLevel() == 0){
		r2.deconstructor();
		return 0;
	}
	if(r3.getLevel() == 3){
		r3.deconstructor();
		return 0;
	} else if (r2.getLevel() == 0){
		r3.deconstructor();
		return 0;
	}	
	r3.deconstructor();
	return 0;
}
