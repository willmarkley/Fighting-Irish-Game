# User Manual


__Project Contributors:__  
  Paul Lee  
  Henry Long  
  Will Markley  
  Kevin Shin  


####1. Special libraries needed to build/compile if personal machines were used

The SDL library is required to build/compile the program. If SDL is already installed, our *Makefile* will correctly link the libaries and compile the game.


####2. Instructions on how to build/compile your program

The program is compiled with the given *Makefile*, which is accomplished on Linux machines with the command `make`.  The *Makefile* is located in our *sourcecode* directory.  It will compile the program into an executable named *main* that will also be located in the *sourcecode* directory.


####3. User manual with how the controls/interactions work.

######Movement
The character is controlled with the arrow keys on the keyboard.  Depending on which keys are pressed, the player is moved up, down, sideways, and diagonally.

######Shooting Functionality
To shoot a bullet, the user would press spacebar.  Bullets are represented as footballs (level 1), basketballs (level 2), and books (level 3).

######Health
If the player comes in contact with an enemy, its health bar in the top left corner will go down.  When all of the player's health is depleted, the game will end.  The player can stay alive by avoiding contact with the enemies.

######Objective
The player can beat the game by shooting bullets at the enemies.  Each enemy has a health value that is decremented upon being hit with a bullet.  When an empty loses all of it's health, it disappears from the game.  When all the enemies in a level have been defeated, the player advances to the next level of the game.  After beating the last level, 3rd in our case, the game ends and the player is notified that they have won.

######Items
A player can collide with the **?** box on the screen to recieve an item.  Items are randomized and could be one of the following:  
1. Increase player health  
2. Decrease player health  
3. Increase player speed  
4. Decrease player speed  
5. Give the player a health of 10 (Normally 5)  
		

####4. Known bugs.

The known bugs include having a bullet appear at the beginning of the second level.  The player loses shoot functionailty until an enemy collides with this bullet; immediately after, all returns to normal.  This bug occurs in ~50% of games runs.

####5. Any other information that will inform the instructor and TAs for final grading.

The game was designed to be run on the University of Notre Dame Red Hat Linux Machines.


