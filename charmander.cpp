/*********************************************************************
 ** Program Filename:   charmander.cpp
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  C++ file for Charmander class. Creates a Charmander object and provides an effectiveness function to use with it.
 *********************************************************************/

#include "charmander.h"

/*********************************************************************
 ** Function: Charmander()
 ** Description: Default constructor for the Charmander object. Calls Pokémon constructor with correct parameters
 ** Parameters: N/A
 ** Pre-Conditions: N/A
 ** Post-Conditions: A new Charmander object will be created with correct attributes.
 *********************************************************************/
Charmander::Charmander() : Pokemon("Charmander", "Fire", 39, 52, 43, 65) {}

/*********************************************************************
 ** Function: effectiveness()
 ** Description: Function for calculating the effectiveness of this pokemon against another pokemon based on it's type
 ** Parameters: std::string enemyType
 ** Pre-Conditions: enemyType must be provided
 ** Post-Conditions: The effectiveness of this pokemon against another will be breturned
 *********************************************************************/
float Charmander::effectiveness(std::string enemyType) const {
	if (enemyType == "Fire" || enemyType == "Water")
		return .5;
	else if (enemyType == "Grass")
		return 2;
	else
		return 1;
}
