/*********************************************************************
 ** Program Filename:   pokemon.cpp
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  C++ file for Pokémon class. Creates a Pokémon object and provides various functions to use with said class.
 *********************************************************************/

#include "pokemon.h"

/*********************************************************************
 ** Function: pokedex()
 ** Description: Paramaterized constructor for making a pokemon object with specific attributes.
 ** Parameters: std::string name, std::string type, int maxHealth, int attack, int defense, int speed
 ** Pre-Conditions: pokemon attributes must be provided as arguments
 ** Post-Conditions: A pokemon object with specific attributes will be created.
 *********************************************************************/
Pokemon::Pokemon(std::string name, std::string type, int maxHealth, int attack, int defense, int speed) {
	this->name = name;
	this->type = type;
	this->maxHealth = maxHealth;
	this->currHealth = maxHealth;
	this->attack = attack;
	this->defense = defense;
	this->speed = speed;
}

/*********************************************************************
 ** Function: ~pokedex()
 ** Description: Default deconstructor of Pokémon class
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: A pokemon object will be deconstructed
 *********************************************************************/
Pokemon::~Pokemon() {}

/*********************************************************************
 ** Function: fight()
 ** Description: Function allowing a Pokémon to fight another Pokémon. damageToDeal will be calculated and then dealt
 ** Parameters: Pokemon* enemy
 ** Pre-Conditions: enemy Pokemon pointer must be provided
 ** Post-Conditions: Pokemon will fight another Pokemon provided as an argument and will deal the correct amount of damage to it
 *********************************************************************/
int Pokemon::fight(Pokemon* enemy) {
	// Calulate the amount of damage to deal
	float randomNum = ((float) std::rand() / (float) RAND_MAX) * (1.15 - .85) + 1.15;
	int damageToDeal =	15 * attack / (enemy->getDefense()) * effectiveness(enemy->getType()) * randomNum;
	
	// Deal and then return the amount of damage
	return enemy->damage(damageToDeal);
}

/*********************************************************************
 ** Function: damage()
 ** Description: Function for dealing damage to a Pokémon object
 ** Parameters: int damageToDeal
 ** Pre-Conditions: amount of damage to deal must be specified
 ** Post-Conditions: A pokemon object will have damageToDeal amount of damage dealt to it.
 *********************************************************************/
int Pokemon::damage(int damageToDeal) {
	currHealth -= damageToDeal;
	if (currHealth < 0)
		currHealth = 0;
	
	return damageToDeal;
}

/*********************************************************************
 ** Function: heal()
 ** Description: Function for healing health of a Pokémon object
 ** Parameters: int healthToHeal
 ** Pre-Conditions: amount of health to heal must be specified
 ** Post-Conditions: A pokemon object will have healthToHeal amount of health points added to it.
 *********************************************************************/
void Pokemon::heal(int healthToHeal) {
	currHealth += healthToHeal;
	if (currHealth > maxHealth)
		currHealth = maxHealth;
}

/*********************************************************************
 ** Function: getName()
 ** Description: Function for getting the name of a pokemon
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Name of the pokemon will be returned.
 *********************************************************************/
std::string Pokemon::getName() const {
	return name;
}

/*********************************************************************
 ** Function: getType()
 ** Description: Function for getting the type of a pokemon
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Type of the pokemon will be returned.
 *********************************************************************/
std::string Pokemon::getType() const {
	return type;
}

/*********************************************************************
 ** Function: getHealth()
 ** Description: Function for getting the health of a pokemon
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Health of the pokemon will be returned.
 *********************************************************************/
int Pokemon::getHealth() const {
	return currHealth;
}

/*********************************************************************
 ** Function: getAttack()
 ** Description: Function for getting the atack of a pokemon
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Attack of the pokemon will be returned.
 *********************************************************************/
int Pokemon::getAttack() const {
	return attack;
}

/*********************************************************************
 ** Function: getDefense()
 ** Description: Function for getting the defense of a pokemon
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Defense of the pokemon will be returned.
 *********************************************************************/
int Pokemon::getDefense() const {
	return defense;
}

/*********************************************************************
 ** Function: getSpeed()
 ** Description: Function for getting the speed of a pokemon
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: Speed of the pokemon will be returned.
 *********************************************************************/
int Pokemon::getSpeed() const {
	return speed;
}
