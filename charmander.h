/*********************************************************************
 ** Program Filename:   charmander.h
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  Header file for Charmander class
 *********************************************************************/

#ifndef charmander_h
#define charmander_h

#include <iostream>
#include "pokemon.h"

class Charmander : public Pokemon {
public:
	Charmander();
	float effectiveness(std::string) const;
};

#endif /* charmander_h */
