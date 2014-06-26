all: game.o driver.o
	g++ driver.o game.o -o out

driver.o: driver.cpp
	g++ driver.cpp -c

game.o: game.cpp
	g++ game.cpp -c

clean:
	rm -f *.out *.o out
