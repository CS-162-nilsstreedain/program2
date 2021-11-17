/*********************************************************************
 ** Program Filename:   arena.cpp
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  C++ file for Arena class. Creates an Arena object and provides various functions to use with said class.
 *********************************************************************/

#include "arena.h"

/*********************************************************************
 ** Function: Arena()
 ** Description: Paramaterized constructor for making an Arena object that holds 2 players and controlls game flow.
 ** Parameters: std::string name
 ** Pre-Conditions: The name of the user Trainer must be provided.
 ** Post-Conditions: An Arena object containing 2 Trainers will be created. One of the Trainers will be created with the input name.
 *********************************************************************/
Arena::Arena(std::string name) {
	gameOver = false;
	user = new Trainer(name);
	comp = new Trainer();
}

/*********************************************************************
 ** Function: printRoundStats()
 ** Description: Function for printing User and Computer Pokemon info to the console
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Pokemon info for the User and computer will be printed to the console
 *********************************************************************/
void Arena::printRoundStats() {
	Pokemon* userActive = user->getActivePokemon();
	Pokemon* compActive = comp->getActivePokemon();
	
	std::cout << "\nYour Pokemon: " << userActive->getName() << ", "
										<< userActive->getType() << ", "
										<< userActive->getHealth() << " health points" << std::endl;
	std::cout << "Enemy Pokemon: " << compActive->getName() << ", "
										<< compActive->getType() << ", "
										<< compActive->getHealth() << " health points" << std::endl;
}

/*********************************************************************
 ** Function: startTurn()
 ** Description: Function for starting a turn for each player (player with fastest Pokemon goes first)
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Each player will make a move, player with fastest pokemon will go first.
 *********************************************************************/
void Arena::startTurn() {
	if (user->getActivePokemon()->getSpeed() >= comp->getActivePokemon()->getSpeed()) {
		printRoundStats();
		makeMoveOrEndGame(user, comp);
		if (!gameOver)
			makeMoveOrEndGame(comp, user);
	} else {
		makeMoveOrEndGame(comp, user);
		if (!gameOver) {
			printRoundStats();
			makeMoveOrEndGame(user, comp);
		}
	}
}

/*********************************************************************
 ** Function: makeMoveOrEndGame()
 ** Description: If the player about to goes is dead, the game will end. Otherwise they will make their move
 ** Parameters: Trainer *playerOne, Trainer *playerTwo
 ** Pre-Conditions: N/A
 ** Post-Conditions: Player one will make a move if they are alive, otherwise the game will end and they will lose.
 *********************************************************************/
void Arena::makeMoveOrEndGame(Trainer *playerOne, Trainer *playerTwo) {
	if (!playerOne->isAlive())
		endGame(*playerTwo);
	else
		playerOne->makeMove(playerTwo);
}

/*********************************************************************
 ** Function: endGame()
 ** Description: Function Ending the game loop and printing the winning player to the console
 ** Parameters: Trainer *winner
 ** Pre-Conditions: Winning trainer pointer must be provided
 ** Post-Conditions: Name of winning trainer will be printed and game loop will end.
 *********************************************************************/
void Arena::endGame(Trainer &winner) {
	std::cout << "\x1B[2J\x1B[H" << "The winner is: " << winner.getName() << std::endl;
	gameOver = true;
}

/*********************************************************************
 ** Function: isGameOver()
 ** Description: Returns true if the game is over, false otherwise
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: True will be returned if the game is over, false will be returned otherwise
 *********************************************************************/
bool Arena::isGameOver() {
	return gameOver;
}
