/*********************************************************************
 ** Program Filename:   pikachu.cpp
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  C++ file for Pikachu class. Creates a Pikachu object and provides an effectiveness function to use with it.
 *********************************************************************/

#include "pikachu.h"

/*********************************************************************
 ** Function: Pikachu()
 ** Description: Default constructor for the Pikachu object. Calls Pokémon constructor with correct parameters
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: A new Pikachu object will be created with correct attributes.
 *********************************************************************/
Pikachu::Pikachu() : Pokemon("Pikachu", "Electric", 35, 55, 40, 90) {}

/*********************************************************************
 ** Function: effectiveness()
 ** Description: Function for calculating the effectiveness of this pokemon against another pokemon based on it's type
 ** Parameters: std::string enemyType
 ** Pre-Conditions: enemyType must be provided
 ** Post-Conditions: The effectiveness of this pokemon against another will be breturned
 *********************************************************************/
float Pikachu::effectiveness(std::string enemyType) const {
	if (enemyType == "Electric" || enemyType == "Grass")
		return .5;
	else if (enemyType == "Water")
		return 2;
	else
		return 1;
}
