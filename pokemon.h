/*********************************************************************
 ** Program Filename:   pokemon.h
 ** Author:  Nils Streedain
 ** Date:  10/29/21
 ** Description:  Header file for Pokémon class
 *********************************************************************/

#ifndef pokemon_h
#define pokemon_h

#include <iostream>

class Pokemon {
private:
	std::string name;
	std::string type;
	
	int maxHealth;
	int currHealth;
	int attack;
	int defense;
	int speed;
	
	virtual float effectiveness(std::string) const=0;
public:
	Pokemon(std::string, std::string, int, int, int, int);
	
	virtual ~Pokemon()=0;
	
	int fight(Pokemon*);
	int damage(int);
	void heal(int);
	
	std::string getName() const;
	std::string getType() const;
	int getHealth() const;
	int getAttack() const;
	int getDefense() const;
	int getSpeed() const;
};

#endif /* pokemon_h */
