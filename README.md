# Battle Arena

## Learning Outcomes
- Inheritance
- Polymorphism

## Introduction

The goal for this assignment is to create a Pokémon battle game that pits the player against a computer opponent. Each trainer enters the battle with a team of 3 carefully selected Pokémon, and uses them to fight against the computer trainer and their team until one of the teams has no monsters left.

*For the assignment's inspiration, see the first battle between rivals Red and Blue in the original games:*
https://www.youtube.com/watch?v=UNcuZ9PhVtA (Links to an external site.)

## Game Flow
The game begins by asking the trainer their name. Then, the trainer is shown the available Pokémon to choose from and picks 3 of them for their team. The computer's team is selected randomly. Then the battle begins:

- The trainer has 3 choices each turn: fight, heal, or swap.
  - If they choose fight, the first Pokémon on their team attacks the first Pokémon on the computer's team and lowers their health by the calculated damage amount.
  - If they choose heal, they must select which Pokémon to heal. Healing restores up to 15 health points.
  - If they choose swap, they must select which Pokémon on their team to swap with the one in the first position. This means that on the next turn, the new Pokémon will be in the attack position.
- After making their selections, the trainer's turn ends and the computer's turn begins.
- The computer has the same 3 choices each turn: fight, heal, or swap. It should randomly select one of the options.
- After the computer has randomly made their selections, their turn ends.
- The trainer and computer continue to battle until one of their teams has no health left. The trainer still standing wins.

## Program Requirements
Based on the description, there are a number of required classes to build this game. You may create more classes if they would be helpful.

### Classes
`Pokémon` have the following traits: name, type, health points, attack, and defense. They can do damage to other Pokémon, and be healed. This must be an abstract class (it must have at least 1 pure virtual function).

You will also need classes for each type of Pokémon the trainers can choose. The `Bulbasaur`, `Charmander`, and `Squirtle` classes should all be derived from the Pokémon class. Each child class has unique values for the inherited traits shown in the table below.*


Name	| Bulbasaur  |  Charmander  | Squirtle
|-|-|-|-|
Type  | Grass | Fire  | Water
Health Points | 45  | 39  | 44
Attack  | 49  | 52  | 48
Defense | 49  | 43  | 65

*Stats and images pulled from https://pokemondb.net/pokedex/all (Links to an external site.)

The formula for calculating the amount of damage an attack does is below:

Damage = 15 * (Attack of Current Pokémon)/(Defense of Opponent Pokémon) * Type Effectiveness * Random

Different types of Pokémon are stronger or weaker when fighting against certain types. For this assignment, there are 3 types: grass, fire, and water.

- When a grass type attacks a water type the effectiveness is 2, but when it attacks a fire type the effectiveness decreases to 0.5
- When a fire type attacks a grass type the effectiveness is 2, but when it attacks a water type the effectiveness decreases to 0.5
- When a water type attacks a fire type the effectiveness is 2, but when it attacks a grass type the effectiveness decreases to 0.5

The "Random" variable in the damage calculation should be randomized between the range of 0.85 to 1.15.

The `Trainer` class has a `name`, and an array to hold 3 Pokémon in the team (`Pokémon* team[3]`). You will need functions for their 3 battle choices: fight, heal, and swap. When a Trainer chooses to heal a Pokémon, increase their health by 15 (starting/maximum health for each Pokémon is the stat in the table above). You will also need functions for adding Pokemon to the team, among other functions.

The `Arena` class will be used to manage the two Trainers in each battle and the game flow. At a minimum, it should have functions for choosing each Pokémon for a team, checking win conditions, user interface, and taking turns.

Notes
- For this assignment you have additional freedom to design your own implementation. You may add member variables and member functions beyond those described above in order to finish the game.
- All classes should have accessors/mutators, constructors, destructors, etc. as needed.
- Whenever a Pokémon's health goes to 0, the trainer should be prompted to choose another one from their team to put in the first position (the attack position).
- A trainer may choose the same Pokémon more than once for their team.

## Extra Credit
In addition to the requirements above, you may earn extra credit as follows:

- Add another attribute to the Pokémon: speed. Each round, the attacking Pokémon with the highest speed gets to go first. (5 points)

Name  | Bulbasaur | Charmander  | Squirtle
-|-|-|-
Speed | 45  | 65  | 43
 

- Add a new Pokémon class for the trainers to choose from, including correct stats and effectiveness. (5 points)

##Programming Style/Comments
In your implementation, make sure that you include a file header for every .cpp or .h file. Also ensure that you use proper indentation/spacing and include comments! Below is an example header to include. Be sure to review the style guidelines for this class and try to follow them. I.e. don’t align everything on the left or put everything on one line!

```
/******************************************************
** Program: battle_arena.cpp
** Author: Your Name
** Date: xx/xx/2021
** Description:  
** Input:
** Output:
******************************************************/
```

When you compile your code, it is acceptable to use C++11 functionality in your program. In order to support this, change your Makefile to include the proper flag.
For example, consider the following approach (note the inclusion of -std=c++11):

```
g++ -std=c++11 <other flags and parameters>
```

In order to submit your homework assignment, you must create a TAR archive that contains your .h, .cpp, and Makefile files. This tar file will be submitted to Canvas. In order to create the tar file, use the following command:

```
tar –cvf battle.tar /*list of all the .h and .cpp files*/ Makefile
```
