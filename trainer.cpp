/*********************************************************************
 ** Program Filename:   trainer.cpp
 ** Author:  Nils Streedain
 ** Date:  10/9/21
 ** Description:  C++ file for Trainer class. Creates a Trainer object and provides various functions to use with said class.
 *********************************************************************/

#include "trainer.h"

/*********************************************************************
 ** Function: Trainer()
 ** Description: Default constructor for the Trainer object. Creates a computer player.
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: A computer controlled Trainer object will be created.
 *********************************************************************/
Trainer::Trainer() {
	isPlayer = false;
	name = "Computer";
	choosePokemon();
	numAlivePokemon = 3;
}

/*********************************************************************
 ** Function: Trainer()
 ** Description: Paramaterized constructor for the Trainer object. Creates a user player.
 ** Parameters: std::string name
 ** Pre-Conditions: name must be provided
 ** Post-Conditions: A user controlled Trainer object will be created.
 *********************************************************************/
Trainer::Trainer(std::string name) {
	isPlayer = true;
	this->name = name;
	choosePokemon();
	numAlivePokemon = 3;
}

/*********************************************************************
 ** Function: ~Trainer()
 ** Description: Default deconstructor for the Trainer object. Deletes each Pokemon pointer assigned to the Trainer
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: A Trainer object will be deleted
 *********************************************************************/
Trainer::~Trainer() {
	for (int i = 0; i < 3; i++)
		delete team[i];
}

/*********************************************************************
 ** Function: choosePokemon()
 ** Description: Function to allow either a user or computer controlled player to choose what Pokémon to add to their party.
 ** Parameters: N/A
 ** Pre-Conditions: If a user based Trainer, the user must select the Pokémon to add.
 ** Post-Conditions: 3 Pokémon the user or computer chooses will be added to their party.
 *********************************************************************/
void Trainer::choosePokemon() {
	// Loops over the 3 available party slots for a Trainer
	for (int i = 0; i < 3; i++) {
		// If Trainer is a user, options will be printed to the console
		if (isPlayer)
			std::cout 	<< "Choose Pokémon " << i + 1 << " to add to your party:\n"
						<< "(1) Bulbasaur, (2) Charmander, (3) Squirtle, (4) Pikachu"
						<< std::endl;
		// A Pokemon will be added to the correct slot in the party based on the user input
		switch (askForIntBetween(1, 4)) {
			case 1:
				team[i] = new Bulbasaur;
				break;
			case 2:
				team[i] = new Charmander;
				break;
			case 3:
				team[i] = new Squirtle;
				break;
			case 4:
				team[i] = new Pikachu;
				break;
			default:
				break;
		}
	}
}

/*********************************************************************
 ** Function: askForIntBetween()
 ** Description: Function to get an int between two ints from the user of computer. Either the user will be asked to provide one or a random will be generated.
 ** Parameters: int min, int max
 ** Pre-Conditions: min and max ints must be provided. If the user is asked, they must provide an int.
 ** Post-Conditions: An int chossen by either the computer or user will be returned.
 *********************************************************************/
int Trainer::askForIntBetween(int min, int max) const {
	if (isPlayer) {
		// If Trainer is a user, the user must input an int between min and max
		int num;
		
		// If an incorrect int is provided, the user will be repeatedly asked to input an int
		while (!(std::cin >> num) || num < min || num > max) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nInvalid input, please type an integer between " << min << " and " << max << "." << std::endl;
		}
		std::cout << std::endl;
		
		return num;
	} else {
		// If Trainer is a computer, a random int between min and max will be returned
		return min + (std::rand() % (max - min + 1));
	}
}

/*********************************************************************
 ** Function: getName()
 ** Description: Function for getting the name of a Trainer
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Name of the Trainer will be returned.
 *********************************************************************/
std::string Trainer::getName() {
	return name;
}

/*********************************************************************
 ** Function: getActivePokemon()
 ** Description: Function for getting the active pokemon of a Trainer
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Active pokemon of the Trainer will be returned.
 *********************************************************************/
Pokemon* Trainer::getActivePokemon() {
	return team[0];
}

/*********************************************************************
 ** Function: getNumAlive()
 ** Description: Function for getting the number of alive pokemon a Trainer has
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Number of alive pokemon will be returned.
 *********************************************************************/
