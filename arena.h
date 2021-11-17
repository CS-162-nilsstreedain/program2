/*********************************************************************
 ** Program Filename:   arena.h
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  Header file for Arena class
 *********************************************************************/

#ifndef arena_h
#define arena_h

#include <iostream>
#include "trainer.h"

class Arena {
private:
	bool gameOver;
	Trainer* user;
	Trainer* comp;
public:
	Arena(std::string);
	
	void printRoundStats();
	void startTurn();
	void makeMoveOrEndGame(Trainer*, Trainer*);
	void endGame(Trainer&);	
	bool isGameOver();
};

#endif /* arena_h */
