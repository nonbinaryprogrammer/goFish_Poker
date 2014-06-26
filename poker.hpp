/*********************************************************************
** Program Filename: poker.hpp
** Author: Helena Bales
** Date: 04/27/2014
** Description: poker class- child of game class
** Input: none
** Output: none
********************************************************************/

#include"./game.h"

class poker : public game {
	
	public:
	void pscores(int);
	void printmatches(int);
	bool guess(int);
	bool checkguess(int, int, int);
	bool won();
	
	private:
	int starthand = 5;

};
