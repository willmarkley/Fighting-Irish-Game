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
	}	
	if(r2.getLevel() == 2){
		r3.play();
	}
	return 0;
}
