/*********************************************************************
 ** Program Filename:   battle_arena.cpp
 ** Author:  Nils Streedain
 ** Date:  10/30/21
 ** Description:  Main driver file for the Pokémon Battle Arena program.
 ** Input:  filename
 ** Output:  Command Line/Output File
 *********************************************************************/

#include <iostream>
#include "arena.h"

/*********************************************************************
 ** Function: main()
 ** Description: Ask the user what name they would like to use and then creates and starts an arena with that name
 ** Parameters: int argc, const char * argv[]
 ** Pre-Conditions: A name needs to be typed in as an input
 ** Post-Conditions: The name will be used to create an arena and a game will be started in that arena.
 *********************************************************************/
int main(int argc, const char * argv[]) {
	
	std::cout << "\x1B[2J\x1B[H" << "What would you like your player name to be?" << std::endl;
	std::string name;
	std::cin >> name;
	std::cin.clear();
	std::cout << std::endl;

	Arena arena(name);

	while (!arena.isGameOver())
		arena.startTurn();
}
