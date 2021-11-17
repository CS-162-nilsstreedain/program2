/*********************************************************************
 ** Program Filename:   squirtle.cpp
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  C++ file for Squirtle class. Creates a Squirtle object and provides an effectiveness function to use with it.
 *********************************************************************/

#include "squirtle.h"

/*********************************************************************
 ** Function: Squirtle()
 ** Description: Default constructor for the Squirtle object. Calls Pokémon constructor with correct parameters
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: A new Squirtle object will be created with correct attributes.
 *********************************************************************/
Squirtle::Squirtle() : Pokemon("Squirtle", "Water", 44, 48, 65, 43) {}

/*********************************************************************
 ** Function: effectiveness()
 ** Description: Function for calculating the effectiveness of this pokemon against another pokemon based on it's type
 ** Parameters: std::string enemyType
 ** Pre-Conditions: enemyType must be provided
 ** Post-Conditions: The effectiveness of this pokemon against another will be breturned
 *********************************************************************/
float Squirtle::effectiveness(std::string enemyType) const {
	if (enemyType == "Grass" || enemyType == "Water")
		return .5;
	else if (enemyType == "Fire")
		return 2;
	else
		return 1;
}
