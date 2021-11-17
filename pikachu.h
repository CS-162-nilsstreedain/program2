/*********************************************************************
 ** Program Filename:   pikachu.h
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  Header file for Pikachu class
 *********************************************************************/

#ifndef pikachu_h
#define pikachu_h

#include <iostream>
#include "pokemon.h"

class Pikachu : public Pokemon {
public:
	Pikachu();
	float effectiveness(std::string) const;
};

#endif /* pikachu_h */
