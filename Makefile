# Lab 4 Makefile
CC = g++ -std=c++11
exe_file = application
$(exe_file): pikachu.o squirtle.o charmander.o bulbasaur.o pokemon.o trainer.o arena.o battle_arena.o
	$(CC) pikachu.o squirtle.o charmander.o bulbasaur.o pokemon.o trainer.o arena.o battle_arena.o -o $(exe_file)
pikachu.o: pikachu.cpp
	$(CC) -c pikachu.cpp
squirtle.o: squirtle.cpp
	$(CC) -c squirtle.cpp
charmander.o: charmander.cpp
	$(CC) -c charmander.cpp
bulbasaur.o: bulbasaur.cpp
	$(CC) -c bulbasaur.cpp
pokemon.o: pokemon.cpp
	$(CC) -c pokemon.cpp
trainer.o: trainer.cpp
	$(CC) -c trainer.cpp
arena.o: arena.cpp
	$(CC) -c arena.cpp
battle_arena.o: battle_arena.cpp
	$(CC) -c battle_arena.cpp

clean:
	rm -f *.out *.o $(exe_file)
