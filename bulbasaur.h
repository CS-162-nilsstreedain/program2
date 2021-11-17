/*********************************************************************
 ** Program Filename:   bulbasaur.h
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  Header file for Bulbasaur class
 *********************************************************************/

#ifndef bulbasaur_h
#define bulbasaur_h

#include <iostream>
#include "pokemon.h"

class Bulbasaur : public Pokemon {
public:
	Bulbasaur();
	float effectiveness(std::string) const;
};

#endif /* bulbasaur_h */
