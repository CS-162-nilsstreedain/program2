/*********************************************************************
 ** Program Filename:   trainer.h
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  Header file for Trainer class
 *********************************************************************/

#ifndef trainer_h
#define trainer_h

#include <iostream>
#include <limits>
#include "pokemon.h"
#include "bulbasaur.h"
#include "charmander.h"
#include "squirtle.h"
#include "pikachu.h"

class Trainer {
private:
	bool isPlayer;
	std::string name;
	Pokemon* team[3];
	int numAlivePokemon;
public:
	Trainer();
	Trainer(std::string);
	
	~Trainer();
	
	void choosePokemon();
	int askForIntBetween(int, int) const;
	
	std::string getName();
	Pokemon* getActivePokemon();
	int getNumAlive();
	bool isAlive();
	
	void makeMove(Trainer*);
	void fight(Trainer*);
	void heal();
	bool swap();
};

#endif /* trainer_h */
