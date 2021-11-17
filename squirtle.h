/*********************************************************************
 ** Program Filename:   squirtle.h
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  Header file for Squirtle class
 *********************************************************************/

#ifndef squirtle_h
#define squirtle_h

#include <iostream>
#include "pokemon.h"

class Squirtle : public Pokemon {
public:
	Squirtle();
	float effectiveness(std::string) const;
};

#endif /* squirtle_h */
