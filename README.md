# Fighting Irish Game
[![Build Status](https://travis-ci.org/willmarkley/Fighting-Irish-Game.svg?branch=master)](https://travis-ci.org/willmarkley/Fighting-Irish-Game)  

## User Manual


__Project Contributors:__  
  Paul Lee  
  Henry Long  
  Will Markley  
  Kevin Shin  


#### 1. Special libraries needed to build/compile

The SDL library is required to build/compile the program. If SDL is already installed, our *Makefile* will correctly link the libaries and compile the game.


#### 2. Instructions on how to build/compile your program

The program is compiled with the given *Makefile*, which is accomplished on Linux machines with the command `make`.  The *Makefile* is located in our *sourcecode* directory.  It will compile the program into an executable named *main* that will also be located in the *sourcecode* directory.


#### 3. User manual with how the controls/interactions work.

###### Movement
The character is controlled with the arrow keys on the keyboard.  Depending on which keys are pressed, the player is moved up, down, sideways, and diagonally.

###### Shooting Functionality
To shoot a bullet, the user would press spacebar.  Bullets are represented as footballs (level 1), basketballs (level 2), and books (level 3).

###### Health
If the player comes in contact with an enemy, the health bar in the top left corner will decrease with each contact. The player starts each level with 5 health. When all of the player's health is depleted, the game will end.  The player can stay alive by avoiding contact with the enemies or picking up items that regenerate health.

###### Objective
The player can beat the game by shooting bullets at the enemies.  Each enemy has a health value that is decremented upon being hit with a bullet.  When an enemy loses all of its health, it is "dead" and disappears from the game.  When all the enemies in a level have been defeated, the player advances to the next level of the game.  After beating the last level, 3rd in our case, the game ends and the player is notified that they have won.

###### Items
A player can collide with the **?** box on the screen to recieve an item.  Items are truly randomized and could be one of the following:  

1. Increase player health by 1

2. Decrease player health by 1

3. Increase player speed and give player a *slide* effect

4. Decrease player speed and give player a *slide* effect

5. Give the player a health of 10 (Normally 5)
		
The *slide* effect is basically just another factor in how the player moves. The player will slowly continue to move in the direction that the user most recently pressed. For example, when the player picks up either one of the speed altering items from the left side of the item block, the player will continue to move right because the last directional key pressed by the user is *right*. The player can also slide diagonally.

#### 4. Known bugs.
Occassionally when the enemies run across the perimeters of the window, they will bump into each other and "push" one outside of the window scope. Sometimes the enemy image will be stuck and flicker and other times it will bounce right back onto the screen.

#### 5. Any other information that will inform the instructor and TAs for final grading.

The game was designed to be run on the University of Notre Dame Red Hat Linux Machines.  The group worked very hard to make this game a success and had a lot of fun learning along the way.


