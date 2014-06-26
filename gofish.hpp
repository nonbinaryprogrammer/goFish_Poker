/*********************************************************************
** Program Filename: gofish.hpp
** Author: Helena Bales
** Date: 04/23/2014
** Description: go fish class- child of game class
** Input: none
** Output: none
********************************************************************/

#include"./game.h"

class gofish : public game {
	
	public:
	void pscores(int);
	void printmatches(int);
	bool guess(int);
	bool checkguess(int, int, int);
	bool won();
	
	private:
	int starthand = 7;

};
