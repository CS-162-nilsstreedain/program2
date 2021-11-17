/*********************************************************************
 ** Program Filename:   bulbasaur.cpp
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  C++ file for Bulbasaur class. Creates a Bulbasaur object and provides an effectiveness function to use with it.
 *********************************************************************/

#include "bulbasaur.h"

/*********************************************************************
 ** Function: Bulbasaur()
 ** Description: Default constructor for the Bulbasaur object. Calls Pokémon constructor with correct parameters
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: A new Bulbasaur object will be created with correct attributes.
 *********************************************************************/
Bulbasaur::Bulbasaur() : Pokemon("Bulbasaur", "Grass", 45, 49, 49, 45) {}

/*********************************************************************
 ** Function: effectiveness()
 ** Description: Function for calculating the effectiveness of this pokemon against another pokemon based on it's type
 ** Parameters: std::string enemyType
 ** Pre-Conditions: enemyType must be provided
 ** Post-Conditions: The effectiveness of this pokemon against another will be breturned
 *********************************************************************/
float Bulbasaur::effectiveness(std::string enemyType) const {
	if (enemyType == "Fire" || enemyType == "Grass")
		return .5;
	else if (enemyType == "Water")
		return 2;
	else
		return 1;
}