int Trainer::getNumAlive() {
	return numAlivePokemon;
}

/*********************************************************************
 ** Function: isAlive()
 ** Description: Function for seeing id a trainer has any alive Pokemon
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: True will be returned if the Trainer has at least one Pokemon with health. False otherwise
 *********************************************************************/
bool Trainer::isAlive() {
	return (numAlivePokemon > 1) || (team[0]->getHealth() > 0);
}

/*********************************************************************
 ** Function: makeMove()
 ** Description: Function for having a Trainer make a mvoe.
 ** Parameters: Trainer *opponent
 ** Pre-Conditions: An opponent pointer must be provided. The user must also select moves to make.
 ** Post-Conditions: The Trainer will make a move (Fight, Heal, or Swap)
 *********************************************************************/
void Trainer::makeMove(Trainer *opponent) {
	// Has player swap Pokémon at beginning of turn if dead
	if (team[0]->getHealth() <= 0) {
		std::cout << "\n" << name << "'s Pokémon " << team[0]->getName() << " fainted." << std::endl;
		swap();
		numAlivePokemon--;
	}
	
	// Asks user what move they'd like to make
	if (isPlayer)
		std::cout << "\nWhat move would you like to make?\n(1) Fight, (2) Heal, (3) Swap" << std::endl;
	// Makes move based on user input
	switch (askForIntBetween(1, 3)) {
		case 1:
			fight(opponent);
			break;
		case 2:
			heal();
			break;
		case 3:
			if (!swap())
				makeMove(opponent);
			break;
		default:
			makeMove(opponent);
			break;
	}
}

/*********************************************************************
 ** Function: fight()
 ** Description: Function for getting a Trainer's Pokemon to fight another Trainer's Pokemon
 ** Parameters: Trainer *opponent
 ** Pre-Conditions: Opponent Trainer pointer must be provided
 ** Post-Conditions: Pokemon will fight and the move will be printed
 *********************************************************************/
void Trainer::fight(Trainer *opponent) {
	int damageDealt = team[0]->fight(opponent->getActivePokemon());
	std::cout << name << " fought " << opponent->getName() << " and dealt " << damageDealt << " damage." << std::endl;
}

/*********************************************************************
 ** Function: heal()
 ** Description: Function for getting a Trainer to heal it's Pokemon
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Pokemon will be healed and the move will be printed.
 *********************************************************************/
void Trainer::heal() {
	if (isPlayer) {
		std::cout << "Which Pokémon would you like to heal?" << std::endl;
		for (int i = 0; i < numAlivePokemon; i++)
			std::cout << "(" << i + 1 << ") " << team[i]->getName() << std::endl;
	}
	
	Pokemon* pokemonToHeal = team[askForIntBetween(1, numAlivePokemon) - 1];
	pokemonToHeal->heal(15);
	std::cout << name << " healed " << pokemonToHeal->getName() << " by 15 health points." << std::endl;
}

/*********************************************************************
 ** Function: swap()
 ** Description: Function for getting a Trainer to swap it's active Pokemon with another Pokemon in it's party
 ** Parameters: N/A
 ** Pre-Conditions: Trainer must provide which Pokemon it would like to swap with.
 ** Post-Conditions: Active Pokemon will be swapped with another in it's party.
 *********************************************************************/
bool Trainer::swap() {
	// Returns false if the trainer does not have enough Pokemon to swap
	if (numAlivePokemon < 1) {
		if (isPlayer)
			std::cout << "Not enough alive Pokémon, select another option." << std::endl;
		return false;
	}
	
	// Prints to console which Pokemon are available to swap
	if (isPlayer) {
		std::cout << "Which Pokémon would you like to swap in?" << std::endl;
		for (int i = 1; i < numAlivePokemon; i++)
			std::cout << "(" << i << ") " << team[i] -> getName() << std::endl;
	}
	// Asks user or computer which pokemon to swap with
	int pokemonToSwap = askForIntBetween(1, numAlivePokemon - 1);
	
	std::cout << name << " swapped " << team[0]->getName() << " with " << team[pokemonToSwap]->getName() << std::endl;
	
	// Swaps indexes of active pokemon and pokemon to swap.
	Pokemon* temp = team[0];
	team[0] = team[pokemonToSwap];
	team[pokemonToSwap] = temp;
	
	return true;
}
